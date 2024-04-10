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
int t[maxn];
int ans[maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&t[i]);
	for(int i=0;i<n;i++)
	{
		priority_queue<int> q;
		int tot=t[i];
		for(int j=0;j<i;j++)
		{
			tot+=t[j];
			q.push(t[j]);
		}
		int cnt=0;
		while(tot>m)
		{
			cnt++;
			tot-=q.top();
			q.pop();
		}
		ans[i]=cnt;
		printf("%d%c",ans[i],i==n-1?'\n':' ');
	}

}