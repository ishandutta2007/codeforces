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
int arr[maxn];
int n,m;
bool check(int cur)
{
	int pre=0;
	for(int i=0;i<n;i++)
	{
		if(pre<arr[i])
		{
			if(m-arr[i]+pre>cur) pre=arr[i];
		}
		else if(pre>arr[i])
			if(pre-arr[i]>cur) return false;
	}
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int l=0,r=m,ans=m;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d\n",ans);
}