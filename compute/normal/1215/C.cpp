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
vector<int> ab,ba;
int main()
{
	int n;
	cin>>n;
	string s,t;
	cin>>s>>t;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='a'&&t[i]=='b')
			ab.push_back(i+1);
		else if(s[i]=='b'&&t[i]=='a')
			ba.push_back(i+1);
	}
	if(ab.size()%2!=ba.size()%2)
		cout<<-1<<endl;
	else{
		if(ab.size()%2==0)
		{
			cout<<(ab.size()+ba.size())/2<<endl;
			for(int i=0;i<ab.size();i+=2)
				cout<<ab[i]<<" "<<ab[i+1]<<'\n';
			for(int i=0;i<ba.size();i+=2)
				cout<<ba[i]<<" "<<ba[i+1]<<'\n';
		}
		else{
			cout<<(ab.size()+ba.size()-2)/2+2<<endl;
			for(int i=0;i<ab.size()-1;i+=2)
				cout<<ab[i]<<" "<<ab[i+1]<<'\n';
			for(int i=0;i<ba.size()-1;i+=2)
				cout<<ba[i]<<" "<<ba[i+1]<<'\n';
			cout<<ab[ab.size()-1]<<" "<<ab[ab.size()-1]<<'\n';
			cout<<ab[ab.size()-1]<<" "<<ba[ba.size()-1]<<'\n';

		}
	}
}