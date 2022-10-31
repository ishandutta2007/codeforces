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
const int INF=0x3f3f3f3f;
int arr[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int pre=INF;
	long long ans=0;
	for(int i=n-1;i>=0;i--)
	{
		if(pre>arr[i]) 
		{
			ans+=arr[i];
			pre=arr[i];
		}
		else {
			ans+=pre-1;
			pre--;
		}
		if(pre==0) break;
	}
	printf("%lld\n",ans);
}