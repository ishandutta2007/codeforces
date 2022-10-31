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
int brr[maxn];
int hei[maxn][maxn];
int ans[maxn][maxn];
int main()
{
	int n,m,h;
	cin>>n>>m>>h;
	for(int i=0;i<m;i++) cin>>arr[i];
	for(int i=0;i<n;i++) cin>>brr[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>hei[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!hei[i][j]) continue;
			else ans[i][j]=max(1,min(arr[j],brr[i]));
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
}