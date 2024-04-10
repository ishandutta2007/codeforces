#include<bits/stdc++.h>
using namespace std;
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
int len[]={1,3,6,10,15,21,28,36,45,55};
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	string ans;
	int cur=1;
	int step=2;
	while(cur<=n)
	{
		ans+=s[cur-1];
		cur+=step;
		step++;
	}
	cout<<ans<<endl;
}