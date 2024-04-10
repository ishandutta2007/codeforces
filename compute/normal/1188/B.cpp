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
const int maxn=3e5+7;
map<ll,int> cnt;
int main()
{
	ll n,p,k;
	scanf("%lld%lld%lld",&n,&p,&k);
	ll ans=0;
	ll mod=p;
	for(int i=0;i<n;i++)
	{
		ll tmp;
		scanf("%lld",&tmp);
		ll cur=tmp*tmp%mod*tmp%mod*tmp%mod;
		cur=cur-k*tmp%mod+mod;
		cur%=mod;
		ans+=cnt[cur];
		cnt[cur]++;
	}
	printf("%lld\n",ans);
}