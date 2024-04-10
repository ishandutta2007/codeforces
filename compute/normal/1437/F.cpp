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
const int mod=998244353;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n;
	cin>>n;
	vi a(n+1);
	vi pre(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	for(int i=1;i<=n;i++)
	{
		int tar=a[i]/2;
		pre[i]=upper_bound(a.begin(),a.end(),tar)-a.begin()-1;
	}
	vi dp(n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		vi g(n+1);
		vi sum(n+1);
		sum[0]=dp[0];
		for(int i=1;i<=n;i++) sum[i]=(sum[i-1]+dp[i])%mod;
		for(int r=1;r<=n;r++)
		{
			if(pre[r]+1>=i-1)
				g[r]=(g[r]+(ll)dp[r]*(pre[r]-i+2)%mod)%mod;
			if(r)
				g[r]=(g[r]+sum[pre[r]])%mod;
		}
	//	dbg(i,g);
		dp=g;
	}
	print(dp[n]);
}