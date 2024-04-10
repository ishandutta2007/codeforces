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
const int maxn=5005;
struct Edge{
	int to,id;
};
int ans[maxn];
vector<Edge> G[maxn];
bool vis[maxn];
int mx=1;
bool ins[maxn];
void dfs(int u)
{
	vis[u]=1;
	ins[u]=1;
	for(auto e:G[u])
	{
		int v=e.to;
		if(ins[v])
			ans[e.id]=2,mx=2;
		else if(!vis[v]){
			ans[e.id]=1;
			dfs(v);
		}
		else{
			ans[e.id]=1;
		}
	}
	ins[u]=0;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back({v,i});
	}
	for(int i=1;i<=n;i++)if(!vis[i])
		dfs(i);
	printf("%d\n",mx);
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	puts("");
}