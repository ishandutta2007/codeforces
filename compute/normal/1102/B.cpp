#include<bits/stdc++.h>
using namespace std;
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
const int maxn=5005;
vector<int> bin[maxn];
int ans[maxn];
int main()
{
	int n,k;
	int ok=0;
	cin>>n>>k;
	int ma=0;
	for(int i=0,temp;i<n;i++)
	{
		cin>>temp;
		if(!ok&&temp<=k)
		{
			ok=temp;
			ans[i]=temp;
		}
		else{
			bin[temp].push_back(i);
		}
		ma=max(ma,(int)bin[temp].size()+(ok==temp));
	}
	if(ma>k) cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
		int cnt=ok%k+1;
		for(int i=0;i<maxn;i++)
		{
			for(int j=0;j<bin[i].size();j++)
			{
				int cur=bin[i][j];
				if(i==ok&&cnt==ok) cnt=cnt%k+1;
				ans[cur]=cnt;
				cnt=cnt%k+1;
			}
		}
		for(int i=0;i<n;i++)
			 cout<<ans[i]<<" ";
		cout<<endl;
	}
}