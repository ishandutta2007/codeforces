#include<bits/stdc++.h>
using namespace std;
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
int l[105],r[105];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>l[i]>>r[i];
	int ans=n;
	int last;
	cin>>last;
	for(int i=0;i<n;i++)
	{
		if(last>r[i]) ans--;
		else break;
	}
	cout<<ans<<endl;
}