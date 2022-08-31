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
int n,m,i,j,k,l,p,dis[65][65][65],dp[65][65][65],x,y,z,q;
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m>>q;
	for (i=1;i<=m;i++)
	{
		for (j=1;j<=n;j++)
		{
			for (k=1;k<=n;k++)
			{
				cin>>dis[i][j][k];
			}
		}
	}
	for (l=1;l<=m;l++)
	{
		for (k=1;k<=n;k++)
		{
			for (i=1;i<=n;i++)
			{
				for (j=1;j<=n;j++)
				{
					dis[l][i][j]=min(dis[l][i][j],dis[l][i][k]+dis[l][k][j]);
				}
			}
		}
	}
	for (i=0;i<=60;i++)
	{
		for (j=0;j<=60;j++)
		{
			for (k=0;k<=60;k++)
			{
				dp[i][j][k]=1<<29;
			}
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			for (k=1;k<=m;k++)
			{
				dis[0][i][j]=dp[i][j][0]=min(dp[i][j][0],dis[k][i][j]);
			}
		}
	}
	/*for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			cerr<<dis[0][i][j]<<' ';
		}
		cerr<<endl;
	}*/
	for (l=1;l<=60;l++)
	{
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
			{
				for (k=1;k<=n;k++)
				{
					dp[i][j][l]=min(dp[i][j][l],dp[i][k][l-1]+dis[0][k][j]);
				}
			}
		}
	}
/*	for (l=0;l<=3;l++)
	{
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
			{
				cerr<<dp[i][j][l]<<' ';
			}
			cerr<<endl;
		}
		cerr<<endl;
	}*/
	for (i=1;i<=q;i++)
	{
		cin>>x>>y>>z;
		cout<<dp[x][y][min(60,z)]<<endl;
	}
	return 0;
}