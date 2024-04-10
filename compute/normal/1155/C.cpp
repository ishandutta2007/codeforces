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
const int maxn=3e5+7;
ll arr[maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	ll gcd=0;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&arr[i]);
		if(i)
			gcd=__gcd(gcd,arr[i]-arr[i-1]);
	}
	bool ok=0;
	ll ans=0;
	for(int i=0;i<m;i++)
	{
		ll tmp;
		scanf("%lld",&tmp);
		if(gcd%tmp==0) 
		{
			ok=1;ans=i+1;
		}
	}
	if(!ok) cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
		cout<<arr[0]<<" "<<ans<<endl;
	}
}