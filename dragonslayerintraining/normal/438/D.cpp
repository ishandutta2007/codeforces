#include <cstdio>
#include <algorithm>
#include <stdint.h>

int max[400000];
int64_t sum[400000];

void build(int w,int L,int R){
  if(R-L==1){
    int X;
    scanf("%d",&X);
    max[w]=sum[w]=X;
  }else{
    int M=(L+R)/2;
    build(w*2+1,L,M);
    build(w*2+2,M,R);
    max[w]=std::max(max[w*2+1],max[w*2+2]);
    sum[w]=sum[w*2+1]+sum[w*2+2];
  }
}

int64_t query(int w,int L,int R,int a,int b){
  if(b<=L||a>=R) return 0;
  if(a<=L&&b>=R) return sum[w];
  int M=(L+R)/2;
  return query(w*2+1,L,M,a,b)+query(w*2+2,M,R,a,b);
}

void update(int w,int L,int R,int a,int b,int MOD){
  if(b<=L||a>=R) return;
  if(a>L||b<R||(R-L>1&&max[w]>=MOD)){
    int M=(L+R)/2;
    update(w*2+1,L,M,a,b,MOD);
    update(w*2+2,M,R,a,b,MOD);
    max[w]=std::max(max[w*2+1],max[w*2+2]);
    sum[w]=sum[w*2+1]+sum[w*2+2];
  }else if(R-L==1){
    max[w]%=MOD;
    sum[w]%=MOD;
  }
}

void set(int w,int L,int R,int i,int v){
  if(i<L||i>=R) return;
  if(R-L==1){
    max[w]=sum[w]=v;
  }else{
    int M=(L+R)/2;
    set(w*2+1,L,M,i,v);
    set(w*2+2,M,R,i,v);
    max[w]=std::max(max[w*2+1],max[w*2+2]);
    sum[w]=sum[w*2+1]+sum[w*2+2];
  }
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  build(0,0,N);
  for(int i=0;i<M;i++){
    int T;
    scanf("%d",&T);
    switch(T){
    case 1:{
      int L,R;
      scanf("%d %d",&L,&R);
      printf("%I64d\n",query(0,0,N,L-1,R));
      break;
    }
    case 2:{
      int L,R,X;
      scanf("%d %d %d",&L,&R,&X);
      update(0,0,N,L-1,R,X);
      break;
    }
    case 3:{
      int K,X;
      scanf("%d %d",&K,&X);
      set(0,0,N,K-1,X);
      break;
    }
    }
  }
  return 0;
}