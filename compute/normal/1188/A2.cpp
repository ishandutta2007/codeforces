#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[33;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
ll quick(ll a,ll b,ll mod)
{
	ll ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a,ll mod){return quick(a,mod-2,mod);}
const int maxn=1e3+7;
int deg[maxn];
struct Edge{
	int u,v,w;
}e[maxn],ans[maxn*4];
vector<int> G[maxn];
int get1(int u,int fa)
{
	if(deg[u]==1) return u;
	for(auto v:G[u])if(v!=fa)
		return get1(v,u);
}
PII get2(int u,int fa)
{
	PII ret={-1,-1};
	for(auto v:G[u])if(v!=fa)
	{
		int cur=get1(v,u);
		if(ret.first==-1) ret.first=cur;
		else{
			ret.second=cur;
			break;
		}
	}
	return ret;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		deg[e[i].u]++;
		deg[e[i].v]++;
		G[e[i].u].push_back(e[i].v);
		G[e[i].v].push_back(e[i].u);
	}
	bool ok=1;
	for(int i=1;i<=n;i++) if(deg[i]==2) ok=0;
	if(!ok) 
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	int cnt=0;
	for(int i=1;i<n;i++)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(deg[u]>deg[v]) swap(u,v);
		if(deg[u]==1)
		{
			if(deg[v]==1)
				ans[cnt++]={u,v,w};
			else{
				PII cur=get2(v,u);
				ans[cnt++]={u,cur.first,w/2};
				ans[cnt++]={u,cur.second,w/2};
				ans[cnt++]={cur.first,cur.second,-w/2};
			}
		}
		else{
			PII c1=get2(u,v),c2=get2(v,u);
			ans[cnt++]={c1.first,c2.first,w/2};
			ans[cnt++]={c1.second,c2.second,w/2};
			ans[cnt++]={c1.first,c1.second,-w/2};
			ans[cnt++]={c2.first,c2.second,-w/2};
		}
	}
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++)
		printf("%d %d %d\n",ans[i].u,ans[i].v,ans[i].w);
}