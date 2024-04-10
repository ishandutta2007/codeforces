#include <cstdio>
#include <algorithm>

int as[200005];
int dp[200005];

void solve(){
  int N;
  scanf("%d",&N);
  long long sum=0;
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    if(i%2==0){
      sum+=as[i];
      as[i]*=-1;
    }
  }
  long long x=0,y=0,best=0;
  for(int i=1;i<N;i++){
    x=std::max(0LL,x+as[i]+as[i-1]);
    best=std::max(x,best);
    std::swap(x,y);
  }
  printf("%lld\n",sum+best);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}