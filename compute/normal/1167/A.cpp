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
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		reverse(s.begin(),s.end());
		bool ok=0;
		for(int i=10;i<s.length();i++)
		{
			if(s[i]=='8') ok=1;
		}
		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}