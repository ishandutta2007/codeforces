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
const int maxn=1e5+7;
int arr[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	int ans=1;
	int mx=-1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		mx=max(mx,arr[i]);
	}
	int cur=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==mx)
			cur++;
		else cur=0;
		ans=max(ans,cur);
	}
	printf("%d\n",ans);
}