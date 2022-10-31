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
const int maxn=1e6+7;
int a[maxn];
vi ans;
int n;
int ed;
bool vis[maxn];
void dfs(int u)
{
	if(vis[u]) 
	{
		ed=u;
		return;
	}
	vis[u]=1;
	ans.push_back(u);
	int x=a[u]-u;
	dfs(-x);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		ed=-1;
		ans.clear();
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i],vis[i]=0;
		dfs(1);
		vi op;
		bool ok=0;
		for(int i=0;i<ans.size();i++)
		{
			if(ans[i]==ed) ok=1;
			if(ok) op.push_back(ans[i]);
		}
		cout<<op.size()<<'\n';
		print(op);
	}
}