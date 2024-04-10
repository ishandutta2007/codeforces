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
int cnt[55];
int main()
{
	int n;
	cin>>n;
	int one=0;
	bool same=1;
	int mi=55;
	for(int i=0;i<n;i++)
	{
		cin>>cnt[i];
		mi=min(mi,cnt[i]);
		if(cnt[i]==1) one++;
		if(i&&cnt[i]!=cnt[i-1]) same=0;
	}
	if(one)
	{
		if(one>n/2) cout<<"Bob"<<endl;
		else cout<<"Alice"<<endl;
	}
	else{
		if(same)
		{
			cout<<"Bob"<<endl;
		}
		else
		{
			int ans=0;
			for(int i=0;i<n;i++)
			{
				if(cnt[i]>mi) ans++;
			}
			if(ans>=n/2)
				cout<<"Alice"<<endl;
			else cout<<"Bob"<<endl;
		}
	}
}