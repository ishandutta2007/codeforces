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
const int mod=1e9+7;
const int maxn=2e5+7;
ll fac[maxn];
ll invfac[maxn];
ll quick(ll a,ll b)
{
    ll ret=1;
    while(b)
    {
        if(b&1) ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
ll C(ll n,ll m)
{
    if(n<m) return 0;
    return fac[n]*fac[m]%mod*invfac[n-m]%mod;
}
void solve()
{
    int n,k;
    cin>>n>>k;
    ll ans=1;
    for(int i=1;i<=n;i++)
    {
        ll cur=C(n+k+i-1LL*k*i-1,i);
        ll gl=cur*quick(C(n,i),mod-2)%mod;
        ans=(ans+gl%mod)%mod;
    }
    print(ans);
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    fac[0]=1;
    for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
    for(int i=0;i<maxn;i++) invfac[i]=quick(fac[i],mod-2);
    int T;
    cin>>T;
    while(T--) solve();
}