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
int arr[maxn],brr[maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	for(int i=0;i<m;i++) scanf("%d",&brr[i]);
	ll ans=0;
	int ma=0,mb=0x3f3f3f3f,pos=0;
	for(int i=0;i<n;i++) ma=max(arr[i],ma);
	for(int i=0;i<m;i++) mb=min(mb,brr[i]);
	if(mb<ma) ans=-1;
	if(m==1)
	{
		if(ma!=mb) ans=-1;
	}
	if(ans==-1) puts("-1");
	else{
		for(int i=0;i<m;i++) ans+=brr[i];
		int ma2=0;
		ma=0;
		for(int i=0;i<n;i++)
		{
			if(ma<arr[i])
			{
				ma2=ma;
				ma=arr[i];
			}
			else if(ma2<arr[i]) ma2=arr[i];
			ans+=1LL*arr[i]*m;
		}
		dbg(ans,ma,ma2);
		if(ma==mb)
			ans-=1LL*m*ma;
		else ans-=1LL*(m-1)*ma+ma2;
		printf("%lld\n",ans);
	}
}