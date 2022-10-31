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
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
const int mod=1e6+3;
const int maxn=15;
ll arr[maxn][maxn];
ll x[maxn];
int ask(int cur)
{
	cout<<'?'<<" "<<cur<<endl;
	int ret;
	cin>>ret;
	return ret;
}
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
ll inv(ll a){return quick(a,mod-2);}
void gauss(int n,int m)
{
	for(int i=0;i<n;i++)
	{
		ll b=inv(arr[i][i]);
		for(int j=0;j<=m;j++) arr[i][j]=arr[i][j]*b%mod;
		for(int j=0;j<n;j++)
		{
			if(i==j) continue;
			ll ti=arr[j][i];
			for(int k=i;k<=m;k++)
			{
				arr[j][k]=(arr[j][k]-ti*arr[i][k]%mod+mod)%mod;
			}
		}
	}
	for(int i=0;i<n;i++) x[i]=arr[i][m];
	
}
ll calc(int cur)
{
	ll ret=x[0];
	for(int i=1;i<11;i++)
	{
		ll tmp=1;
		for(int j=1;j<=i;j++)
		{
			tmp=cur*tmp%mod;
		}
		ret=(ret+x[i]*tmp%mod)%mod;
	}
	return ret;
}
int main()
{
	arr[0][11]=ask(0);
	arr[0][0]=1;
	for(int i=1;i<=10;i++)
	{
		arr[i][0]=1;
		for(int j=1;j<=10;j++)
		{
			int cur=1;
			for(int k=1;k<=j;k++)
				cur=cur*i%mod;
			arr[i][j]=cur;
		}
		arr[i][11]=ask(i);
	}
//	for(int i=0;i<11;i++)
//	{
//		for(int j=0;j<=11;j++)
//			cout<<arr[i][j]<<" ";
//		cout<<endl;
//	}
	gauss(11,11);
	//for(int i=0;i<=11;i++) dbg(i,x[i]);
	ll ans=-1;
	for(int i=0;i<mod;i++)
	{
		if(calc(i)==0) 
		{
			ans=i;
			break;
		}
	}
	cout<<"! "<<ans<<endl;
}