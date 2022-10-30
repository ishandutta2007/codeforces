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
void solve()
{
	int n;
	cin>>n;
	vi u(n);
	vvc<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>u[i];
		u[i]--;
	}
	vi s(n);
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		a[u[i]].push_back(s[i]);
	}
	vc<ll> ans(n);
	for(int i=0;i<n;i++)
	{
		sort(a[i].begin(),a[i].end());
		reverse(a[i].begin(),a[i].end());
		vc<ll> pre=vc<ll>(a[i].size()+1);
		int sz=a[i].size();
		for(int j=0;j<a[i].size();j++)
			pre[j+1]=pre[j]+a[i][j];
		for(int j=1;j<=a[i].size();j++)
			ans[j-1]=ans[j-1]+pre[sz/j*j];
	}
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