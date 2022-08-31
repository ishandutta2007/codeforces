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
long long n,m,i,j,k,l,dp[1<<19][19],mp[19][19],x,y,ans;
int main()
{
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		cin>>x>>y;
		x--;
		y--;
		mp[x][y]=mp[y][x]=1;
	}
	for (i=2;i<n;i++)
	{
		for (j=0;j<(1<<(i-1));j++)
		{
			for (k=0;k<=i;k++)
			{
				dp[j][k]=0;
			}
		}
		dp[0][i]=1;
		for (j=0;j<(1<<(i));j++)
		{
			for (k=0;k<=i-(j>0);k++)
			{
				if (mp[k][i]&&(j>(j&(-j)))) ans+=dp[j][k];
				for (l=0;l<i;l++)
				{
					if ((1<<l)&j) continue;
					if (!mp[k][l]) continue;
					dp[j|(1<<l)][l]+=dp[j][k];
				}
			}
		}
	}
	cout<<ans/2;
	return 0;
}