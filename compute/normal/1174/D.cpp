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
const int maxn=1<<19;
bool vis[maxn];
int main()
{
	int n,x;
	cin>>n>>x;
	vis[x]=1;
	vector<int> all;
	all.push_back(0);
	for(int i=1;i<(1<<n);i++)
	{
		if(!vis[i])
		{
			all.push_back(i);
			vis[i^x]=1;
		}
	}
	dbg(all);
	vector<int> ans;
	for(int i=1;i<all.size();i++)
		ans.push_back(all[i]^all[i-1]);
	cout<<ans.size()<<endl;
	for(auto u:ans)
		cout<<u<<" ";
	cout<<endl;

}