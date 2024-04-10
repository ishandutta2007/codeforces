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
int change(char a,char b)
{
	if(a<b) swap(a,b);
	return min(a-b,b-'A'+'Z'-a+1);
}
int main()
{
	int n;
	cin>>n;
	string s;
	string tar="ACTG";
	int mx=0x3f3f3f3f;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		int cur=0;
		if(i+4>n) break;
		for(int j=0;j<4;j++)
		{
			dbg(i,j);
			cur+=change(s[i+j],tar[j]);
			dbg(cur);
		}
		mx=min(mx,cur);
	}
	cout<<mx<<endl;
}