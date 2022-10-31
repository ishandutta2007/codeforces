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
int main()
{
	int n;
	string s;
	cin>>n>>s;
	string ans;
	for(int i=0;i<n;i++)
	{
		if(ans=="")
			ans+=s[i];
		else{
			if(ans.length()%2==1&&ans[ans.length()-1]==s[i]) continue;
			else ans+=s[i];
		}
	}
	string op;
	for(int i=0;i<ans.length();i++)
	{
		if(i==ans.length()-1&&(i+1)%2==1) continue;
		op+=ans[i];
	}
	cout<<n-op.length()<<endl;
	cout<<op<<endl;
}