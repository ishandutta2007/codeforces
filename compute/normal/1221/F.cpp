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
const int maxn=1e6+7;
vector<int> all;
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
int x[maxn],y[maxn],w[maxn];
inline int  getid(int x)
{
	return lower_bound(all.begin(),all.end(),x)-all.begin();
}
int len;
ll mx[maxn<<2];
ll pp[maxn<<2];
ll lz[maxn<<2];
inline void pushdown(int o)
{
	if(lz[o])
	{
		mx[lson]+=lz[o];
		mx[rson]+=lz[o];
		lz[lson]+=lz[o];
		lz[rson]+=lz[o];
		lz[o]=0;
	}
}
inline void pushup(int o)
{
	if(mx[lson]<mx[rson])
	{
		mx[o]=mx[lson];
		pp[o]=pp[lson];
	}
	else{
		mx[o]=mx[rson];
		pp[o]=pp[rson];
	}
}
void build(int L=0,int R=len,int o=1)
{
	if(L==R)
	{
		mx[o]=0;
		pp[o]=L;
		return;
	}
	int mid=L+R>>1;
	build(Lson);
	build(Rson);
	pushup(o);
}
void update(int l,int r,int val,int L=0,int R=len,int o=1)
{
	if(l<=L&&r>=R)
	{
		lz[o]+=val;
		mx[o]+=val;
		return;
	}
	pushdown(o);
	int mid=L+R>>1;
	if(l<=mid) update(l,r,val,Lson);
	if(r>mid) update(l,r,val,Rson);
	pushup(o);
}
pair<ll,int> query(int l,int r,int L=0,int R=len,int o=1)
{
	if(l<=L&&r>=R)
		return make_pair(mx[o],pp[o]);
	pushdown(o);
	int mid=L+R>>1;
	pair<ll,int> ret=make_pair(0x3f3f3f3f3f3f3f3f,-1);
	if(l<=mid) 
	{
		auto cur=query(l,r,Lson);
		if(ret.first>cur.first) ret=cur;
	}
	if(r>mid) 
	{
		auto cur=query(l,r,Rson);
		if(ret.first>cur.first) ret=cur;
	}
	return ret;
}
vector<PII> db[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&w[i]);
		all.push_back(x[i]);
		all.push_back(y[i]);
	}
	all.push_back(0);
	all.push_back(0x3f3f3f3f);
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	len=all.size()-1;
	build();
	for(int i=0;i<n;i++)
	{
		x[i]=getid(x[i]);
		y[i]=getid(y[i]);
		int t=max(x[i],y[i]);
		db[t].push_back(make_pair(w[i],min(x[i],y[i])));
	}
	ll cur=0;
	ll ans=0;
	PII op=make_pair(len,len);
	for(int i=0;i<len;i++)
	{
		for(auto u:db[i])
		{
			cur+=u.first;
			update(u.second,len,u.first);
		}
		auto qans=query(0,i);
		ll curans=cur-qans.first-all[i];
		dbg(qans.first,qans.second,all[i],cur,curans);
		if(ans<curans)
		{
			ans=curans;
			op=make_pair(qans.second+1,i);
		}
		if(ans<cur-all[i])
		{
			ans=cur-all[i];
			op=make_pair(0,i);
		}
		update(i,len,all[i]-all[i+1]);
	}
	printf("%lld\n",ans);
	printf("%d %d %d %d\n",all[op.first],all[op.first],all[op.second],all[op.second]);
}