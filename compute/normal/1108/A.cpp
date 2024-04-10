#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m" << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
const int INF=0x3f3f3f3f;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		int ans1=l1,ans2=l2;
		if(ans1==ans2) ans2++;
		dbg(ans1);
		dbg(ans2);
		printf("%d %d\n",ans1,ans2);
	}
}