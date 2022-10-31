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
struct P{
	ll l,r;
	ll dif;
}pt[maxn];
int n;
bool cmp1(const P &a,const P &b) 
{
	return a.dif>b.dif;
}
int main()
{
	scanf("%d",&n);
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld",&pt[i].l,&pt[i].r);
		ans+=-pt[i].l+pt[i].r*n;
		pt[i].dif=pt[i].l-pt[i].r;
	}
	sort(pt,pt+n,cmp1);
	for(int i=1;i<=n;i++)
	{
		ans+=1LL*i*pt[i-1].dif;
	}
	printf("%lld\n",ans);
}