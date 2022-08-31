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
int n,m,i,j,deg[500005],x,y,vis[500005];
vector<int> bi[500005],seq;
void dfs2(int x,int fa)
{
	int i;
	vis[x]=1;
	seq.push_back(x);
	for (i=0;i<bi[x].size();i++)
	{
		if (bi[x][i]==fa) continue;
		if (vis[bi[x][i]]) continue;
		dfs2(bi[x][i],x);
	}
}
void dfs(int x,int fa)
{
	int i;
	for (i=0;i<bi[x].size();i++)
	{
		if (bi[x][i]==fa) continue;
		if (vis[bi[x][i]]) continue;
		dfs(bi[x][i],x);
	}
	if (deg[x]%2==0)
	{
		deg[fa]--;
		vis[x]=1;
		seq.push_back(x);
		for (i=0;i<bi[x].size();i++)
		{
			if (bi[x][i]==fa) continue;
			if (vis[bi[x][i]]) continue;
			dfs2(bi[x][i],x);
		}
	}
}
int main()
{
	scanf("%d",&n);
	if (n%2==0)
	{
		printf("NO\n");
		return 0;
	}
	for (i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if (x==0) continue;
		bi[x].push_back(i);
		bi[i].push_back(x);
		deg[x]++;
		deg[i]++;
	}
	dfs(1,0);
	if (seq.size()<n)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for (i=0;i<seq.size();i++) printf("%d\n",seq[i]);
	return 0;
}