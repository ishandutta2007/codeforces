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
const int maxn=1e5+7;
vector<int> G[maxn];
double dp[maxn];
double dfs(int u,int fa=-1)
{
	if(dp[u]>0) return dp[u];
	dp[u]=0;
	int cnt=0;
	for(auto v:G[u])
	{
		if(fa==v) continue;
		cnt++;
		dp[u]+=dfs(v,u);
	}
	if(!cnt) return 0;
	return dp[u]=dp[u]/cnt+1;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	int n;
	scanf("%d",&n);
	for(int i=0,u,v;i<n-1;i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	printf("%.10f\n",dp[1]);
}