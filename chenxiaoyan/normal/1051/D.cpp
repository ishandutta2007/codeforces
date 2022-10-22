#include<cstdio>
#include<algorithm>
using namespace std;
#define mod 998244353
int dp[1001][2001][4];
#define ww 0
#define wb 1
#define bw 2
#define bb 3
int main(){
	int n,want,i,j;scanf("%d%d",&n,&want);
	dp[1][1][ww]=dp[1][2][wb]=dp[1][2][bw]=dp[1][1][bb]=1;
	for(i=2;i<=n;i++)for(j=1;j<=(i<<1);j++){
		dp[i][j][ww]=(dp[i-1][j][ww]+dp[i-1][j][wb])%mod+(dp[i-1][j][bw]+dp[i-1][j-1][bb])%
		mod;
		dp[i][j][bb]=dp[i][j][ww]%=mod;
		dp[i][j][wb]=(dp[i-1][j][wb]+(j-2>0?dp[i-1][j-2][bw]:0))%mod+(dp[i-1][j-1][ww]+dp[i-
		1][j-1][bb])%mod;
		dp[i][j][bw]=dp[i][j][wb]%=mod;
	}
//	for(i=1;i<=n;i++)for(j=1;j<=(i<<1);j++){
//		for(int k=0;k<4;k++)printf("dp[%d][%d][%d]=%d\t",i,j,k,dp[i][j][k]);
//		puts("");
//	}
	printf("%d\n",((dp[n][want][ww]+dp[n][want][wb])%mod+(dp[n][want][bw]+dp[n][want][bb])%
	mod)%mod);
	return 0;
}
/*1
3 4
*/
/*2///
4 1
*/
/*3
1 2
*/