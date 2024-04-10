#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
ll rand_int(ll l, ll r) //[l, r]
{
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
    print(v[i],i==(int)(v.size())-1?suc:2);
}
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
const int maxn=2e5+7;
int mx[maxn<<2];
ll sum[maxn<<2];
int lz[maxn<<2];
inline void upd(int o,int len,int v)
{
	lz[o]=v;
	mx[o]=v;
	sum[o]=1LL*len*v;
}
inline void pushdown(int o,int L,int R)
{
	if(lz[o])
	{
		int mid=L+R>>1;
		upd(lson,mid-L+1,lz[o]);
		upd(rson,R-mid,lz[o]);
		lz[o]=0;
	}
}
int n;
int a[maxn];
void modify(int l,int r,int v,int L=0,int R=n-1,int o=1)
{
	if(l<=L&&r>=R)
	{
		upd(o,R-L+1,v);
		return;
	}
	pushdown(o,L,R);
	int mid=L+R>>1;
	if(l<=mid) modify(l,r,v,Lson);
	if(r>mid) modify(l,r,v,Rson);
	mx[o]=mx[lson];
	sum[o]=sum[lson]+sum[rson];
}
ll query(int l,int r,int L=0,int R=n-1,int o=1)
{
	if(l<=L&&r>=R)
		return sum[o];
	pushdown(o,L,R);
	int mid=L+R>>1;
	ll ret=0;
	if(l<=mid) ret+=query(l,r,Lson);
	if(r>mid) ret+=query(l,r,Rson);
	return ret;
}
void build(int L=0,int R=n-1,int o=1)
{
	if(L==R)
	{
		mx[o]=sum[o]=a[L];
		return;
	}
	int mid=L+R>>1;
	build(Lson);
	build(Rson);
	mx[o]=mx[lson];
	sum[o]=sum[lson]+sum[rson];
}
int findp(int v,int L=0,int R=n-1,int o=1)
{
	if(L==R) return L-(mx[o]<=v);
	pushdown(o,L,R);
	int mid=L+R>>1;
	if(mx[rson]>=v) return findp(v,Rson);
	return findp(v,Lson);
}
int finds(ll v,int L=0,int R=n-1,int o=1)
{
	if(L==R) return L+(mx[o]<=v);
	pushdown(o,L,R);
	int mid=L+R>>1;
	if(sum[lson]>=v) return finds(v,Lson);
	return finds(v-sum[lson],Rson);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int q;
	cin>>n>>q;
	for(int i=0;i<n;i++) cin>>a[i];
	build();
	while(q--)
	{
		int t,x,y;
		cin>>t>>x>>y;
		x--;
		if(t==1)
		{
			int p=findp(y);
			if(p+1<=x) modify(p+1,x,y);
		}
		else{
			int ans=0;
			while(x<n)
			{
				ll pre=0;
				if(x) pre=query(0,x-1);
				int cp=finds(pre+y);
				cp--;
				if(cp>=x)
				{
					ans+=cp-x+1;
					y-=query(x,cp);
				}
				assert(y>=0);
				x=max(cp+1,findp(y)+1);
			}
			print(ans);
		}
	}
}