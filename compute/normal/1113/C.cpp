#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "the " << #x << " -> "; err(x); } while (0)
void err() { cout << "" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
const int maxn=3e5+7;
const int INF=0x3f3f3f3f;
int arr[maxn];
map<int,int> odd,even;

int main()
{
	int n;
	scanf("%d",&n);
	long long ans=0;
	int cur=0;
	even[0]++;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&arr[i]);
		cur^=arr[i];
		if(i%2==0) ans+=even[cur],even[cur]++;
		else ans+=odd[cur],odd[cur]++;
		dbg(cur);
		dbg(even[cur]);
		dbg(ans);
	}
	printf("%lld\n",ans);
}