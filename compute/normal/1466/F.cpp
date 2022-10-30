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
struct Edge{
	int v,id;
	bool operator<(const Edge&a){
		return id<a.id;
	}
};
const int maxn=5e5+7;
vc<Edge> G[maxn];
const int mod=1e9+7;
vc<pi> all;
int vis[maxn];
int fa[maxn],sg[maxn];
int Find(int x)
{
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
	x=Find(x);y=Find(y);
	sg[x]|=sg[y];
	fa[y]=x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=m;i++) fa[i]=i;
	vi op;
	for(int i=0,u,v;i<n;i++)
	{
		int k;
		cin>>k;
		if(k==2)
		{
			cin>>u>>v;
			if(Find(u)!=Find(v))
			{
				if(!sg[Find(u)]||!sg[Find(v)])
					op.push_back(i+1);
				Union(u,v);
			}
		}
		else {
			cin>>u;
			if(!sg[Find(u)])
			{
				op.push_back(i+1);
				sg[Find(u)]=1;
			}
		}
	}
	int T=1;
	for(int i=0;i<op.size();i++) T=T*2%mod;
	cout<<T<<" "<<op.size()<<'\n';
	print(op);
}