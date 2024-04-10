#include <cstdio>
#include <algorithm>

const int MOD=998244353;

const int INF=1e9+7;

int as[1005]={-INF};
int N,K;

int dp[1005][1005]={{1}};

int solve(int crit){
  int j=0;
  for(int i=1;i<=N;i++){
    for(int k=0;k<=K;k++){
      dp[i][k]=dp[i-1][k];
    }
    while(as[j+1]<=as[i]-crit) j++;
    for(int k=0;k<K;k++){
      dp[i][k+1]=(dp[i][k+1]+dp[j][k])%MOD;
    }
  }
  return dp[N][K];
}

int main(){
  scanf("%d %d",&N,&K);
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
  }
  std::sort(as+1,as+N+1);
  int ans=0;
  for(int i=1;i*(K-1)<=100000;i++){
    ans=(ans+solve(i))%MOD;
  }
  printf("%d\n",ans);
  return 0;
}