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
int main()
{
	int h1,h2,m1,m2;
	char ch;
	cin>>h1>>ch>>m1;
	cin>>h2>>ch>>m2;
	if(h1==h2)
	{
		if(h1<10) cout<<0<<h1;
		else cout<<h1;
		cout<<":";
		int mi=(m1+m2)/2;
		if(mi<10) cout<<0<<mi<<endl;
		else cout<<mi<<endl;
	}
	else{
		int delta=60*h2+m2-60*h1-m1;
		int st=60*h1+m1;
		int t=delta/2+st;
		dbg(t);
		if(t/60<10) cout<<0<<t/60;
		else cout<<t/60;
		cout<<":";
		if(t%60<10) cout<<0<<t%60<<endl;
		else cout<<t%60<<endl;
	}
}