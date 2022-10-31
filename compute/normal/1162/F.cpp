#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int maxn=3e3+7;
const int mod=998244353;
int col[maxn];
namespace DSU{
	int far[maxn];
	void init()
	{
		for(int i=0;i<maxn;i++) far[i]=i;
	}
	int Find(int x){return x==far[x]?x:far[x]=Find(far[x]);}
	void Union(int x,int y)
	{
		x=Find(x),y=Find(y);
		if(x<y) swap(x,y);
		far[y]=x;
	}
};
string s;
int var,w,b;
bool isp[maxn];
vector<int> G[maxn];
bool dfs(int u)
{
	for(auto &v:G[u])
	{
		if(col[v]==-1)
		{
			col[v]=col[u]^1;
			if(!dfs(v)) return false;
		}
		else{
			if(col[v]==col[u]) return false;
		}
	}
	return true;
}
ll solve(int len)
{
	for(int i=0;i<=b;i++) G[i].clear();
	memset(isp,0,sizeof(isp));
	DSU::init();
	for(int i=0;i<s.length()/2;i++)
		DSU::Union(i,s.length()-i-1);
	for(int i=0;i<len/2;i++)
		DSU::Union(var+i,var+len-1-i);
	isp[w]=isp[b]=1;
	DSU::Union(var+len-1,b);
	for(int i=0;i<s.length();i++) isp[i]=1;
	for(int i=0;i<len;i++) isp[i+var]=1;
	for(int i=0;i<len;i++)
		if(s[i]=='0') DSU::Union(i,var+i);
	for(int i=len;i<s.length();i++)
	{
		if(s[i]=='1')
			DSU::Union(i,b);
		else if(s[i]=='0') DSU::Union(i,w);
	}
	DSU::Union(s.length()-1,b);
	if(DSU::Find(b)==DSU::Find(w)) return 0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='1')
		{
			G[DSU::Find(i)].push_back(DSU::Find(var+i));
			G[DSU::Find(var+i)].push_back(DSU::Find(i));
		}
	}
	G[DSU::Find(w)].push_back(DSU::Find(b));
	G[DSU::Find(b)].push_back(DSU::Find(w));
	ll ret=1;
	memset(col,-1,sizeof(col));
	for(int i=b;i>=0;i--)
	{
		if(isp[i])
		{
			int cur=DSU::Find(i);
			if(col[cur]==-1)
			{
				if(cur==b) col[cur]=1;
				else col[cur]=0;
				if(!dfs(cur)) return 0;
				else {
					if(cur!=b&&cur!=w) ret=ret*2%mod;
				}
			}
		}
	}
	return ret;
}
int main()
{
	cin>>s;
	var=s.length();
	reverse(s.begin(),s.end());
	w=var*2+1,b=var*2+2;
	ll ans=0;
	for(int i=1;i<s.length();i++)
		ans=(ans+solve(i))%mod;
	cout<<ans<<endl;
}