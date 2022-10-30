#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
const int mod=998244353;
const int INF=0x3f3f3f3f;
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
const int maxn=1e6+7;
#define mid (L+R>>1)
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
vector<int> used;
ll sum[maxn<<2];
int lz[maxn<<2];
int mx[maxn<<2];
int mi[maxn<<2];
int n,w;
inline void pushup(int o)
{
	mx[o]=max(mx[lson],mx[rson]);
	mi[o]=min(mi[lson],mi[rson]);
}
bool vis[maxn<<2];
inline void use(int o)
{
	if(!vis[o]) used.push_back(o);
	vis[o]=1;
}
inline void pushdown(int o)
{
	if(lz[o]!=-INF)
	{
		lz[lson]=max(lz[lson],lz[o]);
		lz[rson]=max(lz[rson],lz[o]);
		mi[lson]=max(mi[lson],lz[o]);
		mi[rson]=max(mi[rson],lz[o]);
		mx[lson]=max(mx[lson],lz[o]);
		mx[rson]=max(mx[rson],lz[o]);
		use(lson);use(rson);
		lz[o]=-INF;
	}
}
void update(int l,int r,int val,int L=1,int R=w,int o=1)
{
	if(mi[o]>=val) return;
	use(o);
	if(l<=L&&r>=R)
	{
		lz[o]=max(lz[o],val);
		mx[o]=max(mx[o],val);
		mi[o]=max(mi[o],val);
		return;
	}
	pushdown(o);
	if(l<=mid) update(l,r,val,Lson);
	if(r>mid) update(l,r,val,Rson);
	pushup(o);
}
void solve(int L=1,int R=w,int o=1)
{
	if(mi[o]==mx[o])
	{
		sum[o]+=mx[o];
		return;
	}
	pushdown(o);
	solve(Lson);
	solve(Rson);
}
ll query(int p,int L=1,int R=w,int o=1)
{
	if(L==R)
		return sum[o];
	ll ret=sum[o];
	if(p<=mid) ret+=query(p,Lson);
	else ret+=query(p,Rson);
	return ret;
}
int main()
{
	scanf("%d%d",&n,&w);
	for(int i=1;i<=(w<<2);i++) mx[i]=mi[i]=lz[i]=-INF;
	for(int i=1;i<=n;i++)
	{
		int v;
		scanf("%d",&v);
		for(int j=1,tmp;j<=v;j++)
		{
			scanf("%d",&tmp);
			update(j,w-v+j,tmp);
		}
		if(v!=w)
		{
			update(1,w-v,0);
			update(v+1,w,0);
		}
		solve();
		for(auto u:used)
			mx[u]=mi[u]=lz[u]=-INF,vis[u]=0;
		used.clear();
	}
	for(int i=1;i<=w;i++)
		printf("%lld%c",query(i),i==w?'\n':' ');
}