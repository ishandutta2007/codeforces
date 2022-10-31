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
int f(int n)
{
	n++;
	while(n%10==0) n/=10;
	return n;
}
map<int,int> vis;
int main()
{
	int n;
	cin>>n;
	int ans=0;
	do{
		vis[n]=1;
		n=f(n);
		ans++;
	}while(!vis.count(n));
	cout<<ans<<endl;
}