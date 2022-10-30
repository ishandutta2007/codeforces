#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
ll quick(ll a,ll b,ll mod)
{
	ll ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a,ll mod){return quick(a,mod-2,mod);}
const int maxn=2e5+7;
int sz[maxn];
int fa[maxn];
ll ans=0;
inline ll C2(ll x)
{
	return x*(x-1)/2;
}
void init()
{
	for(int i=0;i<maxn;i++) fa[i]=i,sz[i]=1;
}
int Find(int x)
{
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
	x=Find(x),y=Find(y);
	if(x==y) return;
	ans-=C2(sz[x]),ans-=C2(sz[y]);
	sz[x]+=sz[y];
	ans+=C2(sz[x]);
	dbg(x,y,ans,sz[x]);
	fa[y]=x;
}
int tot;
struct Edge{
	int u,v,w,tp;
	bool operator<(const Edge& a)const{
		if(w==a.w) return tp<a.tp;
		return w<a.w;
	}
}e[maxn*2];
ll op[maxn];
int main()
{
	init();
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		e[tot++]={u,v,w,0};
	}
	for(int i=0;i<m;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		e[tot++]={0,0,tmp,i+1};
	}
	sort(e,e+tot);
	for(int i=0;i<tot;i++)
	{
		if(e[i].tp==0)
			Union(e[i].u,e[i].v);
		else{
			op[e[i].tp]=ans;
		}
	}
	for(int i=1;i<=m;i++)
		printf("%lld%c",op[i],i==m?'\n':' ');
}