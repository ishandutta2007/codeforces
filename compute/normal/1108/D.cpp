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
char col[]={'R','G','B'};
int main()
{
	int n;
	string s;
	cin>>n>>s;
	string ans;
	int cnt=0;
	ans+=s[0];
	for(int i=1;i<n;i++)
	{
		if(s[i]==s[i-1])
		{
			cnt++;
			for(int j=0;j<3;j++)
			{
				if(col[j]!=s[i-1]&&col[j]!=s[i+1])
				{
					s[i]=col[j];
					ans+=col[j];
					break;
				}
			}
		}
		else ans+=s[i];
	}
	cout<<cnt<<endl;
	cout<<ans<<endl;
}