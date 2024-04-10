#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int main()
{
	int n,x,y;
	cin>>n>>x>>y;
	string s;
	cin>>s;
	int ans=0;
	reverse(s.begin(),s.end());
	swap(x,y);
	if(s[x]=='0') ans++;
	for(int i=0;i<y;i++)
	{
		if(i==x) continue;
		if(s[i]=='1') ans++;
		dbg(i,ans);
	}
	cout<<ans<<endl;

}