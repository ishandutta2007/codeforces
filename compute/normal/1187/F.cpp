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
const int maxn=2e5+7;
const int mod=1e9+7;
ll l[maxn],r[maxn];
ll E[maxn];
ll pre[maxn];
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
ll inv(ll a){return quick(a,mod-2);}
ll calc(int a,int b)
{
	ll ret=min({r[a-1],r[a],r[b]})-max({l[a-1],l[a],l[b]});
	if(ret<0) ret=0;
	else ret=ret*inv(r[b]-l[b])%mod*inv(r[a]-l[a])%mod*inv(r[a-1]-l[a-1])%mod;
	return (1-(2-E[a]-E[b]+2*mod)%mod+mod+ret)%mod;
}
int main()
{
	int n;
	scanf("%d",&n);
	ll ans=0;
	for(int i=1;i<=n;i++)
		scanf("%lld",&l[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&r[i]);
		r[i]++;
	}
	ll tot=0;
	for(int i=1;i<=n;i++)
	{
		if(i==1) E[i]=1;
		else {
			ll len=min(r[i-1],r[i])-max(l[i-1],l[i]);
			if(len<0) len=0;
			E[i]=(1-len*inv(r[i-1]-l[i-1])%mod*inv(r[i]-l[i])%mod+mod)%mod;
		}
		ans=(ans+E[i])%mod;
		tot=(tot+E[i])%mod;
	}
	for(int i=1;i<=n;i++)
	{
		if(i>1)
			ans=(ans+calc(i-1,i))%mod;
		if(i<n)
			ans=(ans+calc(i,i+1))%mod;
		ll tmp=tot;
		for(int j=max(i-1,1);j<=min(n,i+1);j++)
			tmp=(tmp-E[j]+mod)%mod;
		ans=(ans+tmp*E[i]%mod)%mod;
	}
	printf("%lld\n",ans);
}