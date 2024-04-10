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
const int maxn=2e5+7;
int arr[maxn];
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int mx1=0,mx2=0;
	for(int i=0;i<n;i++) 
	{
		scanf("%d",&arr[i]);
		if(mx1<=arr[i])
		{
			mx2=mx1;
			mx1=arr[i];
		}
		else{
			mx2=max(mx2,arr[i]);
		}
	}
	long long sim=1LL*k*mx1+1LL*mx2;
	dbg(sim);
	long long ans=0;
	ans=sim*(m/(k+1));
	ans+=1LL*mx1*(m%(k+1));
	printf("%lld\n",ans);
}