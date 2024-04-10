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
	ll x[4];
	for(int i=0;i<4;i++) cin>>x[i];
	sort(x,x+4);
	ll a,b,c;
	c=x[3]-x[0];
	b=x[2]-c;
	a=x[1]-c;
	
	cout<<a<<" "<<b<<" "<<c<<endl;
	
}