#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
const int mod=998244353;
const int INF=0x3f3f3f3f;
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
bool cmp(PII a,PII b)
{
	return a.first+a.second>b.first+b.second;
}
int main()
{
	int n,r;
	scanf("%d%d",&n,&r);
	vector<PII> pos,neg;
	for(int i=0,a,b;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		if(b>=0) pos.push_back(make_pair(a,b));
		else neg.push_back(make_pair(max(a,-b),b));
	}
	sort(pos.begin(),pos.end());
	sort(neg.begin(),neg.end(),cmp);
	bool ok=1;
	for(auto u:pos)
	{
		if(u.first>r) ok=0;
		else r+=u.second;
	}
	for(auto u:neg)
	{
		if(u.first>r) ok=0;
		else r+=u.second;
	}
	if(ok) puts("YES");
	else puts("NO");
}