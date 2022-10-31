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
int pos[maxn];
int arr[maxn];
int st[maxn],ed[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1,tmp;i<=n;i++)
	{
		scanf("%d",&tmp);
		arr[i]=tmp;
		pos[tmp]=i;
	}
	stack<int> s;
	for(int i=1;i<=n;i++)
	{
		while(!s.empty()&&arr[s.top()]<arr[i])
		{
			ed[s.top()]=i-1;
			s.pop();
		}
		if(s.empty()) st[i]=1;
		else st[i]=s.top()+1;
		s.push(i);
	}
	while(!s.empty()) {ed[s.top()]=n;s.pop();}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=st[i],r=ed[i];
		int cur=arr[i];
		if(i-l<r-i)
		{
			for(int j=l;j<i;j++)
			{
				if(pos[cur-arr[j]]<=r&&pos[cur-arr[j]]>i) ans++;
			}
		}
		else{
			for(int j=i+1;j<=r;j++)
			{
				if(pos[cur-arr[j]]>=l&&pos[cur-arr[j]]<i) ans++;
			}
		}
	}
	printf("%lld\n",ans);


}