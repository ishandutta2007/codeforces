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
const int maxn=1e5+7;
int pos[maxn];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vi a(n);
		for(int i=0;i<n;i++) 
		{
			cin>>a[i];
			pos[a[i]]=i;
		}
		vi b(m);
		for(int i=0;i<m;i++) cin>>b[i];
		int cur=-1;
		ll ans=0;
		for(int i=0;i<m;i++)
		{
			if(pos[b[i]]>=cur) ans+=2*(pos[b[i]]-i)+1;
			else ans++;
			dbg(i,b[i],pos[b[i]],ans);
			cur=max(cur,pos[b[i]]);
		}
		cout<<ans<<'\n';

	}
}