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
long long arr[maxn];
long long brr[maxn];
int n,k;
int need[maxn];
bool check(long long x)
{
	memset(need,0,sizeof(need));
	int res=k;
	for(int i=0;i<n;i++)
	{
		long long cur=arr[i];
		while(cur<1LL*k*brr[i])
		{
			if(!res) return 0;
			res--;
			need[cur/brr[i]+1]++;
			cur+=x;
		}
	}
	for(int i=1;i<=k;i++) 
	{
		need[i]=need[i]+need[i-1];
		if(need[i]>i) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&k);
	k--;
	for(int i=0;i<n;i++)
		scanf("%lld",&arr[i]);
	for(int i=0;i<n;i++)
		scanf("%lld",&brr[i]);
	long long l=0,r=1e13,ans=-1;
	while(l<r)
	{
		long long mid=l+r>>1;
		if(check(mid)) r=mid,ans=mid;
		else l=mid+1;
	}
	printf("%lld\n",ans);
}