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
int c,m,x;
bool check(int cur)
{
	int rm=c-cur+m-cur+x;
	return rm>=cur;
}
int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		cin>>c>>m>>x;
		int l=0,r=min(c,m);
		int ans=0;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(check(mid))
			{
				l=mid+1;
				ans=mid;
			}
			else r=mid-1;
		}
		cout<<ans<<endl;
	}
}