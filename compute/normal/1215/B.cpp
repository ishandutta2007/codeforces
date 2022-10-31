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
const int maxn=2e5+7;
int a[maxn];
int cnt[4];
int main()
{
	int n;
	scanf("%d",&n);
	int cur=1;
	ll ans1=0,ans2=0;
	cnt[1]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>0) a[i]=1;
		else a[i]=-1;
		cur=a[i]*cur;
		if(cur>0)
		{
			ans2+=cnt[1];
			ans1+=cnt[0];
			cnt[1]++;
		}
		else{
			ans2+=cnt[0];
			ans1+=cnt[1];
			cnt[0]++;
		}
	}
	printf("%lld %lld\n",ans1,ans2);

}