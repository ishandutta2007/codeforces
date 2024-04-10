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
const int maxn=1e7+7;
int arr[maxn/10];
int mp[maxn];
int main()
{
	//db();
	int n;
	ll lcm=1LL<<60;
	int ans1,ans2;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&arr[i]);
		mp[arr[i]]++;
	}
	for(int i=1;i<maxn;i++)
	{
		ll cur1=0,cur2=0;
		for(int j=i;j<maxn;j+=i)
		{
			if(mp[j]>1)
			{
				if(!cur1) cur1=j;
				if(!cur2) cur2=j;
				break;
			}
			else if(mp[j])
			{
				if(!cur1) cur1=j;
				else if(!cur2) cur2=j;
				else break;
			}
		}
		if(cur1&&cur2)
		{
			ll tmp=cur1*cur2/i;
			if(tmp<lcm)
			{
				lcm=tmp;
				ans1=cur1,ans2=cur2;
			}
		}
	}
	int op1,op2;
	for(int i=1;i<=n;i++)
		if(arr[i]==ans1) {op1=i;break;}
	for(int i=1;i<=n;i++)
		if(arr[i]==ans2&&i!=op1) {op2=i;break;}
	if(op1>op2) swap(op1,op2);
	printf("%d %d\n",op1,op2);
	
}