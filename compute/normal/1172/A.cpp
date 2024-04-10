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
const int maxn=2e5+7;
int pos[maxn];
int arr[maxn];
vector<int> hand;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0,tmp;i<n;i++)
	{
		scanf("%d",&tmp);
		hand.push_back(tmp);
	}
	int one=0;
	for(int i=1,tmp;i<=n;i++)
	{
		scanf("%d",&tmp);
		if(tmp==1) one=i;
		arr[i]=tmp;
		pos[tmp]=i;
	}
	int ans=0;
	bool ok=one;
	int las=-1;
	if(one)
	{
		for(int i=one;i<=n;i++)
		{
			if(arr[i]!=i-one+1)
				ok=0;
		}
		if(ok) ans=one-1;
		las=n-ans;
	}
	if(ok&&las!=-1)
	{
		dbg(las);
		for(int i=1;i<one;i++)
			if(arr[i]&&arr[i]-las<=i) ok=0;
	}
	if(!ok)
	{
		ans=0;
		for(int i=1;i<=n;i++)
			ans=max(ans,pos[i]-i+1);
		dbg(ans);
	}
	printf("%d\n",ans+(ok?0:n));

}