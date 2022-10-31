#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[33;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int mod=1e9+7;
const int maxn=1e5+7;
bool vis[maxn];
vector<int> G[maxn];
int dfs(int u,int fa)
{
	vis[u]=1;
	int ret=1;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa) continue;
		if(vis[v]) continue;
		ret+=dfs(v,u);
	}
	return ret;
}
long long quick(long long a,long long b)
{
	long long ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0,u,v,tp;i<n-1;i++)
	{
		scanf("%d%d%d",&u,&v,&tp);
		if(tp) continue;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	long long tot=quick(n,k);
	long long ans=tot;
	for(int i=1;i<=n;i++)
	{
		int cnt;
		if(!vis[i])
		{
			cnt=dfs(i,-1);
			ans=(ans-quick(cnt,k)+mod)%mod;
		}
	}
	printf("%lld\n",ans);
}