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
	int T;
	cin>>T;
	while(T--)
	{
		int s,i,e;
		cin>>s>>i>>e;
		int l=0,r=e,ans=0;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(s+mid>i+(e-mid))
			{
				ans=e-mid+1;
				r=mid-1;
			}
			else l=mid+1;
			dbg(l,r,ans);
		}
		cout<<ans<<endl;
	}
}