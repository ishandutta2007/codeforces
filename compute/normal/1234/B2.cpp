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
	int n,k;
	scanf("%d%d",&n,&k);
	deque<int> dq;
	set<int> ext;
	for(int i=0,tmp;i<n;i++)
	{
		scanf("%d",&tmp);
		if(ext.count(tmp)) continue;
		if(dq.size()==k)
		{
			ext.erase(dq.back());
			dq.pop_back();
		}
		dq.push_front(tmp);
		ext.insert(tmp);
	}
	printf("%d\n",(int)dq.size());
	for(auto u:dq)
		printf("%d ",u);
	puts("");

}