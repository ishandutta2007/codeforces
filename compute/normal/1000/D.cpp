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
int arr[1005];
const int maxn=2005;
int n;
ll inv[maxn],f[maxn],finv[maxn];
void init()										//inv,f,finv ll
{
    inv[1]=1;
    for(int i=2;i<maxn;i++)
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;		//inv: 
    f[0]=finv[0]=1;								//f:  	finv:(1/f)
    for(int i=1;i<maxn;i++)
    {
        f[i]=f[i-1]*i%mod;
        finv[i]=finv[i-1]*inv[i]%mod;
    }
}

ll C(int n,int m)								//C(n,m)
{
    if(m<0||m>n)    return 0;
    return f[n]*finv[n-m]%mod*finv[m]%mod;
}
ll dp[maxn];
int main()
{
	init();

	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=n-1;i>=0;i--)
	{
		dp[i]=dp[i+1];
		if(arr[i]<=0) continue;
		for(int j=i+arr[i];j<n;j++)
			dp[i]=(dp[i]+C(j-i-1,arr[i]-1)*(1+dp[j+1])%mod)%mod;
	}
	cout<<dp[0]<<endl;
}