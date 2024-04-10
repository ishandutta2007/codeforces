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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	vc<pi> a(n);
	vc<pi> b(m);
	for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
	for(int i=0;i<m;i++) cin>>b[i].first>>b[i].second;
	vc<pi> all;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int dx=b[j].first-a[i].first,dy=b[j].second-a[i].second;
			if(dx>=0&&dy>=0)
				all.emplace_back(dx,dy);
		}
	}
	sort(all.begin(),all.end());
	int sz=all.size();
	int ans=0;
	if(sz)
	{
		vi mx(sz);
		mx[sz-1]=all.back().second;
		for(int i=sz-2;i>=0;i--) mx[i]=max(mx[i+1],all[i].second);
		ans=mx[0]+1;
		for(int i=0;i<sz;i++)
			ans=min(ans,all[i].first+1+(i<sz-1?mx[i+1]+1:0));
	}
	print(ans);
}