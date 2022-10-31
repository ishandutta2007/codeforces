#include<bits/stdc++.h>
using namespace std;
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
struct song{
	int t,b;
	bool operator<(const song& a)const{
		return t>a.t;
	}
}arr[300005];
bool cmp(const song a,const song b)
{
	return a.b>b.b;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	priority_queue<int,vector<int>,greater<int> > q;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&arr[i].t,&arr[i].b);
	}
	sort(arr,arr+n,cmp);
	int cur=0;
	long long tot=0;
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		cur=arr[i].b;
		q.push(arr[i].t);
		tot+=arr[i].t;
		while(q.size()>k)
		{
			tot-=q.top();
			q.pop();
		}
		ans=max(ans,1LL*tot*cur);
	}
	printf("%lld\n",ans);
}