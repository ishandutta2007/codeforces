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
const int maxn=3e5+7;
int fa[maxn];
int Find(int x)
{
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
	x=Find(x),y=Find(y);
	fa[y]=x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int m,n;
	cin>>m>>n;
	for(int i=0;i<=n+m;i++) fa[i]=i;
	vi a(m);
	vi b(n);
	for(int i=0;i<m;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	vc<vi> A(m);
	using tp=tuple<int,int,int>;
	vc<tp> edge;
	ll tot=0;
	for(int i=0;i<m;i++)
	{
		int sz;
		cin>>sz;
		A[i]=vi(sz);
		for(int j=0;j<sz;j++)
		{
			cin>>A[i][j];
			edge.emplace_back(a[i]+b[A[i][j]-1],i+n,A[i][j]-1);
			tot+=a[i]+b[A[i][j]-1];
		}
	}
	sort(edge.begin(),edge.end());
	reverse(edge.begin(),edge.end());
	for(auto u:edge)
	{
		int w,x,y;tie(w,x,y)=u;
		if(Find(x)==Find(y)) continue;
		tot-=w;
		Union(x,y);
	}
	print(tot);
}