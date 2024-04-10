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
const int maxn=50;
int hi[maxn];
int main()
{
	int n,h,m;
	cin>>n>>h>>m;
	for(int i=1;i<=n;i++) hi[i]=h;
	while(m--)
	{
		int l,r,x;
		cin>>l>>r>>x;
		for(int i=l;i<=r;i++) hi[i]=min(hi[i],x);
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans+=hi[i]*hi[i];
	cout<<ans<<endl;
}