#include <cstdio>
#include <algorithm>

int ds[100005];

void solve(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&ds[i]);
  }
  std::sort(ds,ds+N);
  long long cost=ds[N-1];
  for(int i=0;i<N;i++){
    cost+=(N-i-1LL)*ds[i]-1LL*i*ds[i];
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