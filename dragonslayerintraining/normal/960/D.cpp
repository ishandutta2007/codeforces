#include <cstdio>
#include <stdint.h>

int64_t shifts[61];//shift of nodes from locations

int64_t msb(int64_t X){
  for(int64_t l=61-1;l>=0;l--){
    if(X&(1LL<<l)){
      return l;
    }
  }
  return -1;
}

void shiftvals(int64_t X,int64_t K){
  int64_t l=msb(X);
  shifts[l]=((shifts[l]+K)&((1LL<<l)-1));
}

void shiftnodes(int64_t X,int64_t K){
  for(int64_t l=msb(X);l<61;l++,K<<=1){
    int64_t mask=((1LL<<l)-1);
    K&=mask;
    shifts[l]=((shifts[l]+K)&mask);
  }
}

int64_t query(int64_t X){
  int64_t l=msb(X);
  X-=(1LL<<l);
  X=((X+shifts[l])&((1LL<<l)-1));
  bool first=true;
  for(;l>=0;l--,X>>=1){
    int64_t mask=((1LL<<l)-1);
    if(first){first=false;}else{printf(" ");}
    printf("%I64d",int64_t((1LL<<l)+((X+(1LL<<l)-shifts[l])&mask)));
  }
  printf("\n");
}

int main(){
  int64_t Q;
  scanf("%I64d",&Q);
  while(Q-->0){
    int64_t T,X,K;
    scanf("%I64d",&T);
    switch(T){
    case 1:
      scanf("%I64d %I64d",&X,&K);
      shiftvals(X,K);
      break;
    case 2:
      scanf("%I64d %I64d",&X,&K);
      shiftnodes(X,K);
      break;
    case 3:
      scanf("%I64d",&X);
      query(X);
      break;
    }
  }
  return 0;
}