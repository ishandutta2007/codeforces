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
vector<int> ll[30],rr[30];
vector<int> ln,rn;
vector<pair<int,int> > ans;
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	string l,r;
	cin>>l>>r;
	for(int i=0;i<n;i++)
	{
		if(l[i]=='?') ln.push_back(i+1);
		else ll[l[i]-'a'].push_back(i+1);
		if(r[i]=='?') rn.push_back(i+1);
		else rr[r[i]-'a'].push_back(i+1);
	}
	for(int i=0;i<30;i++)
	{
		for(int j=0;j<(int)min((int)ll[i].size(),(int)rr[i].size());j++)
		{
			ans.push_back(make_pair(ll[i][j],rr[i][j]));
		}
	}
	int curl=0,curr=0;
	for(int i=0;i<30;i++)
	{
		for(int j=(int)min(ll[i].size(),rr[i].size());j<rr[i].size();j++)
		{
			if(curl>=ln.size()) break;
			ans.push_back(make_pair(ln[curl++],rr[i][j]));
		}
		for(int j=(int)min(ll[i].size(),rr[i].size());j<ll[i].size();j++)
		{
			if(curr>=rn.size()) break;
			ans.push_back(make_pair(ll[i][j],rn[curr++]));
		}
	}
	while(curl<ln.size()&&curr<rn.size())
	{
		ans.push_back(make_pair(ln[curl],rn[curr]));
		curl++,curr++;
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
}