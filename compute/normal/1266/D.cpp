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
const int maxn=1e5+7;
ll deg[maxn];
struct Edge{
	int to;
	ll w;
};
vc<Edge> G[maxn];
int id[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) id[i]=i;
	for(int i=0,u,v,w;i<m;i++)
	{
		cin>>u>>v>>w;
		u--;
		v--;
		deg[u]-=w;
		deg[v]+=w;
	}
	sort(id,id+n,[&](int i,int j){return deg[i]<deg[j];});
	int l=0,r=n-1;
	int cnt=0;
	while(l<r)
	{
		ll valr=abs(deg[id[r]]),vall=abs(deg[id[l]]);
		if(!vall||!valr)
			break;
		//dbg(l,r,id[l],id[r],vall,valr);
		G[id[l]].push_back({id[r],min(vall,valr)});
		dbg(id[l],id[r]);
		if(valr>vall)
		{
			deg[id[r]]-=vall;
			l++;
		}
		else if(vall>valr){
			deg[id[l]]+=valr;
			r--;
		}
		else{
			l++;
			r--;
		}
		cnt++;
	}
	cout<<cnt<<endl;
	for(int i=0;i<n;i++)
	{
		for(auto e:G[i])
			cout<<i+1<<" "<<e.to+1<<" "<<e.w<<"\n";
	}

}