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
	cin>>T;
	srand(time(NULL));
	while(T--)
	{
		int cnt[27];
		memset(cnt,0,sizeof(cnt));
		vector<int> all;
		string s;
		cin>>s;
		for(int i=0;i<s.length();i++)
			cnt[s[i]-'a']++;
		for(int i=0;i<26;i++)
			if(cnt[i]) all.push_back(i);
		int ti=100000;
		while(ti-->0)
		{
			random_shuffle(all.begin(),all.end());
			bool ok=1;
			for(int i=1;i<all.size();i++)
				ok&=(abs(all[i]-all[i-1])>1);
			if(ok) break;
		}
		if(ti<0) cout<<"No answer"<<endl;
		else{
			for(int i=0;i<all.size();i++)
			{
				for(int j=0;j<cnt[all[i]];j++)
					cout<<char(all[i]+'a');
			}
			cout<<endl;
		}
	}
}