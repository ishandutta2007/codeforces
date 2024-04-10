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
using tp=tuple<int,int,int>;
const int maxn=5e5+7;
struct Edge{
	int to,w;
};
vc<Edge> G[maxn];
vc<tp> Edge;
int n;
pi dfs(int u,int fa=-1)
{
	pi ret={1,u};
	for(auto &e:G[u])if(e.to!=fa)
	{
		int v=e.to;
		auto cur=dfs(v,u);
		cur.first++;
		ret=max(ret,cur);
	}
	return ret;
}
pi diameter()
{
	pi tar=dfs(1);
	pi tt=dfs(tar.second);
	return make_pair(tar.second,tt.second);
}
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
struct Solver{
	int dfn[maxn],dep[maxn],ti=0,out[maxn];
	int rev[maxn];
	int val[maxn];
	int rt;
	void dfs(int u,int fa=-1)
	{
		dfn[u]=++ti;
		rev[ti]=u;
		for(auto &e:G[u])if(e.to!=fa)
		{
			int v=e.to;
			val[v]=val[u]^e.w;
			dep[v]=dep[u]+1;
			dfs(v,u);
		}
		out[u]=ti;
	}
	void setrt(int u)
	{
		rt=u;
		dfs(rt);
		assert(ti==n);
		build();
	}
	int mx[maxn<<2][2];
	int lz[maxn<<2];
	void build(int L=1,int R=n,int o=1)
	{
		if(L==R)
		{
			int pt=rev[L];
			mx[o][val[pt]]=dep[pt];
			mx[o][val[pt]^1]=-1e9;
			return;
		}
		int mid=L+R>>1;
		build(Lson);
		build(Rson);
		mx[o][0]=max(mx[lson][0],mx[rson][0]);
		mx[o][1]=max(mx[lson][1],mx[rson][1]);
	}
	void pushdown(int o)
	{
		if(lz[o])
		{
			swap(mx[lson][0],mx[lson][1]);
			swap(mx[rson][0],mx[rson][1]);
			lz[lson]^=1;
			lz[rson]^=1;
			lz[o]=0;
		}
	}
	void update(int l,int r,int L=1,int R=n,int o=1)
	{
		if(l<=L&&r>=R)
		{
			swap(mx[o][0],mx[o][1]);
			lz[o]^=1;
			return;
		}
		pushdown(o);
		int mid=L+R>>1;
		if(l<=mid) update(l,r,Lson);
		if(r>mid) update(l,r,Rson);
		mx[o][0]=max(mx[lson][0],mx[rson][0]);
		mx[o][1]=max(mx[lson][1],mx[rson][1]);
	}
	void change(int u,int v)
	{
		if(dep[u]<dep[v]) swap(u,v);
		update(dfn[u],out[u]);
	}
	int getans()
	{
		return mx[1][0];
	}
}s1,s2;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v,t;
		cin>>u>>v>>t;
		Edge.emplace_back(u,v,t);
		G[u].push_back({v,t});
		G[v].push_back({u,t});
	}
	pi rt=diameter();
	dbg(rt.first,rt.second);
	s1.setrt(rt.first);
	s2.setrt(rt.second);
	int m;
	cin>>m;
	while(m--)
	{
		int id;
		cin>>id;
		id--;
		auto cur=Edge[id];
		int u,v,t;tie(u,v,t)=cur;
		s1.change(u,v);
		s2.change(u,v);
		print(max(s1.getans(),s2.getans()));
	}
}