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
long long n,m,i,j,k,dp[505][505],q,x,y,xx,yy,ans;
char mp[505][505];
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			cin>>mp[i][j];
		}
	}
	for (i=1;i<=n;i++) mp[i][0]=mp[i][m+1]='#';
	for (i=1;i<=m;i++) mp[0][i]=mp[n+1][i]='#';
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
			/*for (k=1;k<=i;k++)
			{
				if (mp[k][j]=='.'&&mp[k][j-1]=='.') dp[i][j]++;
			}
			for (k=1;k<=j;k++)
			{
				if (mp[i][k]=='.'&&mp[i-1][k]=='.') dp[i][j]++;
			}*/
			if (mp[i][j]=='.')
			{
				if (mp[i-1][j]=='.') dp[i][j]++;
				if (mp[i][j-1]=='.') dp[i][j]++;
			}
		}
	}
	cin>>q;
	for (i=1;i<=q;i++)
	{
		cin>>x>>y>>xx>>yy;
		ans=dp[xx][yy]-dp[xx][y-1]-dp[x-1][yy]+dp[x-1][y-1];
		for (k=x;k<=xx;k++)
		{
			if (mp[k][y]=='.'&&mp[k][y-1]=='.') ans--;
		}
		for (k=y;k<=yy;k++)
		{
			if (mp[x][k]=='.'&&mp[x-1][k]=='.') ans--;
		}
		cout<<ans<<endl;
	}
	return 0;
}