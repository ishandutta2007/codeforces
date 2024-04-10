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
const int maxn=3e5+7;
int l[maxn],r[maxn];
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	if(n%2!=0)
	{
		cout<<":("<<endl;
		return 0;
	}
	bool ok=1;
	for(int i=0;i<s.length();i++)
	{
		if(i) l[i]=l[i-1];
		if(i) r[i]=r[i-1];
		if(s[i]=='(') l[i]++;
		else if(s[i]==')') r[i]++;
	}
	int curl=0,curr=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='?')
		{
			if(l[n-1]+curl<n/2)
			{
				s[i]='(';
				curl++;
			}
			else 
			{
				s[i]=')';
				curr++;
			}
		}
		if((l[i]+curl==r[i]+curr&&i!=n-1)||(l[i]+curl<r[i]+curr))
		{
			ok=0;
			break;
		}
	}
	if(r[n-1]+curr!=l[n-1]+curl) ok=0;
	if(!ok) cout<<":("<<endl;
	else cout<<s<<endl;
}