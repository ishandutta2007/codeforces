#include <cstdio>
#include <algorithm>

int as[500005];

void solve(){
  int N;
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
  }
  as[N+1]=0;
  long long cost=0;
  long long l=0,r=0;
  for(int i=1;i<=N+1;i++){
    if(as[i]<l){
      cost+=(l-as[i]);
      l=as[i];
      r=as[i];
    }else if(as[i]>r){
      cost+=(as[i]-r);
      l=r;
      r=as[i];
    }else{
      l=as[i];
      r=as[i];
    }
    //printf("%d: [%lld,%lld] %lld\n",i,l,r,cost);
  }
  printf("%lld\n",cost);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}