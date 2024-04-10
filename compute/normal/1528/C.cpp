#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[33;1m " << #x << " -> "; err(x); } while (0)
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
const int maxn=3e5+7;
vi S[maxn],K[maxn];
int st[maxn],ed[maxn];
int tot;
void dfs(int u)
{
	st[u]=++tot;
	for(auto v:K[u])
		dfs(v);
	ed[u]=tot;
}
int val[maxn<<2],lz[maxn<<2];
int n;
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
void build(int L=1,int R=n,int o=1)
{
	val[o]=0;lz[o]=-1;
	if(L==R)
		return;
	int mid=L+R>>1;
	build(Lson);
	build(Rson);
}
inline void pushdown(int o)
{
	if(lz[o]!=-1)
	{
		lz[lson]=lz[o];
		lz[rson]=lz[o];
		val[lson]=lz[o];
		val[rson]=lz[o];
		lz[o]=-1;
	}
}
inline void pushup(int o)
{
	val[o]=max(val[lson],val[rson]);
}
void update(int l,int r,int v,int L=1,int R=n,int o=1)
{
	if(l<=L&&r>=R)
	{
		val[o]=v;
		lz[o]=v;
		return;
	}
	pushdown(o);
	int mid=L+R>>1;
	if(l<=mid) update(l,r,v,Lson);
	if(r>mid) update(l,r,v,Rson);
	pushup(o);
}
int query(int p,int L=1,int R=n,int o=1)
{
	if(L==R)
		return val[o];
	pushdown(o);
	int mid=L+R>>1;
	if(p<=mid) return query(p,Lson);
	return query(p,Rson);
}
int qmax(int l,int r,int L=1,int R=n,int o=1)
{
	if(l<=L&&r>=R)
		return val[o];
	int mid=L+R>>1;
	pushdown(o);
	int ret=0;
	if(l<=mid) ret=max(ret,qmax(l,r,Lson));
	if(r>mid)  ret=max(ret,qmax(l,r,Rson));
	return ret;
}
int cnt,ans;
void findans(int u)
{
	int tar=query(st[u]);
	int ason=qmax(st[u],ed[u]);
	//dbg(u,tar,ason);
	if(tar)
	{
		update(st[tar],ed[tar],0);
		update(st[u],ed[u],u);
	}
	else{
		if(!ason)
		{
			cnt++;
			update(st[u],ed[u],u);
		}
	}
	ans=max(ans,cnt);
	for(auto v:S[u])
		findans(v);
	if(tar)
		update(st[tar],ed[tar],tar);
	else{
		if(!ason)
		{
			cnt--;
			update(st[u],ed[u],0);
		}
	}
}
void solve()
{
	tot=cnt=ans=0;
	cin>>n;
	build();
	for(int i=0;i<=n;i++)
	{
		S[i].clear();
		K[i].clear();
	}
	for(int i=2;i<=n;i++)
	{
		int fa;
		cin>>fa;
		S[fa].push_back(i);
	}
	for(int i=2;i<=n;i++)
	{
		int fa;
		cin>>fa;
		K[fa].push_back(i);
	}
	dfs(1);
	findans(1);
	print(ans);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--) solve();
}