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
string cur;
string s;
bool check(int num)
{
	cur="";
	int dep=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='(') 
		{
			dep++;
			if(dep>num) cur+='0';
			else cur+='1';
		}
		else{
			if(dep>num) cur+='0';
			else cur+='1';
			dep--;
		}
	}
	int dep0=0,dep1=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='(')
		{
			if(cur[i]=='0')
				dep0++;
			else dep1++;
		}
		else{
			if(cur[i]=='0')
				dep0--;
			else dep1--;
		}
		if(dep0>num||dep1>num) return false;
	}
	return true;
}
int main()
{
	int n;
	cin>>n;
	cin>>s;
	int l=1,r=n;
	string ans;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))
			r=mid-1,ans=cur;
		else l=mid+1;
	}
	cout<<ans<<endl;
}