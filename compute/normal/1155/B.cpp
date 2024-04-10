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
	int cnt=0;
	int ell=0;
	for(int i=0;i<s.length()-10;i++)
	{
		if(s[i]=='8')
		{
			cnt++;
		}
		else ell++;
	}
	if(cnt>ell) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}