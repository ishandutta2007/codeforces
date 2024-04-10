#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
ll quick(ll a,ll b,ll mod)
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
ll inv(ll a,ll mod){return quick(a,mod-2,mod);}
int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		int n;
		cin>>n;
		vector<int> a(n+1);
		int st=-1;
		for(int i=0;i<n;i++) 
		{
			cin>>a[i];
			if(a[i]==1) st=i;
		}
		bool ok1=1,ok2=1;
		for(int i=st+1;i<n;i++) 
			if(a[i]-a[i-1]!=1) ok1=0;
		for(int i=st+2;i<n;i++)
			if(a[i]-a[i-1]!=-1) ok2=0;
		if(ok1)
		{
			for(int i=1;i<st;i++) if(a[i]-a[i-1]!=1) ok1=0;
		}
		if(ok2)
		{
			for(int i=1;i<=st;i++)
				if(a[i]-a[i-1]!=-1) ok2=0;
		}
		if(ok1||ok2) puts("YES");
		else puts("NO");
		
	}
}