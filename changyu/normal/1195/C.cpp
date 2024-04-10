#include<cstdio>
#define int long long
#define max(a,b)((a)>(b)?(a):(b))
const int N=1e5+1;
int n,a[N][2],dp[N][2];
signed main(){
	scanf("%I64d",&n);
	for(int j=0;j<2;j++)
	  for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i][j]);
	for(int i=1;i<=n;i++)
	  for(int j=0;j<2;j++)
		dp[i][j]=max(dp[i-1][j],dp[i-1][j^1]+a[i][j]);
	printf("%I64d",max(dp[n][0],dp[n][1]));
	return 0;
}