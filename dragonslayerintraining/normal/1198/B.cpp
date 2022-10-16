#include <cstdio>
#include <algorithm>

const int INF=1e9+7;

int as[200005];
int st[200005*4];

void setmax(int& x,int y){
  x=std::max(x,y);
}

void push(int w,int L,int R){
  if(R-L>1){
    setmax(st[w<<1],st[w]);
    setmax(st[w<<1|1],st[w]);
    st[w]=-INF;
  }
}

void update(int w,int L,int R,int i,int v){
  push(w,L,R);
  if(i<L||i>=R) return;
  if(R-L==1){
    st[w]=v;
  }else{
    int M=(L+R)/2;
    update(w<<1,L,M,i,v);
    update(w<<1|1,M,R,i,v);
  }
}

void dump(int w,int L,int R){
  push(w,L,R);
  if(R-L==1){
    printf("%d ",st[w]);
  }else{
    int M=(L+R)/2;
    dump(w<<1,L,M);
    dump(w<<1|1,M,R);
  }
}

int main(){
  int N;
  scanf("%d",&N);
  std::fill(st,st+N*4,-INF);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    update(1,0,N,i,as[i]);
  }
  int Q;
  scanf("%d",&Q);
  for(int i=0;i<Q;i++){
    int T;
    scanf("%d",&T);
    if(T==1){
      int P,X;
      scanf("%d %d",&P,&X);
      P--;
      update(1,0,N,P,X);
    }else{
      int X;
      scanf("%d",&X);
      setmax(st[1],X);
    }
  }
  dump(1,0,N);
  printf("\n");
}