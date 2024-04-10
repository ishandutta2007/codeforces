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
	ll a[3],d;
	cin>>a[0]>>a[1]>>a[2]>>d;
	sort(a,a+3);
	ll ans=0;
	if(a[1]-a[0]<d)
		ans+=d-(a[1]-a[0]);
	if(a[2]-a[1]<d)
		ans+=d-(a[2]-a[1]);
	cout<<ans<<endl;
}