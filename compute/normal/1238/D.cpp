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
	int n;
	cin>>n;
	string s;
	cin>>s;
	ll ans=1LL*n*(n-1)/2;
	int cur=1;
	for(int i=1;i<s.length();i++)
	{
		if(s[i]==s[i-1])
			cur++;
		else{
			ans-=cur;
			cur=1;
		}
	}
	dbg(ans);
	cur=1;
	for(int i=s.length()-2;i>=0;i--)
	{
		if(s[i]==s[i+1])
			cur++;
		else{
			ans-=cur;
			cur=1;
		}
	}
	for(int i=0;i<s.length()-1;i++)
		if(s[i]!=s[i+1]) ans++;
	cout<<ans<<endl;
}