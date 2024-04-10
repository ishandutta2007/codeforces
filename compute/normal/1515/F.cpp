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
typedef pair<ll,ll> pi;
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
set<pi> G[maxn];
int fa[maxn];
int Find(int x)
{
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
	x=Find(x),y=Find(y);
	if(G[x].size()<G[y].size()) swap(x,y);
	for(auto &e:G[y]) G[x].insert(e);
	fa[y]=x;
	G[y].clear();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	for(int i=0;i<maxn;i++) fa[i]=i;
	int n,m,x;
	cin>>n>>m>>x;
	vc<ll> a(n+1);
	ll tot=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		tot+=a[i];
	}
	if(tot<1LL*(n-1)*x)
	{
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].insert(pi(v,i+1));
		G[v].insert(pi(u,i+1));
	}
	set<pi> q;
	for(int i=1;i<=n;i++) q.insert(pi(a[i],i));
	while(q.size())
	{
		auto cur=*q.rbegin();
		int u=cur.second;
		assert(Find(u)==u);
		q.erase(cur);
		while(G[u].size())
		{
			auto to=*G[u].begin();
			int v=to.first;
			if(Find(v)==u)
				G[u].erase(G[u].begin());
			else{
				print(to.second);
				q.erase(pi(a[Find(v)],Find(v)));
				ll ca=a[Find(v)]+cur.first-x;
				Union(u,v);
				q.insert(pi(ca,Find(u)));
				a[Find(u)]=ca;
				break;
			}
		}
	}
}