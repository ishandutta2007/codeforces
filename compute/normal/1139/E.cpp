#include<bits/stdc++.h>
using namespace std;
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
const int maxn=5005*2;
vector<int> G[maxn],query;
int pot[maxn];
int club[maxn];
bool vis[maxn];
int path[maxn];
int ans[maxn];
bool dfs(int x)
{
	for(auto& p:G[x])
	{
		if(!vis[p])
		{
			vis[p]=1;
			if(!path[p]||dfs(path[p]))
			{
				path[p]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int var=m+1;
	for(int i=1;i<=n;i++)
		scanf("%d",&pot[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&club[i]);
	int d;
	scanf("%d",&d);
	for(int i=1,temp;i<=d;i++)
	{
		scanf("%d",&temp);
		query.push_back(temp);
		vis[temp]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		G[club[i]].push_back(pot[i]+var);
		G[pot[i]+var].push_back(club[i]);
	}
	int match=0;
	memset(vis,0,sizeof(vis));
	while(dfs(match+var))
	{
		memset(vis,0,sizeof(vis));
		match++;
	}
	memset(vis,0,sizeof(vis));
	for(int i=d;i>=1;i--)
	{
		dbg(i);dbg(match);
		int cur=query[i-1];
		G[club[cur]].push_back(pot[cur]+var);
		G[pot[cur]+var].push_back(club[cur]);
		ans[i]=match;
		memset(vis,0,sizeof(vis));
		while(dfs(match+var))
		{
			memset(vis,0,sizeof(vis));
			match++;
		}
	}
	for(int i=1;i<=d;i++)
	{
		printf("%d\n",ans[i]);
	}

}