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
		ll n,m;
		cin>>n>>m;
		ll cnt=n/m;
		int lp=0;
		ll sum=0;
		static map<int,int> vis;
		static vector<int> all;
		all.clear();
		vis.clear();
		int ii=1;
		int cur=m%10;
		while(!vis.count(cur))
		{
			vis[cur]=1;
			all.push_back(cur);
			sum+=cur;
			ii++;
			cur=1LL*ii*m%10;
		}
		ii--;
		dbg(cnt,sum);
		dbg(all);
		ll ans=sum*(cnt/ii);
		for(int i=0;i<cnt%ii;i++)
			ans+=all[i];
		cout<<ans<<endl;
	}
}