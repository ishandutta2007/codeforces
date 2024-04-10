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
int arr[maxn];
int pos;
int n,k;
bool check(int cur)
{
	list<int> q;
	for(int i=0;i<n;i++)
	{
		q.push_back(arr[i]);
		while(!q.empty()&&arr[i]-q.front()>2*cur) q.pop_front();
		if(q.size()>=k+1)
		{
			pos=(arr[i]+q.front())/2;
			return true;
		}
	}
	return false;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		int l=0,r=500000009,ans;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(check(mid))
			{
				r=mid-1;
				ans=pos;
			}
			else l=mid+1;
		}
		printf("%d\n",ans);
	}
}