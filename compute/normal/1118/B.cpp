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
int odd[maxn];
int even[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	for(int i=1;i<=n;i++)
	{
		odd[i]=odd[i-1];
		even[i]=even[i-1];
		if(i%2==1)
		{
			odd[i]+=arr[i];
		}
		else even[i]+=arr[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int od=odd[i-1],ev=even[i-1];
		od+=even[n]-even[i];
		ev+=odd[n]-odd[i];
		if(od==ev) ans++;
		dbg(i);dbg(ans);
	}
	printf("%d\n",ans);
}