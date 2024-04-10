#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
vector<int> g[1100];
vector<pair<int,int> > center;
int n,m;
int dep[1100],fa[1100],v[1100];
int q[1100],tot;
void dfs(int x,int pre)
{
	q[++tot]=x;
	v[x]=1;
	for(auto p:g[x])
		if (p!=pre)
		{
			dep[p]=dep[x]+1;
			fa[p]=x;
			dfs(p,x);
		}
}
int get(int rt)
{
	tot=0; dep[rt]=1; dfs(rt,0);
	int st=q[1];
	for(int i=1;i<=tot;i++)if (dep[st]<dep[q[i]])st=q[i];

	tot=0; dep[st]=1; dfs(st,0);
	int ed=q[1];
	for(int i=1;i<=tot;i++)if (dep[ed]<dep[q[i]])ed=q[i];
	int mid=(dep[ed]-dep[st])/2;
	int t=ed; rep(i,mid)t=fa[t];
	center.pb(mp(dep[ed]-dep[st],t));

	//cout<<center.back().first<<"/"<<center.back().second<<endl;
	return dep[ed]-dep[st];
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].pb(y);
		g[y].pb(x);
	}
	for(int i=1;i<=n;i++)v[i]=0;

	center.clear();
	for(int i=1;i<=n;i++)
		if (!v[i])get(i);

	sort(center.begin(),center.end());
	reverse(center.begin(),center.end());
	for(int i=1;i<center.size();i++)
	{
		g[center[0].second].pb(center[i].second);
		g[center[i].second].pb(center[0].second);
	}

	//cout<<center.size()<<endl;
	
	cout<<get(1)<<endl;
	for(int i=1;i<center.size()-1;i++)
		printf("%d %d\n",center[0].second,center[i].second);
	
}