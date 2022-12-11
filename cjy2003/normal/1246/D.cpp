#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,dep[100010],d,f[100010],zson[100010],nxt[100010],ans[100010],cnt;
vector<int>E[100010];
bool vis[100010];
void dfs(int v)
{
	dep[v]=dep[f[v]]+1;
	if(dep[v]>dep[d])d=v;
	for(auto u:E[v])dfs(u);
}
void dfs1(int v)
{
	for(auto u:E[v])
		if(!vis[u])ans[++cnt]=nxt[u]=nxt[v],nxt[v]=u,dfs1(u);
}
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;++i)
	{
		scanf("%d",&f[i]);++f[i];
		E[f[i]].push_back(i);
	}
	dfs(1);
	int x=d;
	while(x)vis[x]=1,nxt[f[x]]=x,x=f[x];
	while(d)dfs1(d),d=f[d];
	x=1;
	for(int i=1;i<=n;++i)printf("%d ",x-1),x=nxt[x];printf("\n");
	printf("%d\n",cnt);
	for(int i=cnt;i;--i)printf("%d ",ans[i]-1);
	return 0;
}