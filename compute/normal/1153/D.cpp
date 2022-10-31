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
const int maxn=3e5+7;
int idx[maxn];
vector<int> G[maxn];
int dp[maxn];
int k;
int dfs1(int u)
{
	if(!G[u].size())
	{
		dp[u]=1;
		k++;
		return 1;
	}
	for(auto v:G[u]) dp[u]+=dfs1(v);
	return dp[u];
}
int dfs(int u)
{
	if(!G[u].size())
		return k;
	vector<int> son;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		son.push_back(dfs(v));
	}
	sort(son.begin(),son.end());
	if(idx[u]==1)
		return son[son.size()-1];
	else{
		int ret=k;
		for(auto p:son) ret-=(k-p+1);
		return ret+1;
	}
}
int main()
{
	int n;
	k=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&idx[i]);
	for(int i=2;i<=n;i++)
	{
		int fa;
		scanf("%d",&fa);
		G[fa].push_back(i);
	}
	dfs1(1);
	cout<<dfs(1)<<endl;
}