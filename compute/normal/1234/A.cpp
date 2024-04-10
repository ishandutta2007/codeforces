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
	int q;
	cin>>q;
	while(q--)
	{
		int n;
		cin>>n;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			int tmp;
			cin>>tmp;
			sum+=tmp;
		}
		int ans=(sum+n-1)/n;
		cout<<ans<<endl;
	}
}