#include<bits/stdc++.h>
#define MaxN 200123
typedef long long LL;
const LL Mod=998244353;
int n;
std::vector<int>G[MaxN];
LL fac[MaxN];
inline void Init()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	fac[0]=1;
	for(int i=1;i<=n;++i)
	fac[i]=fac[i-1]*i%Mod;
}
LL f[MaxN];
inline void Dfs(int u,int fa)
{
	f[u]=1;
	int cnt=0;
	for(auto v:G[u])
	if(v!=fa)
	{
		Dfs(v,u);
		++cnt;
		f[u]=f[u]*f[v]%Mod;
	}
	if(u!=1)f[u]=f[u]*fac[cnt+1]%Mod;
	else f[u]=f[u]*fac[cnt]%Mod*n%Mod;
}
int main()
{
	Init();
	Dfs(1,0);
	printf("%lld\n",f[1]);
	return 0;
}