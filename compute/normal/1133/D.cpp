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
typedef pair<int,int> PII;
map<pair<int,PII>,int> cnt;
const int maxn=2e5+7;
int arr[maxn],brr[maxn];
int main()
{
	int n;
	int ans=0;
	scanf("%d",&n);
	int zero=0;
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	for(int i=0;i<n;i++) scanf("%d",&brr[i]);
	for(int i=0;i<n;i++)
	{
		if(arr[i]==0&&brr[i]==0) zero++;
		if(!arr[i]) continue;
		pair<int,PII> cur;
		cur.first=(1LL*arr[i]*brr[i]>0?1:-1);
		arr[i]=abs(arr[i]);
		brr[i]=abs(brr[i]);
		int	gcd=__gcd(arr[i],brr[i]);
		arr[i]/=gcd;brr[i]/=gcd;
		cur.second=make_pair(brr[i],arr[i]);
		cnt[cur]++;
		ans=max(ans,cnt[cur]);
	}
	printf("%d\n",ans+zero);
}