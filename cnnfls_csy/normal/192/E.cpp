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
int n,m,i,j,fa[100005][18],cnt[100005],x,y,dep[100005],ans[100005];
vector<pair<int,int> > bi[100005];
void dfs(int x,int par)
{
	int i;
	fa[x][0]=par;
	for (i=0;i<bi[x].size();i++)
	{
		if (bi[x][i].first!=par)
		{
			dep[bi[x][i].first]=dep[x]+1;
			dfs(bi[x][i].first,x);
		}
	}
}
void dfs2(int x,int par)
{
	int i;
	for (i=0;i<bi[x].size();i++)
	{
		if (bi[x][i].first!=par)
		{
			dfs2(bi[x][i].first,x);
			ans[bi[x][i].second]=cnt[bi[x][i].first];
			cnt[x]+=cnt[bi[x][i].first];
		}
	}
}
int lca(int x,int y)
{
	if (dep[x]>dep[y]) swap(x,y);
	int t=dep[y]-dep[x],i;
	for (i=0;i<=17;i++)
	{
		if (t&(1<<i)) y=fa[y][i];
	}
	if (x==y) return x;
	for (i=17;i>=0;i--)
	{
		if (fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
int main()
{
	cin>>n;
	for (i=1;i<n;i++)
	{
		cin>>x>>y;
		bi[x].push_back(make_pair(y,i));
		bi[y].push_back(make_pair(x,i));
	}
	dfs(1,1);
	for (j=1;j<=17;j++)
	{
		for (i=1;i<=n;i++)
		{
			fa[i][j]=fa[fa[i][j-1]][j-1];
		}
	}
	cin>>m;
	while (m--)
	{
		cin>>x>>y;
		if (x==y) continue;
		int z=lca(x,y);
		cnt[x]++;
		cnt[y]++;
		cnt[z]-=2;
	}
	dfs2(1,0);
	for (i=1;i<n;i++) cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}