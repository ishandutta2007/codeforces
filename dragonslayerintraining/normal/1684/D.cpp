#include <cstdio>
#include <algorithm>

int as[200005];

void solve(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    as[i]+=i;
  }
  std::sort(as,as+N);
  long long ans=0;
  for(int i=0;i<N-K;i++){
    ans+=as[i]-i;
  }
  printf("%lld\n",ans);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}