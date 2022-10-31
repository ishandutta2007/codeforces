#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "the " << #x << " -> "; err(x); } while (0)
void err() { cout << "" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
const int maxn=5e4+7;
const int INF=0x3f3f3f3f;
int arr[maxn];
int vis[105];
int main()
{
	memset(vis,0,sizeof(vis));
	int n;
	scanf("%d",&n);
	int tot=0;
	for(int i=0;i<n;i++) {scanf("%d",&arr[i]);tot+=arr[i];}
	int cnt1=0,cnt2=INF,cnt=0;
	for(int fac=2;fac<=100;fac++)
	{
		cnt1=INF,cnt2=INF;
		for(int i=0;i<n;i++)
		{
			if(arr[i]%fac==0&&arr[i]!=fac)
			{
				cnt1=min(cnt1,arr[i]/fac-arr[i]);
				vis[fac]=1;
			}
			cnt2=min(cnt2,arr[i]*fac-arr[i]);
		}
		cnt=min(cnt,cnt1+cnt2);
	}
	dbg(cnt);
	if(cnt<0) tot+=cnt;
	printf("%d\n",tot);
}