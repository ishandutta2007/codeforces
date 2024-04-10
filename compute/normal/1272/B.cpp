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
	int q;
	cin>>q;
	while(q--)
	{
		string s;
		cin>>s;
		int l=0,r=0,u=0,d=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='L') l++;
			else if(s[i]=='R') r++;
			else if(s[i]=='U') u++;
			else d++;
		}
		l=min(l,r);
		r=min(l,r);
		u=min(u,d);
		d=min(u,d);
		if(!l&&!u)
			cout<<"0\n\n";
		else if(!l)
			cout<<"2\nUD\n";
		else if(!u)
			cout<<"2\nLR\n";
		else{
			cout<<l+r+u+d<<'\n';
			for(int i=0;i<l;i++)
				cout<<'L';
			for(int i=0;i<u;i++)
				cout<<'U';
			for(int i=0;i<r;i++)
				cout<<'R';
			for(int i=0;i<d;i++)
				cout<<'D';
			cout<<'\n';
		}
	}
}