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
string op[6];
string col[6]={"RGB","GBR","BRG","BGR","RBG","GRB"};
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int ans=0x3f3f3f3f;
	int indx=0;
	for(int i=0;i<6;i++)
	{
		int cnt=0;
		for(int j=0;j<n;j++)
		{
			op[i]+=col[i][j%3];
		}
		for(int j=0;j<n;j++)
		{
			if(op[i][j]!=s[j]) cnt++;
		}
		if(cnt<ans)
		{
			ans=cnt;
			indx=i;
		}
	}
	cout<<ans<<endl;
	cout<<op[indx]<<endl;

}