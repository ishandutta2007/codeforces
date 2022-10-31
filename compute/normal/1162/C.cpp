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
const int maxn=1e5+7;
int ext[maxn];
map<pair<int,int>,int> cnt;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	ll ans=3*n-2;
	for(int i=0,tmp;i<k;i++)
	{
		scanf("%d",&tmp);
		if(!cnt.count(make_pair(tmp,tmp))) ans--;
		cnt[make_pair(tmp,tmp)]++;
		if(ext[tmp-1])
		{
			if(!cnt.count(make_pair(tmp-1,tmp))) {ans--;}
			cnt[make_pair(tmp-1,tmp)]++;
		}
		if(ext[tmp+1])
		{
			if(!cnt.count(make_pair(tmp+1,tmp))) {ans--;}
			cnt[make_pair(tmp+1,tmp)]++;
		}
		ext[tmp]++;
	}
	printf("%lld\n",ans);
}