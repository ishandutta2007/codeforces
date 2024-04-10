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
const int maxn=505;
int dp[maxn][maxn];
vector<int> arr;
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	arr.push_back(s[0]-'a');
	for(int i=0;i<n;i++)
		if(s[i]-'a'!=arr.back()) arr.push_back(s[i]-'a');
	for(int i=0;i<arr.size();i++) dp[i][i]=1;
	for(int len=2;len<=arr.size();len++)
	{
		for(int l=0,r=len-1;r<arr.size();l++,r++)
		{
			dp[l][r]=dp[l+1][r]+1;
			for(int k=l+2;k<=r;k++)
			{
				if(arr[k]==arr[l])
					dp[l][r]=min(dp[l][r],dp[l+1][k-1]+dp[k][r]);
			}
			dbg(l);dbg(r);
			dbg(dp[l][r]);
		}
	}
	cout<<dp[0][arr.size()-1]<<endl;
}