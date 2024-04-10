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
	int n,a,x,b,y;
	cin>>n>>a>>x>>b>>y;
	bool ok=0;
	for(int i=1;i<=n;i++)
	{
		a=a%n+1;
		b--;
		if(b==0) b=n;
		if(a==b){
			ok=1;break;
		}
		if(a==x||b==y) break;
	}
	if(ok) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}