#include<bits/stdc++.h>
using namespace std;
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
	int n;
	string s;
	cin>>n;
	cin>>s;
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		int cur=s[i]-'0';
		if(cur%2==0) ans+=i+1;
	}
	cout<<ans<<endl;
}