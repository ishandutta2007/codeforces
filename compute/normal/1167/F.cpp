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
const int maxn=5e5+7;
const int mod=1e9+7;
int arr[maxn];
ll tree[maxn];
vector<int> all;
int getid(int x)
{
	return lower_bound(all.begin(),all.end(),x)-all.begin()+1;
}
void add(int x,int val,int ty)
{
	if(ty==1)
	{
		while(x<maxn)
		{
			tree[x]=(tree[x]+val)%mod;
			x+=x&-x;
		}
	}
	else{
		while(x>0)
		{
			tree[x]=(tree[x]+val)%mod;
			x-=x&-x;
		}
	}
}
ll query(int x,int ty)
{
	ll ret=0;
	if(ty==1)
	{
		while(x>0)
		{
			ret=(ret+tree[x])%mod;
			x-=x&-x;
		}
	}
	else{
		while(x<maxn)
		{
			ret=(ret+tree[x])%mod;
			x+=x&-x;
		}
	}
	return ret;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		all.push_back(arr[i]);
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ll pos=query(getid(arr[i]),0);
		ans=(ans+pos*(n-i+1)%mod)%mod;
		add(getid(arr[i]),1LL*i*arr[i]%mod,0);
		dbg(i,ans);
	}
	memset(tree,0,sizeof(tree));
	for(int i=n;i>=1;i--)
	{
		ll pos=query(getid(arr[i]),0);
		ans=(ans+pos*i%mod)%mod;
		add(getid(arr[i]),1LL*(n-i+1)*arr[i]%mod,0);
		dbg(i,ans);
	}
	for(int i=1;i<=n;i++)
	{
		ans=(ans+1LL*i*(n-i+1)%mod*arr[i]%mod)%mod;
	}
	printf("%lld\n",ans);
}