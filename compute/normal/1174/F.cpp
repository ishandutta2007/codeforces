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
const int INF=0x3f3f3f3f;
vector<int> G[maxn];
int askdis(int x)
{
	cout<<'d'<<" "<<x<<endl;
	int ret;
	cin>>ret;
	return ret;
}
int askson(int x)
{
	cout<<'s'<<" "<<x<<endl;
	int ret;
	cin>>ret;
	return ret;
}
void answer(int x)
{
	cout<<"! "<<x<<endl;
}
int sz[maxn],maxson[maxn],rt,treesz;
int dep[maxn],far[maxn];
bool vis[maxn];
void dfs(int u,int fa=-1)
{
	far[u]=fa;
	for(auto& v:G[u])if(v!=fa)
	{
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}
void dfsrt(int u,int fa=-1)
{
	sz[u]=1;maxson[u]=0;
	for(auto& v:G[u])if(v!=fa&&!vis[v])
	{
		dfsrt(v,u);
		sz[u]+=sz[v];
		maxson[u]=max(maxson[u],sz[v]);
	}
	maxson[u]=max(maxson[u],treesz-sz[u]);
	if(maxson[rt]>maxson[u]) rt=u;
}
int getsz(int u,int fa=-1)
{
	int ret=1;
	for(auto& v:G[u])if(fa!=v&&!vis[v])
	{
		ret+=getsz(v,u);
	}
	return ret;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1,u,v;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dep[1]=0;
	dfs(1);
	treesz=n;
	int dis=askdis(1);
	int cur=1;
	while(treesz!=1&&dis)
	{
		rt=0;
		maxson[rt]=INF;
		dfsrt(cur);
		vis[rt]=1;
		int dd=askdis(rt);
		if(!dd){
			cur=rt;
			break;
		}
		if(dd+dep[rt]==dis)
		{
			cur=askson(rt);
			treesz=getsz(cur);
		}
		else {
			cur=far[rt];
			treesz=getsz(cur);
		}
		dbg(rt,cur,treesz);
	}
	answer(cur);
}