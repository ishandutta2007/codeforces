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
const int maxn=1e5+7;
double arr[maxn];
ll ans[maxn];
bool sta[maxn];
int main()
{
	int n;
	double tot=0;
	ll sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&arr[i]);
		tot+=arr[i];
		if(ceil(arr[i])==floor(arr[i])) sta[i]=1;
		sum+=floor(arr[i]);
		ans[i]=floor(arr[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(sta[i]) continue;
		if(sum==ll(round(tot))) break;
		sum++;
		ans[i]++;
	}
	for(int i=0;i<n;i++)
		printf("%lld\n",ans[i]);
}