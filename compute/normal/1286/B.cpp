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
const int maxn=2e3+7;
vi G[maxn];
int c[maxn];
bool ok=1;
vi dfs(int u)
{
	if(!G[u].size())
	{
		vi ret={u};
		if(c[u]!=0) ok=0;
		return ret;
	}
	vi ret;
	for(auto v:G[u])
	{
		vi cur=dfs(v);
		if(!ok) return vi();
		for(auto cc:cur) ret.push_back(cc);
	}
	if(c[u]>ret.size())
	{
		ok=0;
		return vi();
	}
	vi rr;
	for(int i=0;i<c[u];i++)
		rr.push_back(ret[i]);
	rr.push_back(u);
	for(int i=c[u];i<ret.size();i++)
		rr.push_back(ret[i]);
	return rr;
}
int ans[maxn];
int main()
{
	int n;
	cin>>n;
	int rt=-1;
	for(int i=1,fa;i<=n;i++)
	{
		cin>>fa>>c[i];
		if(!fa)
			rt=i;
		else G[fa].push_back(i);
	}
	vi aa=dfs(rt);
	if(!ok) cout<<"NO\n";
	else{
		cout<<"YES\n";
		for(int i=0;i<n;i++)
			ans[aa[i]]=i+1;
		for(int i=1;i<=n;i++)
			cout<<ans[i]<<(i==n?'\n':' ');
	}
}