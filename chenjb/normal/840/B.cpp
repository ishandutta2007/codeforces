#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <utility>
#define LL long long
using namespace std;
int n,m;
vector< pair<int,int> > g[400000];
int d[400000];
int v[400000],used[400000],ans[400000];
int fy,zero,one,root;
void dfs(int x)
{
	v[x]=1;
	int cnt=g[x].size();
	for(int i=0;i<cnt;i++)
		if (!v[g[x][i].first])
		{
			dfs(g[x][i].first);
			if (d[g[x][i].first]==1)
			{
				used[g[x][i].second]=1;
				if (d[x]!=-1)d[x]^=1;
			}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	fy=0; zero=0; one=0;
	root=1;
	for(int i=1;i<=n;i++)
		{
			scanf("%d",&d[i]);
			if (d[i]==-1)root=i,fy++,d[i]=0;
			if (d[i]==0)zero++;
			if (d[i]==1)one++;
		}
	if (fy==0&&one%2==1)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<=m;i++)used[i]=0;
	for(int i=1;i<=n;i++)v[i]=0;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if (x==y)continue;
		g[x].push_back(make_pair(y,i));
		g[y].push_back(make_pair(x,i));
	}
	if (fy>0&&one%2==1)d[root]=1;
	dfs(root);
	int cnt=0;
	for(int i=1;i<=m;i++)if (used[i])ans[++cnt]=i;

	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)printf("%d\n",ans[i]);

	return 0;
}