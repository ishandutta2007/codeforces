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
	int n;
	scanf("%d",&n);
	vector<int> odd,even,all;
	for(int i=0,tmp;i<n;i++)
	{
		scanf("%d",&tmp);
		if(tmp%2==0) even.push_back(tmp);
		else odd.push_back(tmp);
		all.push_back(tmp);
	}
	if(odd.size()&&even.size()) sort(all.begin(),all.end());
	for(int i=0;i<all.size();i++)
		printf("%d ",all[i]);
	puts("");
}