#include <bits/stdc++.h>
using namespace std;
long long n,m,i,j,k,l,dp[2][5005][2][2],a[5005];
int main()
{
	scanf("%I64d",&n);
	memset(dp,22,sizeof(dp));
	dp[0][0][0][0]=0;
	for (i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
	}
	for (i=1;i<=n;i++)
	{
		memset(dp[i&1],22,sizeof(dp[i&1]));
		for (j=0;j<=i;j++)
		{
			dp[i&1][j][0][0]=min(dp[i-1&1][j][0][0],dp[i-1&1][j][0][1]);
			dp[i&1][j][0][1]=min(dp[i-1&1][j][1][0],dp[i-1&1][j][1][1]);
			if (j) dp[i&1][j][1][0]=min(dp[i-1&1][j-1][0][0]+max(0ll,a[i-1]-a[i]+1)+max(0ll,a[i+1]-a[i]+1),dp[i-1&1][j-1][0][1]+max(0ll,min(a[i-2]-1,a[i-1])-a[i]+1)+max(0ll,a[i+1]-a[i]+1));
		}
	}
	for (j=1;j<=(n+1)/2;j++)
	{
		printf("%I64d ",min(min(dp[n&1][j][0][0],dp[n&1][j][0][1]),dp[n&1][j][1][0]));
	}
	return 0;
}