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
const int maxn=2e5+7;
long long arr[maxn];
int n,m;
bool check(int cur)
{
	long long tot=0;
	for(int i=1;i<=cur;i++) tot+=arr[i];
	int cnt=0,rd=1;
	for(int i=cur+1;i<=n;i++)
	{
		tot+=max(0LL,arr[i]-rd);
		cnt++;
		if(cnt==cur) cnt=0,rd++;
	}
	dbg(cur);dbg(tot);
	return tot>=m;
}
int main()
{
	scanf("%d%d",&n,&m);
	int ed=-1;
	for(int i=1;i<=n;i++) 
		scanf("%lld",&arr[i]);
	sort(arr+1,arr+1+n,greater<int>());
	int l=1,r=n+1,ans=-1;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid)) r=mid,ans=mid;
		else l=mid+1;
	}
	printf("%d\n",ans);
}