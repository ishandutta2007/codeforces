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
const int maxn=1e5+7;
int arr[maxn];
typedef pair<int,int> PII;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) 
	{
		scanf("%d",&arr[i]);
	}
	vector<PII> all;
	all.push_back(make_pair(arr[0],1));
	for(int i=1;i<n;i++)
	{
		PII cur=all.back();
		if(arr[i]==cur.first)
		{
			all.pop_back();
			cur.second++;
			all.push_back(cur);
		}
		else all.push_back(make_pair(arr[i],1));
	}
	int ans=0;
	for(int i=1;i<all.size();i++)
	{
		ans=max(ans,min(all[i].second,all[i-1].second));
	}
	printf("%d\n",ans*2);

}