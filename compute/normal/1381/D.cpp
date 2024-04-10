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
const int maxn=1e5+7;
vi G[maxn];
vi dp[maxn];
int dep[maxn],far[maxn];
int len;
void dfs(int u,int fa=-1,int de=0)
{
	dp[u]=vi(G[u].size());
	dep[u]=de;
	far[u]=fa;
	for(int i=0;i<G[u].size();i++)if(G[u][i]!=fa)
	{
		int v=G[u][i];
		dfs(v,u,de+1);
		dp[u][i]=*max_element(dp[v].begin(),dp[v].end())+1;
	}
}
bool suc;
void dfs2(int u,int fa=-1,int p=0)
{
	vi id(G[u].size());
	iota(id.begin(),id.end(),0);
	sort(id.begin(),id.end(),[&](int x,int y){
		return dp[u][x]>dp[u][y];
	});
	for(int i=0;i<G[u].size();i++)if(G[u][i]!=fa)
	{
		int v=G[u][i];
		int mx=max(p,id.size()>1?dp[u][id[id[0]==i]]:0);
		dfs2(v,u,mx+1);
	}
	else dp[u][i]=p;
	int cnt=0;
	for(auto d:dp[u])
	{
		if(d+1>=len) cnt++;
	}
	if(cnt>=3) suc=1;
}
vi pa,pb;
vi path;
int getlen(int a,int b)
{
	int ret=1;
	while(a!=b)
	{
		if(dep[a]<dep[b])
		{
			swap(a,b);
			pa.swap(pb);
		}
		pa.push_back(a);
		a=far[a];
		ret++;
	}
	pa.push_back(a);
	return ret;
}
int getf(int x,int fa)
{
	int ret=0;
	for(int i=0;i<G[x].size();i++)
	{
		if(G[x][i]==fa) continue;
		ret=max(ret,dp[x][i]);
	}
	ret++;
	dbg(x,fa,ret);
	return ret;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,a,b;
		pa.clear(),pb.clear();
		cin>>n>>a>>b;
		for(int i=0;i<=n;i++) G[i].clear();
		for(int i=1,u,v;i<n;i++)
		{
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1);
		len=getlen(a,b);
		dbg(len);
		suc=0;
		dfs2(1);
		if(!suc) cout<<"NO\n";
		else{
			reverse(pb.begin(),pb.end());
			path=pa;
			for(auto u:pb) path.push_back(u);
			dbg(path);
			a=0,b=path.size()-1;
			int mxl=getf(path[0],path[1]),mxr=getf(path[b],path[b-1]);
			while(a<b)
			{
				bool upd=0;
				if(mxr-1!=a) upd=1;
				a=mxr-1;
				if(a>=b) break;
				dbg(path[a]);
				mxl=getf(path[a],path[a+1])-a;
				if(path.size()-mxl!=b) upd=1;
				b=path.size()-mxl;
				if(b<=a) break;
				dbg(path[b]);
				mxr=getf(path[b],path[b-1])-(path.size()-1-b);
				if(!upd) break;
			}
			cout<<(a<b?"NO":"YES")<<'\n';
		}
	}
}