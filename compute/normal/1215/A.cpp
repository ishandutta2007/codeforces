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
	int a1,a2,k1,k2;
	int n;
	cin>>a1>>a2>>k1>>k2>>n;
	int lim=a1*(k1-1)+a2*(k2-1);
	int ans1=max(0,n-lim);
	int ans2=0;
	if(k1>k2)
	{
		swap(k1,k2);
		swap(a1,a2);
	}
	if(n>a1*k1)
		ans2=a1+(n-a1*k1)/k2;
	else ans2=n/k1;
	cout<<ans1<<" "<<ans2<<endl;

}