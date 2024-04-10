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
const ll INF=0x3f3f3f3f3f3f3f3f;
ll mi[maxn<<2];
ll lz[maxn<<2];
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
inline void pushup(int o)
{
	mi[o]=min(mi[lson],mi[rson]);
}
inline void up(int o,ll val)
{
	lz[o]=min(lz[o],val);
	if(mi[o]>val)
		mi[o]=val;
}
inline void pushdown(int o)
{
	if(lz[o]!=INF)
	{
		up(lson,lz[o]);
		up(rson,lz[o]);
		lz[o]=INF;
	}
}
int n,k;
ll query(int l,int r,int L=0,int R=n,int o=1)
{
	if(l<=L&&r>=R)
		return mi[o];
	ll ret=INF;
	pushdown(o);
	int mid=L+R>>1;
	if(l<=mid)
		ret=min(ret,query(l,r,Lson));
	if(r>mid) ret=min(ret,query(l,r,Rson));
	return ret;
}
void update(int l,int r,ll val,int L=0,int R=n,int o=1)
{
	if(l<=L&&r>=R)
	{
		up(o,val);
		return;
	}
	pushdown(o);
	int mid=L+R>>1;
	if(l<=mid) update(l,r,val,Lson);
	if(r>mid) update(l,r,val,Rson);
	pushup(o);
}
char s[maxn];
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	memset(mi,0x3f,sizeof(mi));
	memset(lz,0x3f,sizeof(lz));
	update(0,0,0);
	for(int i=1;i<=n;i++)
	{
		ll cur=query(i-1,i-1)+i;
		if(s[i]=='0') update(i,i,cur);
		else{
			cur=query(max(0,i-k-1),i-1)+i;
			update(i,min(n,i+k),cur);
		}
		//dbg(query(i,i));
	}
	printf("%lld\n",query(n,n));
}