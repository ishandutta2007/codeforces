#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int mod=1e9+7;
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
ll solve(ll n,int cur)
{
	ll ret=0;
	ll tmp=cur;
	while(tmp<=n) 
	{
		ret+=n/tmp;
		long double nxt=tmp;
		nxt*=cur;
		if(nxt>2e18) break;
		tmp*=cur;
	}
	return ret;
}
int main()
{
	ll x,n;
	cin>>x>>n;
	ll ans=1;
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			ans=ans*quick(i,solve(n,i))%mod;
			while(x%i==0) x/=i;
		}
	}
	if(x>1) ans=ans*quick(x,solve(n,x))%mod;
	cout<<ans<<endl;
}