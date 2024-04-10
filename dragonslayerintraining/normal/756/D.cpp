#include <cstdio>
#include <stdint.h>

const int MOD=1e9+7;

int N;
char str[5005];
int dp[26][5005];
int all[5005];
int combo[5005][5005];

void addmod(int& x,int64_t y){x=(x+y)%MOD;}

int main(){
  scanf("%d %s",&N,str);
  for(int i=0;i<=N;i++){
    combo[i][0]=combo[0][i]=1;
  }
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      combo[i][j]=(combo[i][j-1]+combo[i-1][j])%MOD;
    }
  }
  for(int i=0;i<N;i++){
    int c=str[i]-'a';
    for(int j=0;j<=N;j++){
      all[j]-=dp[c][j];
      dp[c][j]=0;
    }
    addmod(dp[c][1],1);
    for(int j=N;j>=0;j--){
      addmod(dp[c][j+1],all[j]);
      addmod(all[j+1],dp[c][j+1]);
    }
  }
  int ans=0;
  for(int b=0;b<26;b++){
    for(int j=1;j<=N;j++){
      addmod(ans,1LL*dp[b][j]*combo[N-j][j-1]);
    }
  }
  printf("%d\n",ans);
  return 0;
}