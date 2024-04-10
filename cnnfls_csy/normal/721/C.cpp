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
int n,m,t,i,j,k,dp[5005][5005],x,y,z,pre[5005][5005];
vector<int> ans;
vector<pair<int,int>/**/> bi[5005],nbi[5005];
bool used[5005];
void dfs(int x)
{
	int i;
	used[x]=1;
	for (i=0;i<bi[x].size();i++)
	{
		if (!used[bi[x][i].first])
		{
			dfs(bi[x][i].first);
		}
	}
	ans.push_back(x);
}
void print(int x,int y)
{
	if (y>1) print(pre[x][y],y-1);
	cout<<x<<' ';
}
int main()
{
	cin>>n>>m>>t;
	for (i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		bi[x].push_back(make_pair(y,z));
		nbi[y].push_back(make_pair(x,z));
	}
	for (i=0;i<=n;i++)
	{
		for (j=0;j<=n;j++)
		{
			dp[i][j]=1e9+7;
		}
	}
	dp[1][1]=0;
	for (i=1;i<=n;i++)
	{
		if (!used[i]) 
		{
			dfs(i);
		}
	}
	reverse(ans.begin(),ans.end());
	for (i=0;i<ans.size();i++)
	{
		for (j=1;j<=n;j++)
		{
			for (k=0;k<nbi[ans[i]].size();k++)
			{
				if (dp[ans[i]][j]>dp[nbi[ans[i]][k].first][j-1]+nbi[ans[i]][k].second)
				{
					dp[ans[i]][j]=dp[nbi[ans[i]][k].first][j-1]+nbi[ans[i]][k].second;
					pre[ans[i]][j]=nbi[ans[i]][k].first;
				}
			}
		}
	}
	for (i=n;i>=2;i--)
	{
		if (dp[n][i]<=t)
		{
			cout<<i<<endl;
			print(n,i);
			return 0;
		}
	}
	cout<<-1;
	return 0;
}