#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int maxn=2e5+7;
vector<int> G[maxn];
int sz[maxn];
ll ans;
int n;
int dfs(int u,int fa=-1)
{
	sz[u]=1;
	for(auto v:G[u])
	{
		if(v==fa) continue;
		sz[u]+=dfs(v,u);
	}
	ans+=sz[u];
	return sz[u];
}
void dfs2(int u,int fa,ll cur)
{
	ans=max(ans,cur);
	for(auto v:G[u])
	{
		if(v==fa) continue;
		dfs2(v,u,cur+(n-2*sz[v]));
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	dfs2(1,-1,ans);
	printf("%lld\n",ans);
}