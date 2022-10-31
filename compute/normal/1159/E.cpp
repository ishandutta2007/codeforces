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
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		vector<int> all(n+5);
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&all[i]);
			if(all[i]==-1) all[i]=i+1;
		}
		stack<int> st;
		bool ok=1;
		vector<int> ans(n+5);
		int cur=0;
		for(int i=1;i<=n+1;i++)
		{
			while(!st.empty()&&all[st.top()]==i)
			{
				ans[st.top()]=++cur;
				st.pop();
			}
			st.push(i);
		}
		for(int i=1;i<=n;i++) if(ans[i]==0) ok=0;
		if(!ok) 
		{
			puts("-1");
			continue;
		}
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
		puts("");
	}
}