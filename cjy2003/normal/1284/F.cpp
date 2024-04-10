#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
namespace dsu
{
	int f[250050];
	int find(int x)
	{
		if(x!=f[x])return f[x]=find(f[x]);
		return x;
	}
}
vector<int>E1[250050],E2[250050];
int n,f[250050],up[250050][18],dep[250050],d[250050];
bool vis[250050];
queue<int>q;
void dfs(int v,int fa)
{
	up[v][0]=fa;dep[v]=dep[fa]+1;
	for(int i=1;i<=17;++i)up[v][i]=up[up[v][i-1]][i-1];
	for(auto u:E1[v])if(u!=fa)dfs(u,v);
}
int qlca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	int dt=dep[x]-dep[y];
	for(int i=0;i<=17;++i)if(dt>>i&1)x=up[x][i];
	if(x==y)return x;
	for(int i=17;~i;--i)if(up[x][i]!=up[y][i])x=up[x][i],y=up[y][i];
	return up[x][0];
}
int main()
{
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<n;++i)
	{
		scanf("%d %d",&x,&y);
		E1[x].emplace_back(y);
		E1[y].emplace_back(x);
	}
	for(int i=1;i<n;++i)
	{
		scanf("%d %d",&x,&y);
		E2[x].emplace_back(y);++d[x];
		E2[y].emplace_back(x);++d[y];
	}
	printf("%d\n",n-1);
	dfs(1,0);
	for(int i=1;i<=n;++i)dsu::f[i]=i;
	for(int i=1;i<=n;++i)if(d[i]==1)q.push(i);
	while(q.size()>1)
	{
		x=q.front();q.pop();vis[x]=1;
		for(auto u:E2[x])
			if(!vis[u])
			{
				y=u,--d[y];
				if(d[y]==1)q.push(y);
				break;
			}
		int l=qlca(x,y);
		int a=dsu::find(x),b;
		if(dep[a]>dep[l])
		{
			printf("%d %d %d %d\n",a,up[a][0],x,y);
			dsu::f[a]=dsu::find(up[a][0]);
		}
		else
		{
			b=y;
			for(int i=17;~i;--i)if(dep[up[b][i]]>dep[l]&&dsu::find(up[b][i])!=a)b=up[b][i];
			printf("%d %d %d %d\n",b,up[b][0],x,y);
			dsu::f[b]=a;
		}
	}
	return 0;
}