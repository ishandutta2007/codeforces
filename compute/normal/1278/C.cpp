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
const int maxn=2e5+7;
int pre[maxn],suf[maxn];
int a[maxn];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		const int var=1e5;
		for(int i=var-n;i<=var+n;i++) pre[i]=suf[i]=-1;
		for(int i=1;i<=2*n;i++)
		{
			cin>>a[i];
			if(a[i]==2) a[i]=-1;
		}
		int cur=0;
		pre[var]=0;
		for(int i=1;i<=n;i++)
		{
			cur+=a[i];
			int rev=cur+var;
			pre[rev]=i;
		}
		cur=0;
		suf[var]=2*n+1;
		for(int i=2*n;i>n;i--)
		{
			cur+=a[i];
			int rev=cur+var;
			suf[rev]=i;
		}
		int ans=0;
		for(int i=-n;i<=n;i++)
		{
			if(pre[var+i]!=-1&&suf[var-i]!=-1)
				ans=max(ans,pre[var+i]+2*n-suf[var-i]+1);
		}
		cout<<2*n-ans<<'\n';
	}
}