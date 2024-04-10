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
const int maxn=1e6+7;
int arr[maxn];
vector<int> all;
int fi[maxn],las[maxn];
int n,x;
int suff;
int getpos(int pos)
{
	int l=max(pos+1,suff),r=x+1,ret=x+1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(fi[mid]>=las[pos]) r=mid-1,ret=mid;
		else l=mid+1;
	}
	dbg(pos,ret);
	return ret-(ret!=pos+1);
}
int main()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&arr[i]);
		all.push_back(arr[i]);
	}
	for(int i=1;i<=n;i++)
		las[arr[i]]=i;
	for(int i=n;i>=1;i--)
		fi[arr[i]]=i;
	int pref=0;
	int cur=0;
	for(int i=1;i<=x;i++)
	{
		if(!fi[i])
			pref=i;
		else if(fi[i]<cur) break;
		else {
			pref=i;
			cur=las[i];
		}
	}
	cur=n+1;
	for(int i=x;i>=1;i--)
	{
		if(!las[i])
			suff=i;
		else if(las[i]>cur) break;
		else{
			suff=i;
			cur=fi[i];
		}
	}
	ll ans=0;
	fi[x+1]=n;
	for(int i=1;i<=x;i++)
		if(!las[i]) las[i]=las[i-1];
	for(int i=x;i>=1;i--)
		if(!fi[i]) fi[i]=fi[i+1];
	//dbg(pref,suff);
	//for(int i=1;i<=x;i++) dbg(i,fi[i],las[i]);
	for(int i=0;i<=pref;i++)
	{
		ans+=x-getpos(i)+1;
		//dbg(ans);
	}
	printf("%lld\n",ans);
}