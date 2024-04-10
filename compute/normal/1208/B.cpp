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
const int maxn=2005;
const int INF=0x3f3f3f3f;
int arr[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int len=0;
	map<int,int> ext;
	map<int,int> rightcount;
	int var=0;
	for(int i=n-1;i>=0;i--)
	{
		if(rightcount.count(arr[i])){
			var=i+1;break;
		}
		rightcount[arr[i]]=1;
	}
	len=n-var;
	int cur=var;
	for(int i=0;i<n;i++)
	{
		if(ext.count(arr[i])) break;
		ext[arr[i]]=1;
		for(int j=n-1;j>=max(i,var);j--)
		{
			if(arr[j]==arr[i])
			{
				cur=max(cur,j+1);
				dbg(i,j);
				break;
			}
		}
		len=max(len,i+1+n-cur);
	}
	cout<<n-len<<endl;
}