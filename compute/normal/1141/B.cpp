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
const int maxn=2e5+7;
int arr[maxn];
int main()
{
	int n;
	cin>>n;
	for(int i=0,temp;i<n;i++)
	{
		cin>>arr[i];
	}
	int pre=0,las=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==1) pre++;
		else break;
	}
	for(int i=n-1;i>=0;i--)
	{
		if(arr[i]==1) las++;
		else break;
	}
	int ans=pre+las;
	int cur=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==1) cur++;
		else cur=0;
		ans=max(cur,ans);
	}
	cout<<ans<<endl;
}