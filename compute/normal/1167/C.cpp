#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int maxn=5e5+7;
int fa[maxn];
int cnt[maxn];
void init()
{
	for(int i=0;i<maxn;i++) fa[i]=i,cnt[i]=1;
}
int Find(int x)
{
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
	x=Find(x);y=Find(y);
	if(x==y) return;
	cnt[x]+=cnt[y];
	fa[y]=x;
}
int main()
{
	init();
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int k;
		scanf("%d",&k);
		int pre=0;
		for(int j=0,tmp;j<k;j++)
		{
			scanf("%d",&tmp);
			if(j) Union(tmp,pre);
			pre=tmp;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",cnt[Find(i)]);
	puts("");
}