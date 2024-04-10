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
int fa[maxn],sz[maxn];
void init(int n)
{
	for(int i=0;i<=n;i++) fa[i]=i,sz[i]=1;
}
int Find(int x)
{
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
	x=Find(x),y=Find(y);
	if(x!=y)
	{
		fa[y]=x;
		sz[x]+=sz[y];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin>>q;
	while(q--)
	{
		int n;
		cin>>n;
		init(n);
		for(int i=1;i<=n;i++)
		{
			int a;
			cin>>a;
			Union(a,i);
		}
		for(int i=1;i<=n;i++)
			cout<<sz[Find(i)]<<" ";
		cout<<'\n';

	}
	
}