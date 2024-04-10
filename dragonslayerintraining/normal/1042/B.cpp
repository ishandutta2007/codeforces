#include <cstdio>
#include <algorithm>

const int INF=1e9+7;

int dp[8];

int main(){
  std::fill(dp,dp+8,INF);
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int C;
    char str[5];
    scanf("%d %s",&C,str);
    int mask=0;
    for(int j=0;str[j];j++){
      mask|=(1<<(str[j]-'A'));
    }
    dp[mask]=std::min(dp[mask],C);
  }
  for(int a=1;a<8;a++){
    for(int b=1;b<8;b++){
      dp[a|b]=std::min(dp[a|b],dp[a]+dp[b]);
    }
  }
  printf("%d\n",(dp[7]==INF)?-1:dp[7]);
  return 0;
}