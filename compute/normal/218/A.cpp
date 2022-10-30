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
const int maxn=105;
int arr[maxn];
int main()
{
	int k,n;
	cin>>n>>k;
	for(int i=1;i<=2*n+1;i++)
		cin>>arr[i];
	for(int i=2;i<=2*n+1;i+=2)
	{
		if(!k) break;
		if(arr[i]-1>arr[i-1]&&arr[i]-1>arr[i+1])
		{
			arr[i]--;
			k--;
		}
	}
	for(int i=1;i<=2*n+1;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}