#include <cstdio>
#include <algorithm>

int as[100001];
int dp[3][100001];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
  }
  as[0]=-1e9;
  int best=0;
  for(int i=1;i<=N;i++){
    if(as[i]>as[i-1]){
      dp[0][i]=dp[0][i-1]+1;
    }else{
      dp[0][i]=1;
    }
    best=std::max(best,dp[0][i]+1);
    if(as[i]>as[i-1]){
      dp[1][i]=dp[1][i-1]+1;
    }else{
      dp[1][i]=1;
    }
    if(i>=2&&as[i]-as[i-2]>1){
      dp[1][i]=std::max(dp[1][i],dp[0][i-2]+2);
    }
    best=std::max(best,dp[1][i]);
  }
  printf("%d\n",std::min(N,best));
  return 0;
}