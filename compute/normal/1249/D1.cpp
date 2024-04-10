#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
set<PII> cur;
int p[maxn];
vector<PII> add[maxn];
int main()
{
	int n,k;
	cin>>n>>k;
	int cc=0;
	vector<int> ans;
	for(int i=1,l,r;i<=n;i++)
	{
		cin>>l>>r;
		p[l]++;
		p[r+1]--;
		add[l].push_back(make_pair(r,i));
	}
	for(int i=1;i<maxn;i++)
	{
		for(auto u:add[i])
			cur.insert(u);
		cc+=p[i];
		while(cc>k)
		{
			ans.push_back((*cur.rbegin()).second);
			p[(*cur.rbegin()).first+1]++;
			cur.erase(cur.find(*cur.rbegin()));
			cc--;
		}
	}
	cout<<ans.size()<<endl;
	for(auto u:ans) cout<<u<<" ";
	cout<<endl;

}