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
	int n;
	cin>>n;
	string s;
	cin>>s;
	vi ans;
	for(int i=0;i<s.length()-1;i++)
	{
		if(s[i]!='B')
		{
			ans.push_back(i+1);
			if(s[i+1]=='B') s[i+1]='W';
			else s[i+1]='B';
			s[i]='B';
		}
	}
	int cntb=0,cntw=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='B') cntb++;
		else cntw++;
	}
	if((cntb&1)&&(cntw&1))
	{
		cout<<-1<<endl;
		return 0;
	}
	if(cntb%2==0)
	{
		for(int i=0;i<s.length()-1;i++)
		{
			if(s[i]=='B'&&s[i+1]=='B')
			{
				ans.push_back(i+1);
				i++;
			}
		}
	}
	else{
		for(int i=0;i<s.length()-1;i++)
		{
			if(s[i]=='W'&&s[i+1]=='W')
			{
				ans.push_back(i+1);
				i++;
			}
		}
	}
	cout<<ans.size()<<endl;
	for(auto u:ans) cout<<u<<" ";
	cout<<endl;
}