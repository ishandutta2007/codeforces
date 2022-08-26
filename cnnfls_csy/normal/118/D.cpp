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
long long n1,n2,m1,m2,i,j,k,dp[105][105][2],mod=1e8;
int main()
{
	cin>>n1>>n2>>m1>>m2;
	for (i=1;i<=m1;i++) dp[i][0][0]=1;
	for (i=1;i<=m2;i++) dp[0][i][1]=1;
	for (i=1;i<=n1;i++)
	{
		for (j=1;j<=n2;j++)
		{
			for (k=1;k<=min(i,m1);k++)
			{
				dp[i][j][0]=(dp[i][j][0]+dp[i-k][j][1])%mod;
			}
			for (k=1;k<=min(j,m2);k++)
			{
				dp[i][j][1]=(dp[i][j][1]+dp[i][j-k][0])%mod;
			}
		}
	}
	/*for (i=1;i<=n1;i++)
	{
		for (j=1;j<=n2;j++)
		{
			cerr<<dp[i][j][0]<<' ';
		}
		cerr<<endl;
	}
		cerr<<endl;
	for (i=1;i<=n1;i++)
	{
		for (j=1;j<=n2;j++)
		{
			cerr<<dp[i][j][1]<<' ';
		}
		cerr<<endl;
	}
	*/
	cout<<(dp[n1][n2][0]+dp[n1][n2][1])%mod;
	return 0;
}