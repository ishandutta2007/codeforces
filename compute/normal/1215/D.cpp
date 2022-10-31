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
	int n;
	string s;
	cin>>n>>s;
	int ls=0,rs=0,lq=0,rq=0;
	for(int i=0;i<n/2;i++)
	{
		if(s[i]=='?') lq++;
		else ls+=s[i]-'0';
	}
	for(int i=n/2;i<n;i++)
	{
		if(s[i]=='?') rq++;
		else rs+=s[i]-'0';
	}
	if(lq>rq)
	{
		swap(lq,rq);
		swap(ls,rs);
	}
	if(lq==rq)
	{
		if(ls==rs)
			cout<<"Bicarp"<<endl;
		else cout<<"Monocarp"<<endl;
	}
	else{
		rq-=lq;
		int delta=rs-ls;
		if(delta>0)
			cout<<"Monocarp"<<endl;
		else{
			if(delta+rq/2*9!=0)
				cout<<"Monocarp"<<endl;
			else cout<<"Bicarp"<<endl;
		}
	}

}