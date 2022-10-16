#include <cstdio>

int dp[16][360];
int main(){
  int N;
  scanf("%d",&N);
  dp[0][0]=1;
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    for(int j=0;j<360;j++){
      dp[i+1][(j+A)%360]|=dp[i][j];
      dp[i+1][(j+360-A)%360]|=dp[i][j];
    }
  }
  if(dp[N][0]){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
  return 0;
}