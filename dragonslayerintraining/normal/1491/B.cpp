#include <cstdio>
#include <algorithm>

int as[100005];

int solve(){
  int N,U,V;
  scanf("%d %d %d",&N,&U,&V);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i+1<N;i++){
    int d=as[i]-as[i+1];
    if(d<-1||d>1){
      return 0;
    }
  }
  for(int i=0;i+1<N;i++){
    int d=as[i]-as[i+1];
    if(d!=0){
      return std::min(U,V);
    }
  }
  return V+std::min(U,V);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    printf("%d\n",solve());
  }
}