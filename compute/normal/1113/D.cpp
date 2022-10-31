#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "the " << #x << " -> "; err(x); } while (0)
void err() { cout << "" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
const int maxn=3e5+7;
const int INF=0x3f3f3f3f;
bool ok=1;
bool check(string s,int len)
{
	if(!s.length()) return false;
	for(int i=0;i<len;i++)
		if(s[i]!=s[len-1-i]) return false;
	return true;
}
int main()
{
	std::ios::sync_with_stdio(false);
	string s;
	cin>>s;
	int ans=0;
	int same=1;
	for(int i=1;i<s.length();i++) 
	{
		if(s.length()%2&&(i==s.length()/2||i==s.length()/2+1)) continue;
		if(s[i]!=s[i-1]) same=0;
	}
	if(same)
		cout<<"Impossible"<<endl;
	else{
		if(s.length()%2) ans=2;
		else{
			ans=2;
			int len=s.length()/2;
			while(len>1)
			{
				if(!check(s,len)) ans=1;
				if(len%2!=0) break;
				len/=2;
			}
		}
		cout<<ans<<endl;
	}
}