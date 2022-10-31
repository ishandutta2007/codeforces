#include<bits/stdc++.h>
using namespace std;
#ifndef Online_Judge
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
long long ans[maxn];
int arr[maxn];
int query[maxn];
int main()
{
	int n;
	long long tot=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		tot+=arr[i];
	}
	sort(arr,arr+n);
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++) scanf("%d",&query[i]);
	for(int i=1;i<=n;i++)
	{
		ans[i]=tot-arr[n-i];
	}
	for(int i=0;i<m;i++)
	{
		printf("%lld\n",ans[query[i]]);
	}
}