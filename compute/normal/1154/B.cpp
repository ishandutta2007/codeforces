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
int arr[205];
int main()
{
	int n;
	cin>>n;
	int ans=-1;
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int d=0;d<=200;d++)
	{
		int cur=arr[1]-d;
		for(int i=2;i<=n;i++)
		{
			if(arr[i]-d!=cur&&arr[i]+d!=cur&&arr[i]!=cur) break;
			if(i==n) ans=d;
		}
		cur=arr[1]+d;
		for(int i=2;i<=n;i++)
		{
			if(arr[i]-d!=cur&&arr[i]+d!=cur&&arr[i]!=cur) break;
			if(i==n) ans=d;
		}
		cur=arr[1];
		for(int i=2;i<=n;i++)
		{
			if(arr[i]-d!=cur&&arr[i]+d!=cur&&arr[i]!=cur) break;
			if(i==n) ans=d;
		}
		if(ans!=-1) break;
	}
	if(n==1) ans=0;
	cout<<ans<<endl;
}