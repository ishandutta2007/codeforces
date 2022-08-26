#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<deque>
#include<set>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,dep[100005],fa[100005][25],ans,x,y,fi[100005],mp[100005],ti,t;
vector<int> bi[100005];
set<int> in;
void dfs(int x,int fath)
{
	fa[x][0]=fath;
	int i;
	for (i=0;i<bi[x].size();i++)
	{
		if (bi[x][i]==fath) continue;
		dep[bi[x][i]]=dep[x]+1;
		dfs(bi[x][i],x);
	}
}
void dfs2(int x,int fath)
{
	fi[x]=++ti;
	mp[ti]=x;
	int i;
	for (i=0;i<bi[x].size();i++)
	{
		if (bi[x][i]==fath) continue;
		dfs2(bi[x][i],x);
	}
}
int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	int i,d=dep[x]-dep[y];
	if (x==y) return x;
	for (i=0;i<=20;i++)
	{
		if ((1<<i)&d) x=fa[x][i];
	}
	if (x==y) return x;
	for (i=20;i>-1;i--)
	{
		if (fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
int add(int x)
{
	if (!in.size()) return 1;
	set<int>::iterator it=in.lower_bound(fi[x]);
	int y,z;
	if (it==in.end()) it=in.begin();
	y=mp[*it];
	if (it==in.begin()) it=in.end();
	it--;
	z=mp[*it];
	return dep[x]+dep[lca(y,z)]-dep[lca(y,x)]-dep[lca(z,x)];
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	//m--;
	for (i=1;i<n;i++)
	{
		cin>>x>>y;
		bi[x].push_back(y);
		bi[y].push_back(x);
	}
	dep[1]=0;
	fa[1][0]=1;
	dfs(1,0);
	for (i=1;i<=20;i++)
	{
		for (j=1;j<=n;j++)
		{
			fa[j][i]=fa[fa[j][i-1]][i-1];
		}
	}
	dfs2(1,0);
	j=0;
//	in.insert(fi[1]);
	for (i=1;i<=n;i++)
	{
		if (j<n) t=add(j+1);
		while (j<n&&m>=t)
		{
			m-=t;
			j++;
			in.insert(fi[j]);
			if (j-i+1>ans)
			{
				ans=j-i+1;
			}
			if (j<n) t=add(j+1);
		}
		in.erase(fi[i]);
		//m+=del(i);
		m+=add(i);
	}
	cout<<ans;
	return 0;
}