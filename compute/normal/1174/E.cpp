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
const int maxn=1e6+7;
const int mod=1e9+7;
int dp[maxn][21][2];
int n;
int two[21];
int getcnt(int x,int y)
{
	return n/(two[x]*(y==1?3:1));
}
int main()
{
	cin>>n;
	two[0]=1;
	for(int i=1;i<21;i++) two[i]=two[i-1]*2;
	ll cur=1;
	int cnt=0;
	while(cur*2<=n)
	{
		cur*=2;
		cnt++;
	}
	dp[1][cnt][0]=1;
	if(cnt&&cur/2*3<=n) dp[1][cnt-1][1]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=cnt;j>=0;j--)
		{
			for(int k=1;k>=0;k--)
			{
				dp[i+1][j][k]=(dp[i+1][j][k]+1LL*dp[i][j][k]*(getcnt(j,k)-i)%mod)%mod;
				if(j)
					dp[i+1][j-1][k]=(dp[i+1][j-1][k]+1LL*dp[i][j][k]*(getcnt(j-1,k)-getcnt(j,k))%mod)%mod;
				if(k)
					dp[i+1][j][k-1]=(dp[i+1][j][k-1]+1LL*dp[i][j][k]*(getcnt(j,k-1)-getcnt(j,k))%mod)%mod;
				dbg(i,j,k,dp[i][j][k]);
			}
		}
	}
	cout<<dp[n][0][0]<<endl;
	
}