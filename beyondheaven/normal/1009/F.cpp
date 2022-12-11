#include<bits/stdc++.h>
#define MaxN 1000123
int n;

char buf[1<<21],*p1,*p2;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
template<typename T>
inline void read(T&x)
{
	x=0;int ch=getchar();
	while(ch<48||ch>57)ch=getchar();
	while(ch>47&&ch<58)x=10*x+(ch-48),ch=getchar();
}

std::vector<int>G[MaxN];
int dis[MaxN],son[MaxN];
int*dp[MaxN];

inline int*new_node(int l)
{
	static int pool[MaxN],*p=pool;
	return (p+=l)-l;
}

inline void Dfs1(int u,int f)
{
	dis[u]=1;
	for(int v:G[u])
	if(v!=f)
	{
		Dfs1(v,u);
		dis[u]=std::max(dis[u],dis[v]+1);
		if(dis[v]>dis[son[u]])
		son[u]=v;
	}
}

int ans[MaxN];

inline void Dfs2(int u,int*p)
{
	#ifdef Dubug
	printf("Dfs2(%d)\n",u);
	#endif
	dp[u]=p;
	dp[u][0]=1;
	if(son[u])
	{
		Dfs2(son[u],p+1);
		ans[u]=ans[son[u]]+1; 
	}
	for(int v:G[u])
	if(dp[v]==nullptr)
	{
		Dfs2(v,new_node(dis[v]));
		for(int i=1;i<=dis[v];++i)
		{
			dp[u][i]+=dp[v][i-1];
			if(dp[u][i]>dp[u][ans[u]])ans[u]=i;
			else if(dp[u][i]==dp[u][ans[u]])ans[u]=std::min(ans[u],i);
		}
	}
	if(dp[u][ans[u]]==1)ans[u]=0;
}

inline void Init()
{
	read(n);
	for(int i=1,u,v;i<n;++i)
	{
		read(u);read(v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
}

int main()
{
	Init();
	Dfs1(1,0);
	Dfs2(1,new_node(dis[1]));
	for(int i=1;i<=n;++i)
	printf("%d\n",ans[i]);
	return 0;
}