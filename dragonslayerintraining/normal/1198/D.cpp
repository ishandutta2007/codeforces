#include <cstdio>
#include <algorithm>

char grid[64][64];
int prefix[64][64];
int dp[51][51][51][51];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    scanf("%s",grid[i]+1);
  }
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]
	+(grid[i][j]=='#');
    }
  }
  for(int x1=N-1;x1>=0;x1--){
    for(int x2=x1+1;x2<=N;x2++){
      for(int y1=N-1;y1>=0;y1--){
	for(int y2=y1+1;y2<=N;y2++){
	  int cnt=prefix[x2][y2]-prefix[x1][y2]-prefix[x2][y1]+prefix[x1][y1];
	  int& res=dp[x1][x2][y1][y2];
	  res=cnt?std::max(x2-x1,y2-y1):0;
	  for(int xm=x1+1;xm<x2;xm++){
	    res=std::min(res,dp[x1][xm][y1][y2]+dp[xm][x2][y1][y2]);
	  }
	  for(int ym=y1+1;ym<y2;ym++){
	    res=std::min(res,dp[x1][x2][y1][ym]+dp[x1][x2][ym][y2]);
	  }
	}
      }
    }
  }
  printf("%d\n",dp[0][N][0][N]);
}