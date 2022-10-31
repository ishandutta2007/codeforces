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
const int maxn=2e5+7;
int arr[maxn];
map<long long,int> ext;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++) cin>>arr[i];
	bool ok=1;
	ext[0]=1;
	long long cur=0;
	long long mi=0;
	long long ma=0;
	for(int i=0;i<n-1;i++)
	{
		cur+=arr[i];
		ma=max(ma,cur);
		mi=min(mi,cur);
		if(ext.count(cur)) ok=0;
		else ext[cur]=1;
	}
	if(!ok||(ma-mi+1)>n) cout<<-1<<endl;
	else{
		cur=-mi+1;
		cout<<cur<<" ";
		for(int i=0;i<n-1;i++)
		{
			cur+=arr[i];
			cout<<cur<<" ";
		}
		cout<<endl;
	}
}