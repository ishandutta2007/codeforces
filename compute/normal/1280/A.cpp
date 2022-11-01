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
const int maxn=3e6+7;
const int mod=1e9+7;
int val[maxn];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x;
		cin>>x;
		string s;
		cin>>s;
		int l=0;
		ll ans=s.length();
		for(int i=0;i<ans;i++) val[i]=s[i]-'0';
		bool ok=0;
		while(l<x)
		{
			l++;
			int cc=val[l-1];
			if(cc==1);
			else {
				ll len=(ans-l+mod)%mod;
				if(!ok)
				{
					for(int i=ans;i<ans+len&&i<=x;i++)
					{
						val[i]=val[i-ans+l];
						if(cc==3) val[i+len]=val[i-ans+l];
					}
					if(ans>x) ok=1;
				}
				ans=(ans+(cc-1)*len%mod)%mod;
			}
		}
		cout<<ans<<'\n';
	}
}