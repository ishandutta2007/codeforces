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
int n,m,i,j,x[10005],y[10005],dfn[10005],low[10005],ti,ed[10005],lst,dep[10005],fat[10005],fa2[10005],vis2[10005];
vector<pair<int,int>/**/> bi[10005];
vector<int> in,ans;
void dfs(int x,int fa)
{
	fat[x]=fa;
	int i;
	dfn[x]=++ti;
	low[x]=dep[x];
	for (i=0;i<bi[x].size();i++)
	{
		if (bi[x][i].first==fa)
		{
			continue;
		}
		if (!dfn[bi[x][i].first])
		{
			dep[bi[x][i].first]=dep[x]+1;
			fa2[bi[x][i].first]=bi[x][i].second;
			dfs(bi[x][i].first,x);
			low[x]=min(low[x],low[bi[x][i].first]);
		}
		else
		{
			if ((dep[x]^dep[bi[x][i].first])&1) low[x]=min(low[x],dep[bi[x][i].first]);
			else if (!vis2[bi[x][i].second])
			{
				in.push_back(bi[x][i].second);
				vis2[bi[x][i].second]=1;
			}
		}
	}
	ed[x]=++ti;
}
bool check(int x,int y)
{
	return dfn[x]<=dfn[y]&&dfn[y]<=ed[x];
}
int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	while (!check(y,x)) y=fat[y];
	return y;
}
void get(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	while (x!=y)
	{
		if (low[x]>dep[fat[x]]) ans.push_back(fa2[x]);
		x=fat[x];
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		bi[x[i]].push_back(make_pair(y[i],i));
		bi[y[i]].push_back(make_pair(x[i],i));
	}
	for (i=1;i<=n;i++)
	{
		if (!dfn[i])
		{
			lst=in.size();
			dfs(i,0);
			if (lst&&lst<in.size())
			{
				cout<<0;
				return 0;
			}
		}
	}
	if (in.empty())
	{
		cout<<m<<endl;
		for (i=1;i<=m;i++) cout<<i<<' ';
		return 0;
	}
	if (in.size()==1)
	{
		ans.push_back(in[0]);
		if (dep[x[in[0]]]<dep[y[in[0]]]) swap(x[in[0]],y[in[0]]);
		get(x[in[0]],y[in[0]]);
	}
	else
	{
		//if (x[1]==5271) return 1;
		if (dep[x[in[0]]]<dep[y[in[0]]]) swap(x[in[0]],y[in[0]]);
		int l=x[in[0]],r=y[in[0]];
		for (i=1;i<in.size();i++)
		{
			if (dep[x[in[i]]]<dep[y[in[i]]]) swap(x[in[i]],y[in[i]]);
			int ll=x[in[i]],rr=y[in[i]];
			l=lca(l,ll);
			if (dep[rr]>dep[r]) swap(r,rr);
			if (!check(rr,r))
			{
				cout<<0;
				return 0;
			}
			if (!check(r,l))
			{
				cout<<0;
				return 0;
			}
		}
		get(l,r);
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for (i=0;i<ans.size();i++) cout<<ans[i]<<' ';
	return 0;
}