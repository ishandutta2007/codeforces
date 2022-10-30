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
const int mod=1e9+7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		vc<ll> x(n);
		for(int i=0;i<n;i++) cin>>x[i];
		ll ans=0;
		vi cnt(62);
		for(int i=60;i>=0;i--)
		{
			for(auto u:x) cnt[i]+=u>>i&1;
		}
		for(int j=0;j<n;j++)
		{
			ll as=0,os=0;
			for(int t=60;t>=0;t--)
			{
				if(x[j]>>t&1)
				{
					as=(as+(1LL<<t)%mod*cnt[t]%mod)%mod;
					os=(os+(1LL<<t)%mod*n%mod)%mod;
				}
				else{
					os=(os+(1LL<<t)%mod*cnt[t]%mod)%mod;
				}
			}
			dbg(j,as,os);
			ans=(ans+as*os%mod)%mod;
		}
		print(ans);
	}
}