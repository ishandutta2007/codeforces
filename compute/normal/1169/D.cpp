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
	string s;
	cin>>s;
	ll ans=0;
	int pre=s.length();
	for(int i=s.length()-1;i>=0;i--)
	{
		for(int k=1;i+2*k<pre;k++)
		{
			if(s[i]==s[i+k]&&s[i+k]==s[i+2*k])
			{
				pre=i+2*k;
				break;
			}
		}
		ans+=s.length()-pre;
	}
	cout<<ans<<endl;
}