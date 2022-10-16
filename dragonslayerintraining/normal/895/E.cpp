#include <cstdio>
#include <cassert>

struct Linear{
  double m,b;
  Linear():m(1),b(0){
  }
  Linear(double m,double b):m(m),b(b){
  }
  struct Linear operator*(struct Linear post)const{
    return Linear(m*post.m,b*post.m+post.b);
  }
  double operator()(double in)const{
    return in*m+b;
  }
};

struct Node{
  double sum;
  struct Linear lazy;
};

int as[100000];
struct Node st[400000];
int N;

void build(int w,int L,int R){
  if(R-L==1){
    st[w].sum=as[L];
    return;
  }
  int M=(L+R)/2;
  build(w*2+1,L,M);
  build(w*2+2,M,R);
  st[w].sum=st[w*2+1].sum+st[w*2+2].sum;
}

void push(int w,int L,int R){
  if(R-L>1){
    st[w*2+1].lazy=st[w*2+1].lazy*st[w].lazy;
    st[w*2+2].lazy=st[w*2+2].lazy*st[w].lazy;
  }
  /*
  if((st[w].lazy.m!=1)|(st[w].lazy.b!=0)){
    printf("CHANGE sum[%d,%d) from %lf to %lf\n",L,R,st[w].sum,st[w].lazy(st[w].sum));
  }
  */
  st[w].sum=st[w].lazy.m*st[w].sum+st[w].lazy.b*(R-L);
  st[w].lazy=Linear();
}

void update(int w,int L,int R,int a,int b,struct Linear op){
  push(w,L,R);
  if((b<=L)||(a>=R)){
    return;
  }
  if((a<=L)&&(b>=R)){
    //printf("UPDATE_LOW: [%d,%d): *%lf+%lf\n",L,R,op.m,op.b);
    //printf("IDENTITY: *%lf+%lf\n",st[w].lazy.m,st[w].lazy.b);
    st[w].lazy=op;
    push(w,L,R);
    return;
  }
  int M=(L+R)/2;
  update(w*2+1,L,M,a,b,op);
  update(w*2+2,M,R,a,b,op);
  assert(st[w*2+1].lazy.m==1);
  assert(st[w*2+1].lazy.b==0);
  assert(st[w*2+2].lazy.m==1);
  assert(st[w*2+2].lazy.b==0);
  st[w].sum=st[w*2+1].sum+st[w*2+2].sum;
  //printf("SUM[%d,%d)=%lf\n",L,R,st[w].sum);
}

void update(int a,int b,double mult,double plus){
  //printf("UPDATE: [%d,%d): *%lf+%lf\n",a,b,mult,plus);
  update(0,0,N,a,b,Linear(mult,plus));
}

double query(int w,int L,int R,int a,int b){
  push(w,L,R);
  if((b<=L)||(a>=R)){
    return 0;
  }
  if((a<=L)&&(b>=R)){
    return st[w].sum;
  }
  int M=(L+R)/2;
  return query(w*2+1,L,M,a,b)+query(w*2+2,M,R,a,b);
}

double query(int a,int b){
  return query(0,0,N,a,b);
}

int main(){
  int Q;
  scanf("%d %d",&N,&Q);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  build(0,0,N);
  /*
  printf("NUMBERS: ");
  for(int i=0;i<N;i++){
    printf("%lf ",query(i,i+1));
  }
  printf("\n");
  */
  for(int i=0;i<Q;i++){
    int T;
    scanf("%d",&T);
    if(T==1){
      int L1,R1,L2,R2;
      scanf("%d %d %d %d",&L1,&R1,&L2,&R2);
      L1--,L2--;
      double A1=query(L1,R1)/(R1-L1);
      double A2=query(L2,R2)/(R2-L2);
      //printf("A: %lf %lf\n",A1,A2);
      update(L1,R1,1-1.0/(R1-L1),A2/(R1-L1));
      update(L2,R2,1-1.0/(R2-L2),A1/(R2-L2));
      /*
      for(int i=0;i<N;i++){
	query(i,i+1);
      }
      printf("NUMBERS: ");
      for(int i=0;i<N;i++){
	printf("%lf ",query(i,i+1));
      }
      printf("\n");
      */
    }else if(T==2){
      int L,R;
      scanf("%d %d",&L,&R);
      L--;
      printf("%lf\n",query(L,R));
    }
  }
  return 0;
}