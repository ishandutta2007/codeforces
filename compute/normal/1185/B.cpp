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
struct node{
	char ch;
	int cnt;
};
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string s;
		cin>>s;
		string t;
		cin>>t;
		vector<node> all,cur;
		all.push_back(node {s[0],1});
		for(int i=1;i<s.length();i++)
		{
			if(s[i]==all.back().ch)
				all.back().cnt++;
			else all.push_back(node{s[i],1});
		}
		cur.push_back(node {t[0],1});
		for(int i=1;i<t.length();i++)
		{
			if(t[i]==cur.back().ch)
				cur.back().cnt++;
			else cur.push_back(node {t[i],1});
		}
		bool ok=1;
		if(cur.size()!=all.size()) ok=0;
		if(ok)
		{
			for(int i=0;i<cur.size();i++)
		{
			if(cur[i].ch!=all[i].ch||cur[i].cnt<all[i].cnt)
			{
				ok=0;break;
			}
		}
		}
		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
}