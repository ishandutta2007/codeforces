#include<cstdio>
#include<algorithm>
#include<vector>
#define MaxN 2123
int n,rt;
struct Edge{int v,next;}edge[MaxN];
int head[MaxN],num_edge;
inline void add_edge(int u,int v)
{
	edge[++num_edge].v=v;
	edge[num_edge].next=head[u];
	head[u]=num_edge;
}
int a[MaxN],c[MaxN];
inline void Init()
{
	scanf("%d",&n);
	for(int i=1,p;i<=n;++i)
	{
		scanf("%d%d",&p,c+i);
		if(p)add_edge(p,i);
		else rt=i;
	}
}
int size[MaxN];
inline void Dfs1(int u)
{
	size[u]=1;
	for(int i=head[u];i;i=edge[i].next)
	Dfs1(edge[i].v),size[u]+=size[edge[i].v];
}
std::vector<int>l;
inline void Dfs2(int u)
{
	l.push_back(a[u]);
	for(int i=head[u];i;i=edge[i].next)
	Dfs2(edge[i].v);
}
inline void Attend(int u)
{
	l.clear();
	for(int i=head[u];i;i=edge[i].next)
	Dfs2(edge[i].v);
}
inline void Dfs3(int u,int p)
{
	if(a[u]>=p)++a[u];
	for(int i=head[u];i;i=edge[i].next)
	Dfs3(edge[i].v,p);
}
inline void Modify(int u,int p)
{
	for(int i=head[u];i;i=edge[i].next)
	Dfs3(edge[i].v,p);
}
bool vis[MaxN];
inline void Dfs4(int u)
{
	vis[a[u]]=1;
	for(int i=head[u];i;i=edge[i].next)
	Dfs4(edge[i].v);
}
inline int Get()
{
	for(int i=1;i<=n;++i)vis[i]=0;
	Dfs4(rt);
	for(int i=1;i<=n;++i)
	if(!vis[i])return i;
	return -1;
}
inline void Dfs(int u)
{
	for(int i=head[u];i;i=edge[i].next)
	Dfs(edge[i].v);
	Attend(u);
	if(c[u]==l.size())a[u]=Get();
	else
	{
		std::sort(l.begin(),l.end());
		a[u]=l[c[u]];
	}
	Modify(u,a[u]);
}
inline void Solve()
{
	Dfs1(rt);
	for(int u=1;u<=n;++u)
	if(c[u]>=size[u])
	{
		puts("NO");
		return;
	}
	puts("YES");
	Dfs(rt);
	for(int i=1;i<=n;++i)
	printf("%d ",a[i]);
	puts("");
}
int main()
{
	Init();
	Solve();
	return 0;
}