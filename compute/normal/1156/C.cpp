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
int arr[maxn];
int n,z;
bool check(int cur)
{
	int r=cur;
	for(int i=0;i<cur;i++)
	{
		if(r>=n) return false;
		while(r<n&&arr[r]-arr[i]<z) r++;
		if(r>=n) return false;
		r++;
	}
	return true;
}
int main()
{
	scanf("%d%d",&n,&z);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	sort(arr,arr+n);
	int cnt=0;
	int l=0,r=n;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid)) l=mid+1,cnt=mid;
		else r=mid-1;
	}
	printf("%d\n",cnt);
}