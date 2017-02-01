#include <stdio.h>
#include <stdlib.h>

struct node{
  int coeff;
  struct node *next;
};

void create(struct node *head,int co)
{
  struct node *p=head,*c=NULL,*temp;
  temp=(struct node*)malloc(sizeof(int));
  temp->coeff=co;
  temp->next=NULL;
  while(p!=NULL)
    {
      c=p;
      p=p->next;
    }
  if(c==NULL)
    {
      c=temp;
    }
  else
    {
      c->next=temp;
    }
}

double value(struct node *head,int n,double x)
{
  double v,t;int i;
  struct node *p=head;int v;
  for(i=0;i<n;i++)
    {
      t*=x;
    }  
   while(p!=NULL){
      v+=p->coeff*t;
      t/=x;
      p=p->next;
    }
   return v;
}

void deep(struct node *head,int n,double x,double y){
  if(((int)(x*1000000)-(int)(x*100000))!=0 || ((int)(y-1000000)-(int)(y-100000))!=0){
    printf("%d\n",x);
  }
  else{
  if((value(head,n,x)<0 && value(head,n,(x+y)/2)>0)||(value(head,n,x)>0 && value(head,n,(x+y)/2)<0)){
    deep(head,n,x,(x+y)/2);
  }
  else if((value(head,n,(x+y)/2)<0 && value(head,n,y)>0)||(value(head,n,(x+y)/2) && value(head,n,y))){
    deep(head,n,(x+y)/2,y);
  }
  else{
    printf("Sorry");
  }
  }
}

void compute(struct node *head,int n){

  double x=-100;  
  while(x<=100){   
    if((value(x)<0 && value(x+1)>0) || (value(x)>0 && value(x+1)<0)){
      deep(head,n,x,x+1);  
      x+=1; 
  }
 
}
  
  
void main()
{
  int n,i,x;
  struct node *head=NULL;
  printf("Enter the highest degree of Polynomials\n");
  scanf("%d",&n);
  printf("Enter the coefficients of polynomials from higher degree to lower degree\n");
  for(i=0;i<=n;i++)
    {
      scanf("%d",&x);
      create(head,x);
    }
  //printf("Done\n");
  compute(head,n);
}
