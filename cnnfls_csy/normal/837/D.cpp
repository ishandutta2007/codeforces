#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
long long n,m,i,j,k,num2[205],num5[205],dp[2][205][6005],ans,x;
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>x;
		while (x%2==0)
		{
			x/=2;
			num2[i]++;
		}
		while (x%5==0)
		{
			x/=5;
			num5[i]++;
		}
	}
	memset(dp,-127,sizeof(dp));
	dp[0][0][0]=0;
	for (i=1;i<=n;i++)
	{
		memset(dp[i&1],-127,sizeof(dp[i&1]));
		for (j=0;j<=i&&j<=m;j++)
		{
			for (k=0;k<=n*30;k++)
			{
				if (k>=num5[i]&&j) dp[i&1][j][k]=max(dp[(i-1)&1][j][k],dp[(i-1)&1][j-1][k-num5[i]]+num2[i]);
				else dp[i&1][j][k]=dp[(i-1)&1][j][k];
			}
		}
	}
	for (i=0;i<=n*30;i++) ans=max(ans,min(i,dp[n&1][m][i]));
	cout<<ans;
	return 0;
}