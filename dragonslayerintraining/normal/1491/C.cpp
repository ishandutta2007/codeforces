#include <cstdio>
#include <algorithm>

long long ss[100005];
long long delta[100005];

void solve(){
  long long N;
  scanf("%lld",&N);
  for(long long i=1;i<=N;i++){
    scanf("%lld",&ss[i]);
  }
  std::fill(delta,delta+N+1,0);
  long long cost=0;
  long long extra=0;
  for(long long i=1;i<=N;i++){
    extra+=delta[i];
    delta[i+2]++;
    if(i+ss[i]+1<=N) delta[i+ss[i]+1]--;
    long long moves=ss[i]-1;
    if(moves>=extra){
      cost+=moves-extra;
    }else{
      delta[i+1]+=extra-moves;
      delta[i+2]-=extra-moves;
    }
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