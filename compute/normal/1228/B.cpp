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
const int maxn=1e3+7;
const int mod=1e9+7;
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
int r[maxn],c[maxn];
int maze[maxn][maxn];
int h,w;
bool check()
{
	for(int i=0;i<h;i++)
	{
		if(maze[i][r[i]]==1) 
		{
			return false;
		}
		maze[i][r[i]]=-1;
	}
	for(int i=0;i<w;i++)
	{
		if(maze[c[i]][i]==1) return false;
		maze[c[i]][i]=-1;
	}
	return true;
}
int main()
{
	cin>>h>>w;
	for(int i=0;i<h;i++)
	{
		cin>>r[i];
		for(int j=0;j<r[i];j++)
			maze[i][j]=1;
	}
	for(int i=0;i<w;i++)
	{
		cin>>c[i];
		for(int j=0;j<c[i];j++)
			maze[j][i]=1;
	}
	if(!check()) cout<<0<<endl;
	else{
		int cnt=0;
		for(int i=1;i<h;i++)
		{
			for(int j=1;j<w;j++)
				if(!maze[i][j]) cnt++;
		}
		cout<<quick(2,cnt)<<endl;
	}
}