#include <cstdio>

const int MOD=998244353;

int as[200005];
int last[200005];
int dp[200005][2];
int sum[200005];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<2;i++){
    if(as[i]==-1){
      last[i]=1;
      dp[i][0]=1;
      dp[i][1]=1;
    }else{
      last[i]=as[i];
      dp[i][0]=0;
      dp[i][1]=1;
    }
  }
  for(int i=0;i<N;i++){
    if(i>=2&&as[i]!=-1){
      int base=dp[i][as[i]==last[i-2]];
      dp[i][0]=0;
      dp[i][1]=base;
    }
    if(i<N-2){
      dp[i+2][0]=(1LL*(K-2)*dp[i][0]+dp[i][1])%MOD;
      dp[i+2][1]=1LL*(K-1)*dp[i][0]%MOD;
      last[i+2]=(as[i+2]==-1)?last[i]:as[i+2];
    }
    sum[i]=(1LL*dp[i][0]*(K-1)+dp[i][1])%MOD;
    //printf("dp[%d]=%d,%d\n",i,dp[i][0],dp[i][1]);
  }
  printf("%I64d\n",1LL*sum[N-2]*sum[N-1]%MOD);
  return 0;
}