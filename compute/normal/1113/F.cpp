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
const int maxn=1e6+7;
const int mod=1e9+7;
long long fac[maxn];
long long quick(long long a,long long b)
{
	assert(b>=0);
	long long ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
long long inv(long long a){return quick(a,mod-2);}
void db()
{
	fac[0]=1;
	for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
}
long long C(int n,int m)
{
	if(m>n) return 0;
	return fac[n]*inv(fac[m])%mod*inv(fac[n-m])%mod;
}
long long calforest(int s,int n)
{
	if(n-s-1<0) return s*inv(n)%mod;
	return s*quick(n,n-s-1)%mod;
}
int main()
{
	db();
	int n,m,a,b;
	scanf("%d%d%d%d",&n,&m,&a,&b);
	long long ans=0;
	for(int i=1;i<=min(n-1,m);i++)
	{
		long long cur=C(n-2,i-1)*fac[i-1]%mod;
		cur=cur*C(m-1,i-1)%mod;
		cur=cur*quick(m,n-i-1)%mod;
		cur=cur*calforest(i+1,n)%mod;
		ans+=cur;
		ans%=mod;
		dbg(ans);
	}
	printf("%lld\n",ans);
}