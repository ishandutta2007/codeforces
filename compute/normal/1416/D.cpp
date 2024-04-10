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
const int maxn=1e6+7;
int ed[maxn];
int p[maxn];
struct Edge{
	int u,v;
}edge[maxn];
struct Q{
	int tp,x;
};
int fa[maxn];
int Find(int x)
{
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
int tot;
vi G[maxn];
void Union(int x,int y)
{
	x=Find(x),y=Find(y);
	if(x==y) return;
	tot++;
	fa[x]=tot;
	fa[y]=tot;
	G[tot].push_back(x);
	G[tot].push_back(y);
}
int ti[maxn],ot[maxn];
int T;
void dfs(int u,int fa=-1)
{
	ti[u]=++T;
	for(auto v:G[u])if(v!=fa)
		dfs(v,u);
	ot[u]=T;
}
pi mx[maxn<<2];
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
void modify(int p,int v,int L=1,int R=tot,int o=1)
{
	if(L==R)
	{
		mx[o]=make_pair(v,p);
		return;
	}
	int mid=L+R>>1;
	if(p<=mid) modify(p,v,Lson);
	else modify(p,v,Rson);
	mx[o]=max(mx[lson],mx[rson]);
}
pi ask(int l,int r,int L=1,int R=tot,int o=1)
{
	if(l<=L&&r>=R)
		return mx[o];
	pi ret={0,0};
	int mid=L+R>>1;
	if(l<=mid) ret=max(ret,ask(l,r,Lson));
	if(r>mid) ret=max(ret,ask(l,r,Rson));
	return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n+m+q;i++) fa[i]=i;
	tot=n;
	for(int i=1;i<=n;i++) cin>>p[i];
	for(int i=1;i<=m;i++) cin>>edge[i].u>>edge[i].v,ed[i]=q;
	vc<Q> query(q);
	for(int i=0;i<q;i++)
	{
		int tp,x;
		cin>>tp>>x;
		if(tp==2) ed[x]=i;
		query[i]={tp,x};
	}
	for(int i=1;i<=m;i++)
		if(ed[i]==q) Union(edge[i].u,edge[i].v);
	for(int i=q-1;i>=0;i--)
	{
		int x=query[i].x;
		if(query[i].tp==2) Union(edge[x].u,edge[x].v);
		else{
			query[i].x=Find(query[i].x);
			dbg(i,query[i].x);
		}
	}
	for(int i=1;i<=tot;i++)
		if(Find(i)==i) dfs(i);
	for(int i=1;i<=n;i++)
		modify(ti[i],p[i]);
	for(int i=0;i<q;i++)
	{
		if(query[i].tp==1)
		{
			int x=query[i].x;
			auto tar=ask(ti[x],ot[x]);
			print(tar.first);
			modify(tar.second,0);
		}
	}
}