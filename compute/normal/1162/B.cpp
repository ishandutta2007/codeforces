#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int maxn=55;
int a[maxn][maxn],b[maxn][maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&b[i][j]);
			if(b[i][j]<a[i][j]) swap(a[i][j],b[i][j]);
		}
	}
	bool ok=1;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(a[i][j]<=a[i][j-1]) ok=0;
		}
		if(i)
		{
		    for(int j=0;j<m;j++)
			if(a[i][j]<=a[i-1][j]) ok=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(b[i][j]<=b[i][j-1]) ok=0;
		}
		if(i)
		{
		    for(int j=0;j<m;j++)
			if(b[i][j]<=b[i-1][j]) ok=0;
		}
		
	}
	if(ok) cout<<"Possible"<<endl;
	else cout<<"Impossible"<<endl;
}