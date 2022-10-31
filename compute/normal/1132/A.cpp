#include<bits/stdc++.h>
using namespace std;
#ifndef Online_Judge
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
	long long cnt1,cnt2,cnt3,cnt4;
	cin>>cnt1>>cnt2>>cnt3>>cnt4;
	if(!cnt3)
	{
		if(cnt1==cnt4) cout<<1<<endl;
		else cout<<0<<endl;
	}
	else{
		if(cnt1==0&&cnt4==0) cout<<0<<endl;
		else if(cnt1==cnt4) cout<<1<<endl;
		else cout<<0<<endl;
	}
}