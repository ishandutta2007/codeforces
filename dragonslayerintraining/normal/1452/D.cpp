#include <cstdio>

const long long MOD=998244353;
const long long HALF=(MOD+1)/2;

int dp[200005];

int main(){
  int N;
  scanf("%d",&N);
  dp[0]=0;
  dp[1]=1;
  for(int i=2;i<=N;i++){
    dp[i]=(dp[i-1]+dp[i-2])%MOD;
  }
  int ans=dp[N];
  for(int i=1;i<=N;i++){
    ans=ans*(HALF)%MOD;
  }
  printf("%d\n",ans);
}