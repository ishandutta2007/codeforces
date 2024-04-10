#include<bits/stdc++.h>
using namespace std;
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
	int n;
	cin>>n;
	int zero=0;
	int pos=0,neg=0;
	for(int i=0;i<n;i++)
	{
		int tmp;
		cin>>tmp;
		if(tmp>0) pos++;
		else if(tmp==0) zero++;
		else neg++;
	}
	int var=(n+1)/2;
	if(pos>=var) cout<<1<<endl;
	else if(neg>=var) cout<<-1<<endl;
	else cout<<0<<endl;
}