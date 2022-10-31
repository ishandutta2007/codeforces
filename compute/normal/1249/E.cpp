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
const int maxn=2e5+7;
int a[maxn],b[maxn];
int dp[maxn][2];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,c;
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	cin>>n>>c;
	for(int i=1;i<n;i++) cin>>a[i];
	for(int i=1;i<n;i++) cin>>b[i];
	for(int i=1;i<n;i++)
	{
		dp[i][0]=min(dp[i-1][1],dp[i-1][0])+a[i];
		dp[i][1]=min(dp[i-1][0]+c,dp[i-1][1])+b[i];
	}
	for(int i=0;i<n;i++)
		cout<<min(dp[i][0],dp[i][1])<<" ";
	cout<<endl;

}