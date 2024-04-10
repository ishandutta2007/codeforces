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
const int mod=998244353;
const int maxn=2e3+7;
ll dp[maxn*2][maxn*2][2];
ll fac[maxn*2];
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
void db()
{
	fac[0]=1;
	for(int i=1;i<maxn*2;i++)
		fac[i]=fac[i-1]*i%mod;
}
int main()
{
	db();
	int n,k,l;
	scanf("%d%d%d",&n,&k,&l);
	dp[0][0][0]=1;
	for(int i=0;i<=2*n+1;i++)
	{
		for(int j=0;j<=i;j++)
		{
			dp[i+1][j+1][0]=(dp[i+1][j+1][0]+dp[i][j][0])%mod;
			dp[i+1][j+1][1]=(dp[i+1][j+1][1]+dp[i][j][1])%mod;
			if(j)
			{
				dp[i+1][j-1][0]=(dp[i+1][j-1][0]+dp[i][j][0]*j%mod)%mod;
				dp[i+1][j-1][1]=(dp[i+1][j-1][1]+dp[i][j][1]*j%mod)%mod;
			}
			if(j>=k)
				dp[i+1][j][1]=(dp[i+1][j][1]+dp[i][j][0])%mod;
		}
	}
	ll ans=dp[2*n+1][0][1]*fac[n]%mod*quick(2,n)%mod*inv(fac[2*n+1])%mod;
	printf("%lld\n",ans*l%mod);

}