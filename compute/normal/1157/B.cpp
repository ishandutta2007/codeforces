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
int f[100];
int main()
{
	int n;
	cin>>n;
	string a;
	cin>>a;
	for(int i=1;i<=9;i++) cin>>f[i];
	bool st=0;
	for(int i=0;i<a.length();i++)
	{
		int cur=a[i]-'0';
		if(!st)
		{
			if(cur<f[cur])
			{
				st=1;
				a[i]=f[cur]+'0';
			}
		}
		else{
			if(f[cur]<cur) break;
			else a[i]=f[cur]+'0';
		}
	}
	cout<<a<<endl;
}