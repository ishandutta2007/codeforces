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
const int maxn=33;
int arr[maxn],brr[maxn];
int main()
{
	int n,m,r;
	scanf("%d%d%d",&n,&m,&r);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int tot=0;
	for(int i=0;i<m;i++)
		scanf("%d",&brr[i]);
	sort(arr,arr+n);
	sort(brr,brr+m);
	int ans=r;
	if(arr[0]<brr[m-1])
		ans+=r/arr[0]*(brr[m-1]-arr[0]);
	printf("%d\n",ans);

}