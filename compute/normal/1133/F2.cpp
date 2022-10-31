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
const int maxn=2e5+7;
vector<int> G[maxn];
bool vis[maxn];
int cnt=0;
int ans[maxn];
void dfs(int u)
{
	vis[u]=1;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(vis[v]) continue;
		if(u==1) cnt++;
		ans[v]=u;
		dfs(v);
	}
}
int main()
{
	int n,m,d;
	memset(vis,0,sizeof(vis));
	scanf("%d%d%d",&n,&m,&d);
	for(int i=0,u,v;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(G[1].size()<d) puts("NO");
	else{
		dfs(1);
		if(cnt>d)
			puts("NO");
		else{
			for(int i=0;i<G[1].size();i++)
			{
				if(cnt==d) break;
				if(ans[G[1][i]]!=1)
				{
					ans[G[1][i]]=1;
					cnt++;
				}
			}
			puts("YES");
			for(int i=2;i<=n;i++)
			{
				printf("%d %d\n",i,ans[i]);
			}
		}

	}
}