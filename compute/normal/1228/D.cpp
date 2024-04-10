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
int col[maxn];
vector<int> G[maxn];
bool vis[maxn];
int cnt[maxn];
int n,m;
vector<int> s1,s2;
bool ok;
void solve1()
{
	col[1]=1;
	s1.push_back(1);
	vis[1]=1;
	for(auto u:G[1]) 
	{
		vis[u]=1;
		cnt[u]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			col[i]=1;
			s1.push_back(i);
			for(auto v:G[i])
			{
				if(!vis[v]) ok=0;
				cnt[v]++;
			}
		}
	}
	for(int i=1;i<=n;++i) if(!col[i]&&cnt[i]!=s1.size()) ok=0;
}
void solve2()
{
	memset(cnt,0,sizeof(cnt));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		if(!col[i])
		{
			col[i]=2;
			s2.push_back(i);
			vis[i]=1;
			break;
		}
	dbg(s2);
	if(!s2.size())
	{
		ok=0;
		return;
	}
	for(auto u:G[s2[0]])if(!col[u])
		vis[u]=1,cnt[u]++;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]&&!col[i])
		{
			col[i]=2;
			s2.push_back(i);
			for(auto v:G[i])
			{
				if(!col[v]&&!vis[v]) ok=0;
				cnt[v]++;
			}
		}
	}
	for(int i=1;i<=n;++i) if(!col[i]&&cnt[i]!=s2.size()) ok=0;
	if(s2.size()+s1.size()==n) ok=0;
}
int main()
{
	ok=1;
	scanf("%d%d",&n,&m);
	for(int i=0,u,v;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	solve1();
	solve2();
	dbg(s2);
	dbg(ok);
	for(int i=1;i<=n;i++) if(!col[i])
	{
		for(auto v:G[i])
			if(!col[v]) 
				ok=0;
	}
	for(int i=1;i<=n;i++) 
		if(!col[i]) col[i]=3;
	if(!ok) puts("-1");
	else{
		for(int i=1;i<=n;i++)
			printf("%d%c",col[i],i==n?'\n':' ');
	}
}