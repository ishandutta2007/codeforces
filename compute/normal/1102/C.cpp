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
const int maxn=1e5+7;
int arr[maxn];
int main()
{
	int n,x,y;
	cin>>n>>x>>y;
	for(int i=0;i<n;i++) cin>>arr[i];
	if(x>y)
		cout<<n<<endl;
	else{
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i]<=x)
			{
				ans++;
			}
		}
		cout<<ceil(ans/2.0)<<endl;
	}
}