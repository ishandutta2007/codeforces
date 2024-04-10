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
const int maxn=2e5+7;
int pre[maxn];
int two[30];
int main()
{
	int t;
	cin>>t;
	two[0]=1;
	for(int i=1;i<=20;i++) two[i]=two[i-1]*2;
	while(t--)
	{
		string s;
		cin>>s;
		int ans=0;
		int cur=-1;
		for(int i=0;i<s.length();i++)
		{
			pre[i]=cur;
			if(s[i]=='1') cur=i;
		}
		for(int i=s.length()-1;i>=0;i--)
		{
			int val=s[i]=='1';
			int j=i;
			do{
				int len=i-j+1;
				dbg(i,j);
				int nxt=pre[j];
				if(val>=len&&val<=i-nxt) 
				{
					dbg(33);
					ans++;
				}
				j=pre[j];
				if(j!=-1&&i-j<=20) val+=two[i-j];
				else break;
			}while(1);
		}
		cout<<ans<<endl;
	}
}