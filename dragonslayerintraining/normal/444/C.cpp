#include <cstdio>
#include <cmath>
#include <stdint.h>

int color[400000];
int64_t colorful[400000];
int64_t lazy[400000];

void build(int w,int L,int R){
  if(R-L==1){
    color[w]=R;
  }else{
    int M=(L+R)/2;
    build(w*2+1,L,M);
    build(w*2+2,M,R);
  }
}

void push(int w,int L,int R){
  colorful[w]+=lazy[w]*(R-L);
  if(R-L>1){
    lazy[w*2+1]+=lazy[w];
    lazy[w*2+2]+=lazy[w];
    if(color[w]){
      color[w*2+1]=color[w*2+2]=color[w];
    }
  }
  lazy[w]=0;
}

void update(int w,int L,int R,int a,int b,int v){
  push(w,L,R);
  if(a>=R||b<=L){
    return;
  }
  if(a<=L&&b>=R&&color[w]){
    lazy[w]=std::abs(v-color[w]);
    color[w]=v;
    push(w,L,R);
  }else{
    int M=(L+R)/2;
    update(w*2+1,L,M,a,b,v);
    update(w*2+2,M,R,a,b,v);
    color[w]=(color[w*2+1]==color[w*2+2])?color[w*2+1]:0;
    colorful[w]=colorful[w*2+1]+colorful[w*2+2];
  }
}

int64_t query(int w,int L,int R,int a,int b){
  push(w,L,R);
  if(a>=R||b<=L){
    return 0;
  }
  if(a<=L&&b>=R){
    return colorful[w];
  }else{
    int M=(L+R)/2;
    return query(w*2+1,L,M,a,b)+
      query(w*2+2,M,R,a,b);
  }
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  build(0,0,N);
  for(int i=0;i<M;i++){
    int T;
    scanf("%d",&T);
    if(T==1){
      int L,R,X;
      scanf("%d %d %d",&L,&R,&X);
      update(0,0,N,L-1,R,X);
    }else{
      int L,R;
      scanf("%d %d",&L,&R);
      printf("%I64d\n",query(0,0,N,L-1,R));
    }
  }
  return 0;
}