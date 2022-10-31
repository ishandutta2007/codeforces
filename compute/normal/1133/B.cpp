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
int cnt[105];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0,temp;i<n;i++)
	{
		scanf("%d",&temp);
		cnt[temp%k]++;
	}
	int ans=0;
	ans+=cnt[0]/2*2;
	dbg(ans);
	for(int i=1;i<=k/2;i++)
	{
		if(i==k/2&&k%2==0)
		{
			ans+=cnt[i]/2*2;
		}
		else ans+=min(cnt[i],cnt[k-i])*2;
		dbg(i);dbg(ans);
	}
	printf("%d\n",ans);
}