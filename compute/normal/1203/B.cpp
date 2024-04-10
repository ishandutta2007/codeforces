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
const int maxn=1e4+7;
int cnt[maxn];
int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		memset(cnt,0,sizeof(cnt));
		int n;
		cin>>n;
		for(int i=0,tmp;i<4*n;i++)
		{
			cin>>tmp;
			cnt[tmp]++;
		}
		vector<PII> all;
		for(int i=1;i<=10000;i++)
		{
			if(cnt[i])
			{
				all.push_back(make_pair(i,cnt[i]));
			}
		}
		bool ok=1;
		int tar=all[0].first*all[all.size()-1].first;
		for(int i=0;i<all.size();i++)
		{
			int rev=all.size()-1-i;
			if(i==rev)
			{
				if(all[i].first*all[i].first!=tar||all[i].second%4!=0) ok=0;
				break;
			}
			if(all[i].second!=all[rev].second||all[i].second%2!=0||all[rev].second%2!=0||all[i].first*all[rev].first!=tar) 
			{
				ok=0;
				break;
			}
		}
		if(ok) puts("YES");
		else puts("NO");
	}
}