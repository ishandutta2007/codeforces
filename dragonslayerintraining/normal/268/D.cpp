#include <cstdio>

const int MOD=1e9+9;

int dp[1001][31][31][31][2];

void addmod(int& x,int y){
  x=(x+y)%MOD;
}

int main(){
  int N,H;
  scanf("%d %d",&N,&H);
  dp[1][1][1][1][1]=1;
  for(int i=1;i<N;i++){
    for(int j=1;j<=H;j++){
      int jj=(j==H)?H:(j+1);
      for(int k=1;k<=H;k++){
	int kk=(k==H)?H:(k+1);
	for(int l=1;l<=H;l++){
	  int ll=(l==H)?H:(l+1);
	  
	  addmod(dp[i+1][jj][kk][ll][0],dp[i][j][k][l][0]);
	  addmod(dp[i+1][jj][kk][ll][1],dp[i][j][k][l][1]);
	  
	  addmod(dp[i+1][H][kk][ll][j<H],dp[i][j][k][l][0]);
	  addmod(dp[i+1][1][kk][ll][j<H],dp[i][j][k][l][1]);
	  
	  addmod(dp[i+1][jj][H][ll][k<H],dp[i][j][k][l][0]);
	  addmod(dp[i+1][jj][1][ll][k<H],dp[i][j][k][l][1]);
	  
	  addmod(dp[i+1][jj][kk][H][l<H],dp[i][j][k][l][0]);
	  addmod(dp[i+1][jj][kk][1][l<H],dp[i][j][k][l][1]);
	}
      }
    }
  }
  int ans=1;
  for(int i=0;i<N;i++){
    ans=ans*2%MOD*2%MOD;
  }
  printf("%d\n",(ans+MOD-dp[N][H][H][H][0]*2%MOD*2%MOD)%MOD);
  return 0;
}