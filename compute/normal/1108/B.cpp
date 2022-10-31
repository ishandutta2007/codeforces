#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[33;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
int arr[200];
int app[10005];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) 
	{
		cin>>arr[i];
		app[arr[i]]++;
	}
	sort(arr,arr+n);
	int ans1=arr[n-1];
	for(int i=1;i<=ans1;i++)
	{
		if(ans1%i==0) app[i]--;
	}
	int ans2;
	for(int i=10000;i>=0;i--)
	{
		if(app[i])
		{
			ans2=i;break;
		}
	}
	cout<<ans1<<" "<<ans2<<endl;
}