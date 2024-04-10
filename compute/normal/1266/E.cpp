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
const int maxn=2e5+7;
int cur[maxn];
int a[maxn];
map<PII,int> ex;
ll ans=0;
void del(int x)
{
	if(cur[x]<=a[x]) ans++;
	cur[x]--;
}
void add(int x)
{
	if(cur[x]<a[x]) ans--;
	cur[x]++;
}
int main()
{
	int n;
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		ans+=a[i];
	}
	int q;
	cin>>q;
	while(q--)
	{
		int s,t,u;
		cin>>s>>t>>u;
		if(ex.count(make_pair(s,t)))
		{
			del(ex[make_pair(s,t)]);
			ex.erase(make_pair(s,t));
		}
		if(u)
		{
			ex[make_pair(s,t)]=u;
			add(u);
		}
		cout<<ans<<'\n';
	}
}