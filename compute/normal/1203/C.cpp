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
const int maxn=4e5+7;
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	ll ans=0;
	ll tmp;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		ans=__gcd(ans,tmp);
	}
	dbg(ans);
	int ou=0;
	for(ll i=1;i*i<=ans;i++)
	{
		if(ans%i==0)
		{
			ou++;
			if(i*i!=ans)
				ou++;
		}
	}
	cout<<ou<<endl;
}