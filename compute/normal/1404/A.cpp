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
typedef pair<int,int> pi;
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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		vvc<char> all(k);
		for(int i=0;i<n;i++)
			all[i%k].push_back(s[i]);
		bool suc=1;
		vc<int> ans(k);
		for(int i=0;i<k;i++)
		{
			int cnt0=0,cnt1=0,e=0;
			for(auto u:all[i])
			{
				if(u=='0') cnt0++;
				else if(u=='1') cnt1++;
				else e++;
			}
			if(cnt0&&cnt1) suc=0;
			if(suc)
			{
				if(cnt0)
					ans[i]=0;
				else if(cnt1) ans[i]=1;
				else ans[i]=-1;
			}
		}
		if(!suc) cout<<"NO\n";
		else{
			int c0=0,c1=0,e=0;
			for(int i=0;i<k;i++)
			{
				if(ans[i]==0) c0++;
				else if(ans[i]==1) c1++;
				else e++;
			}
			if(c0>c1) swap(c0,c1);
			if(c0+e<c1) cout<<"NO\n";
			else cout<<"YES\n";
		}
	}
}