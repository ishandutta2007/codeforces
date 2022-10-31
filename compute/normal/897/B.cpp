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
int mod;
const int maxn=100007;
int calc(int i)
{
	ll ret=i;
	int sv=i;
	while(sv)
	{
		ret=(ret*10+sv%10)%mod;
		sv/=10;
	}
	return ret%mod;
}
int main()
{
	int k;
	cin>>k>>mod;
	ll ans=0;
	for(int i=1;i<=k;i++)
	{
		ans+=calc(i);
		ans%=mod;
	}
	cout<<ans<<endl;
}