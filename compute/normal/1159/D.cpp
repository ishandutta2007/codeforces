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
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	vector<int> ans;
	int a=(n-k)/2;
	while(ans.size()<n)
	{
		for(int i=0;i<a;i++) ans.push_back(0);
		ans.push_back(1);
	}
	for(int i=0;i<n;i++)
		printf("%d",ans[i]);
	puts("");
}