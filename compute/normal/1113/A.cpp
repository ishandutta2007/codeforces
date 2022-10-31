#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "the" << #x << " -> "; err(x); } while (0)
void err() { cout << "" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
const int INF=0x3f3f3f3f;

int main()
{
	int n,v;
	cin>>n>>v;
	n--;
	int ans=0;
	if(v>n) ans=n;
	else{
		ans=v;
		for(int i=2;i<2+n-v;i++) ans+=i;
	}
	cout<<ans<<endl;
}