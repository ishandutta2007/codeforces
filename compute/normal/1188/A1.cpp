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
int deg[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		deg[u]++;
		deg[v]++;
	}
	bool ok=1;
	for(int i=1;i<=n;i++)
	{
		if(deg[i]==2)
			ok=0;
	}
	puts(ok?"YES":"NO");
}