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
ll las[maxn];
ll arr[maxn];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	ll cur=0;
	for(int i=0;i<n;i++)
		scanf("%lld",&arr[i]);
	for(int j=n-1;j>=0;j--)
		las[j]=las[j+1]+arr[j];
	ll ans=las[0];
	sort(las+1,las+n);
	reverse(las+1,las+n);
	for(int i=1;i<k;i++)
		ans+=las[i];
	printf("%lld\n",ans);
}