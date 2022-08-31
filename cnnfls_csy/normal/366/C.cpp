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
int n,m,i,j,dp[105][200005],add=100000,num[105],num2[105];
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	for (i=1;i<=n;i++)
	{
		cin>>num2[i];
	}
	for (i=0;i<=n;i++)
	{
		for (j=0;j<=add+add;j++) dp[i][j]=-1<<30;
	}
	dp[0][add]=0;
	for (i=1;i<=n;i++)
	{
		for (j=0;j<=add+add;j++)
		{
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-num[i]+num2[i]*m]+num[i]);
		}
	}
	/*for (i=1;i<=n;i++)
	{
		for (j=add;j<=add+20;j++)
		{
			if (dp[i][j]>0) cerr<<dp[i][j]<<' '; else cerr<<"-1 ";
		}
		cerr<<endl;
	}*/
	if (dp[n][add]>0) cout<<dp[n][add]; else cout<<-1;
	return 0;
}