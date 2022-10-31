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
int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		int n;
		cin>>n;
		string s[2];
		cin>>s[0]>>s[1];
		bool up=1,down=0;
		for(int i=0;i<n;i++)
		{
			if(s[0][i]=='2') s[0][i]='1';
			if(s[1][i]=='2') s[1][i]='1';
			if(s[0][i]>'2') s[0][i]='3';
			if(s[1][i]>'2') s[1][i]='3';
			bool nxtup=0,nxtdown=0;
			if(up)
			{
				if(s[0][i]==s[1][i]&&s[1][i]=='3') nxtdown=1;
				if(s[0][i]=='1') nxtup=1;
			}
			if(down)
			{
				if(s[1][i]=='1') nxtdown=1;
				if(s[0][i]==s[1][i]&&s[1][i]=='3') nxtup=1;
			}
			up=nxtup;down=nxtdown;
		}
		if(down) cout<<"YES\n";
		else cout<<"NO\n";
	}
}