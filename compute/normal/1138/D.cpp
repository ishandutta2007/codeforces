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
const int maxn=5e5+7;
int F[maxn];
void cal_next(string str,int len)
{
	F[0]=-1;
	int j=0,k=-1;
	while(j<len)
	{
		if(k==-1||str[k]==str[j])
			F[++j]=++k;
		else k=F[k];
	}
}
string s,t;
string ans;
string tt;
string sv;
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int zs=0,os=0,zt=0,ot=0;
	cin>>s>>t;
	sv=t;
	sv+='#';
	cal_next(sv,sv.length());
	dbg(F[t.length()]);
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='0') zs++;
		else os++;
	}
	int last=F[t.length()];
	for(int i=0;i<t.length();i++)
	{
		if(t[i]=='0') zt++;
		else ot++;
	}
	int lz=0,lo=0;
	dbg(last);
	for(int i=last;i<t.length();i++)
	{
		if(t[i]=='0') lz++;
		else lo++;
		tt+=t[i];
	}
	dbg(tt);
	if(zt<=zs&&ot<=os)
	{
		ans+=t;
		zs-=zt;
		os-=ot;
		while(lo<=os&&lz<=zs)
		{
			os-=lo,zs-=lz;
			ans+=tt;
		}
	}
	for(int i=0;i<zs;i++)
	{
		ans+='0';
	}
	for(int i=0;i<os;i++)
		ans+='1';
	cout<<ans<<endl;
}