#include<cstdio>
#define max(a,b)((a)>(b)?(a):(b))
#define min(a,b)((a)<(b)?(a):(b))
const int N=52;
int n,dp[N][N][N][N],b[N][N];char a[N][N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
	  scanf("%s",a[i]+1);
	  for(int j=1;j<=n;j++)
		b[i][j]=b[i][j-1]+b[i-1][j]-b[i-1][j-1]+(a[i][j]=='#');
	}
	for(int k=0;k<n;k++)for(int l=0;l<n;l++)
	  for(int i=1;i+k<=n;i++)for(int j=1;j+l<=n;j++){
		dp[i][i+k][j][j+l]=b[i+k][j+l]-b[i-1][j+l]-b[i+k][j-1]+b[i-1][j-1]?max(k+1,l+1):0;
		for(int p=0;p<k;p++)
		  dp[i][i+k][j][j+l]=min(dp[i][i+k][j][j+l],dp[i][i+p][j][j+l]+dp[i+p+1][i+k][j][j+l]);
		for(int p=0;p<l;p++)
		  dp[i][i+k][j][j+l]=min(dp[i][i+k][j][j+l],dp[i][i+k][j][j+p]+dp[i][i+k][j+p+1][j+l]);
	  }
	printf("%d",dp[1][n][1][n]);	
	return 0;
}