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
int far[maxn][2];
int cnt[maxn][2];
void init()
{
	for(int i=0;i<maxn;i++) far[i][0]=far[i][1]=i,cnt[i][0]=cnt[i][1]=1;
}
int Find(int x,int type)
{
	return far[x][type]==x?x:far[x][type]=Find(far[x][type],type);
}
void Union(int x,int y,int type)
{
	x=Find(x,type),y=Find(y,type);
	if(x==y) return;
	cnt[x][type]+=cnt[y][type];
	far[y][type]=far[x][type];
}
int main()
{
	init();
	int n;
	ll ans=0;
	scanf("%d",&n);
	for(int i=1,u,v,ty;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&ty);
		Union(u,v,ty);
	}
	for(int i=1;i<=n;i++)
	{
		int far0=Find(i,0),far1=Find(i,1);
		if(far0==i) ans+=1LL*cnt[i][0]*(cnt[i][0]-1);
		if(far1==i) ans+=1LL*cnt[i][1]*(cnt[i][1]-1);
		ans+=1LL*(cnt[far0][0]-1)*(cnt[far1][1]-1);
	}
	printf("%lld\n",ans);
}