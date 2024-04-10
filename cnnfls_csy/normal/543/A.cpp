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
int n,m,t,mod,i,j,k,num[505],dp[505][505],ans;
int main()
{
	cin>>n>>m>>t>>mod;
	for (i=1;i<=n;i++) cin>>num[i];
	dp[0][0]=1;
	for (i=1;i<=n;i++)
	{
		for (j=0;j<=m;j++)
		{
			for (k=0;k<=t;k++)
			{
				if (j&&k>=num[i]) dp[j][k]+=dp[j-1][k-num[i]];
				if (dp[j][k]>=mod) dp[j][k]-=mod;
			}
		}
	/*	for (j=0;j<=m;j++)
		{
			for (k=0;k<=t;k++)
			{
				cerr<<dp[i&1][j][k]<<' ';
			}
			cerr<<endl;
		}
		cerr<<endl;*/
	}
	for (i=0;i<=t;i++)
	{
		ans+=dp[m][i];
		if (ans>=mod) ans-=mod;
	}
	cout<<ans;
	return 0;
}