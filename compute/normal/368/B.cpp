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
const int maxn=1e5+7;
int cnt[maxn];
int arr[maxn];
int ans[maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int tot=0;
	for(int i=0;i<n;i++) 
	{
		scanf("%d",&arr[i]);
		if(!cnt[arr[i]]) tot++;
		cnt[arr[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		ans[i]=tot;
		cnt[arr[i]]--;
		if(!cnt[arr[i]]) tot--;
	}
	while(m--)
	{
		int q;
		cin>>q;
		cout<<ans[q-1]<<endl;
	}
}