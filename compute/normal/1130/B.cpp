#include<bits/stdc++.h>
using namespace std;
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
vector<int> arr[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
	{
		int cur;
		scanf("%d",&cur);
		arr[cur].push_back(i);
	}
	long long ans=0;
	int cura=1,curb=1;
	for(int i=1;i<=n;i++)
	{
		ans+=min(abs(arr[i][0]-cura)+abs(arr[i][1]-curb),abs(arr[i][0]-curb)+abs(arr[i][1]-cura));
		cura=arr[i][0],curb=arr[i][1];
	}
	printf("%lld\n",ans);
}