#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[33;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int maxn=2e5+7;
ll arr[maxn],brr[maxn];
const int mod=998244353;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",&arr[i]);
	for(int i=0;i<n;i++) scanf("%lld",&brr[i]);
	for(int i=0;i<n;i++)
		arr[i]=arr[i]*(i+1)*(n-i);
	sort(arr,arr+n);
	sort(brr,brr+n);
	reverse(brr,brr+n);
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		ans=(ans+arr[i]%mod*brr[i]%mod)%mod;
	}
	printf("%lld\n",ans);
}