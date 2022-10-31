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
struct ed{
	int u,v,w;
	bool operator<(const ed&a)const{
		return w>a.w;
	}
}edge[maxn];
int deg[maxn];
vector<ed> ans;
int far[maxn];
int n,m;
void init()
{
	for(int i=0;i<maxn;i++) far[i]=i;
}
int Find(int x)
{
	return x==far[x]?x:far[x]=Find(far[x]);
}
void Union(int x,int y)
{
	x=Find(x),y=Find(y);
	far[y]=x;
}
void kruskal()
{
	sort(edge,edge+m);
	for(int i=0;i<m;i++)
	{
		if(Find(edge[i].u)==Find(edge[i].v)) continue;
		Union(edge[i].u,edge[i].v);
		ans.push_back(edge[i]);
	}
}
int main()
{
	init();
	scanf("%d%d",&n,&m);
	for(int i=0,u,v;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		edge[i].u=u;edge[i].v=v;
		deg[u]++;
		deg[v]++;
	}
	int ct=0;
	int ma=0;
	for(int i=1;i<=n;i++)
	{
		if(deg[i]>ma)
		{
			ma=deg[i];
			ct=i;
		}
	}
	for(int i=0;i<m;i++)
	{
		edge[i].w=max(deg[edge[i].v],deg[edge[i].u]);
		if(edge[i].v==ct||edge[i].u==ct) edge[i].w=0x3f3f3f3f;
	}
	kruskal();
	for(int i=0;i<ans.size();i++)
	{
		printf("%d %d\n",ans[i].u,ans[i].v);
	}
}