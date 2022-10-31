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
	int n;
	cin>>n;
	string s;
	cin>>s;
	int l,r;
	bool ok=0;
	char mx=s[0];
	l=1;
	for(int i=1;i<n;i++)
	{
		if(s[i]>=mx)
		{
			mx=s[i];
			l=i+1;
		}
		else {
			ok=1;r=i+1;break;
		}
	}
	if(ok)
	{
		cout<<"YES"<<endl;
		cout<<l<<" "<<r<<endl;
	}
	else cout<<"NO"<<endl;
}