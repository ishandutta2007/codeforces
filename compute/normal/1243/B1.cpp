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
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
        print(v[i],i==(int)(v.size())-1?suc:2);
}
const int INF=0x3f3f3f3f;

int main()
{
	int k,n;
	cin>>k;
	while(k--)
	{
		cin>>n;
		string s,t;
		cin>>s>>t;
		vector<int> dif;
		for(int i=0;i<n;i++)
		{
			if(s[i]!=t[i]) dif.push_back(i);
		}
		if(dif.size()==0) cout<<"Yes\n";
		else if(dif.size()!=2)
			cout<<"No\n";
		else{
			int i=dif[0],j=dif[1];
			if(t[i]==t[j]&&s[i]==s[j]) cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
}