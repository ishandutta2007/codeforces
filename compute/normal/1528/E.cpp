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
const int maxn=1e6+7;
const int mod=998244353;
ll dp[maxn],f[maxn],pre[maxn];
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
ll inv2=quick(2,mod-2),inv6=quick(6,mod-2);
inline ll C2(ll x)
{
	return x*(x-1)%mod*inv2%mod;
}
inline ll C3(ll x)
{
	return x*(x-1+mod)%mod*(x-2+mod)%mod*inv6%mod;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	if(n==1)
	{
		print(5);
		return 0;
	}
	dp[0]=1;
	pre[0]=1;
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		f[i]=dp[i]-1;
		if(i>=2)
			dp[i]=(dp[i]+dp[i-1]*pre[i-2])%mod;
		dp[i]=(dp[i]+C2(dp[i-1])+dp[i-1])%mod;
		pre[i]=(pre[i-1]+dp[i])%mod;
	}
	ll ans=dp[n]+dp[n-1]*(C2(pre[n-2])+pre[n-2])%mod+(C2(dp[n-1])+dp[n-1])%mod*pre[n-2]%mod+C3(dp[n-1])+C2(dp[n-1])*2%mod+dp[n-1];
	ans%=mod;
	ans=(ans*2-1+mod)%mod;
	//dbg(ans);
	for(int i=1;i<n;i++)
	{
		ans=(ans+f[i]*(dp[n-i]-1-f[n-i]+mod)%mod)%mod;
	//	ans=(ans+f[i]*f[n-i]%mod)%mod;
	//	dbg(i,f[i],f[n-i]);
	}
	print(ans);
}