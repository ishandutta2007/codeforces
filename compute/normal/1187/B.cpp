#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int maxn=2e5+7;
int cnt[maxn][27];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<26;j++)
			cnt[i+1][j]=cnt[i][j];
		cnt[i+1][s[i]-'a']++;
	}
	int m;
	cin>>m;
	while(m--)
	{
		string t;
		cin>>t;
		int cur[26];
		memset(cur,0,sizeof(cur));
		for(int i=0;i<t.length();i++)
			cur[t[i]-'a']++;
		int l=1,r=n,ans=0;
		while(l<=r)
		{
			int mid=l+r>>1;
			bool ok=1;
			for(int i=0;i<26;i++)
				if(cnt[mid][i]<cur[i]) ok=0;
			if(ok) ans=mid,r=mid-1;
			else l=mid+1;
		}
		cout<<ans<<endl;
	}
}