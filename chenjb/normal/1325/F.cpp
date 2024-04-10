#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>
#define mp make_pair
#define pb push_back
#define left lef
#define right righ
#define rep(i,n) for(int i=1;i<=n;++i)
#define MAXN 200010
using namespace std;
int n,m,need;
vector<int> g[MAXN];
vector<int> col[MAXN];
int c[MAXN],maxcol=0;
void dfs(int x)
{
	static set<int> dic;
	dic.clear();
	for(auto p:g[x])
		if (c[p]!=-1)dic.insert(c[p]);
	c[x]=0;
	while (dic.find(c[x])!=dic.end())c[x]++;
	col[c[x]].pb(x); maxcol=max(maxcol,c[x]);
	for(auto p:g[x])
		if (c[p]==-1)dfs(p);
}
void tryindependent()
{
	for(int i=0;i<=maxcol;i++)
		if (col[i].size()>=need)
		{
			puts("1");
			for(int j=0;j<need;j++)
				printf("%d ",col[i][j]);
			puts("");
			exit(0);
		}
}
int q[MAXN];
void dfs(int x,int st)
{
	//cout<<x<<endl;
	q[c[x]]=x;
	if (c[x]==0)
	{
		int flag=0;
		for(auto p:g[x])
			if (p==st)flag=1;
		if (!flag)return;
		puts("2");
		cout<<c[st]+1<<endl;
		for(int i=0;i<=c[st];i++)printf("%d ",q[i]);
		puts("");
		exit(0);
	}
	for(auto p:g[x])
		if (c[p]==c[x]-1)dfs(p,st);
}
void trycycle()
{
	for(int i=1;i<=n;i++)
		if (c[i]==maxcol)dfs(i,i);
	for(int i=1;i<=n;i++)
		if (c[i]==need-1)dfs(i,i);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].pb(y);
		g[y].pb(x);
	}
	need=ceil(sqrt(n));
	//cout<<need<<endl;
	memset(c,255,sizeof(c));
	for(int i=1;i<=n;i++)
		if (c[i]==-1)dfs(i);
	//for(int i=1;i<=n;i++)cout<<c[i]<<" "; puts("");
	tryindependent();
	trycycle();
	assert(0);
	return 0;
}