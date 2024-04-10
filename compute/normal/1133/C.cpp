#include<bits/stdc++.h>
using namespace std;
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
int arr[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	sort(arr,arr+n);
	int ans=0;
	int l=0,r=-1;
	while(r<n)
	{
		++r;
		if(r>=n) break;
		while(arr[r]-arr[l]>5)
			l++;
		ans=max(ans,r-l+1);
		dbg(l);dbg(r);
	}
	printf("%d\n",ans);
}