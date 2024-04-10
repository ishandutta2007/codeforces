#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
const int mod=998244353;
const int INF=0x3f3f3f3f;
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
int n;
string s,t;
inline bool check(const string& cur)
{
	//if(cur.find(s)!=string::npos||cur.find(t)!=string::npos) return false;
	for(int i=1;i<cur.length();i++)
	{
		if(cur[i]==s[1]&&cur[i-1]==s[0]) return false;
		if(cur[i]==t[1]&&cur[i-1]==t[0]) return false;
	}
	return true;
}
string solve()
{
	string c="abc";
	do{
		string ret="";
		for(int i=0;i<n;i++)
			ret+=c;
		if(check(ret)) return ret;
		ret="";
		for(int i=0;i<n;i++)
			ret+=c[0];
		for(int i=0;i<n;i++)
			ret+=c[1];
		for(int i=0;i<n;i++)
			ret+=c[2];
		if(check(ret)) return ret;
	}while(next_permutation(c.begin(),c.end()));
	assert(false);
}
int main()
{
	cin>>n;
	cin>>s>>t;
	string ans=solve();
	cout<<"YES"<<endl;
	cout<<ans<<endl;
}