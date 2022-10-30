#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
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
const int maxn=105;
struct Blow{
	int d,h;
}b[maxn];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,x;
		cin>>n>>x;
		int mx=0,delta=-INF;
		for(int i=0;i<n;i++)
		{
			cin>>b[i].d>>b[i].h;
			mx=max(mx,b[i].d);
			delta=max(delta,b[i].d-b[i].h);
		}
		if(delta<=0&&mx<x) cout<<-1<<endl;
		else{
			int ans=1;
			x-=mx;
			if(x>0)
				ans+=(x+delta-1)/delta;
			cout<<ans<<endl;
		}
	}
}