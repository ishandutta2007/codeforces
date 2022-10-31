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
const int maxn=2e5+7;
bool isprime[maxn*2];
void db()
{
	memset(isprime,1,sizeof(isprime));
	isprime[1]=0;
	for(int i=2;i<maxn*2;i++)
	{
		if(isprime[i])
		{
			for(int j=i*2;j<maxn*2;j+=i)
				isprime[j]=0;
		}
	}
}
int main()
{
	db();
	int n;
	scanf("%d",&n);
	int cnt1=0,cnt2=0;
	vector<int> ans;
	for(int i=0,tmp;i<n;i++)
	{
		scanf("%d",&tmp);
		if(tmp==1) cnt1++;
		else cnt2++;
	}
	int cur=0;
	while(cnt1||cnt2)
	{
		if(isprime[cur+1]&&cnt1) {cnt1--,cur++;ans.push_back(1);}
		else if(isprime[cur+2]&&cnt2){cnt2--,cur+=2;ans.push_back(2);}
		else{
			if(cnt1>cnt2) {ans.push_back(1);cnt1--;cur++;}
			else {ans.push_back(2);cnt2--;cur+=2;}
		}
	}
	for(auto p:ans) printf("%d ",p);
	puts("");
}