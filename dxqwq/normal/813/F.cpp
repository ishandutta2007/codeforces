// Problem: F. Bipartite Checking
// Contest: Codeforces - Educational Codeforces Round 22
// URL: https://codeforces.com/problemset/problem/813/F
// Memory Limit: 256 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
struct node{int x,y;};
vector<node> v[500003];
bool ans[100003];
int fa[100003],sz[100003],dis[100003];
void update(int nl,int nr,int l,int r,int x,node t)
{
	if(nr<l||r<nl) return ;
	if(l<=nl&&nr<=r)
	{
		v[x].push_back(t);
		return ;
	}
	int mid=(nl+nr)>>1;
	update(nl,mid,l,r,x<<1,t),update(mid+1,nr,l,r,(x<<1)+1,t);
	return ;
}
int n=read(),m=read(),T=m;
void solve(int l,int r,int x)
{
	stack<node> stk;
	// printf("%d %d\n",l,r);
	// for(int i=1; i<=n; ++i) printf("%d ",fa[i]);
	// puts("");
	for(node t:v[x])
	{
		int d=1;
		while(fa[t.x]!=t.x) d+=dis[t.x],t.x=fa[t.x];
		while(fa[t.y]!=t.y) d+=dis[t.y],t.y=fa[t.y];
		if(t.x!=t.y)
		{
			if(sz[t.x]>sz[t.y]) swap(t.x,t.y);
			stk.push(t),fa[t.x]=t.y,dis[t.x]=d&1,sz[t.y]+=sz[t.x];
		}
		else if(d&1) 
		{
			while(!stk.empty()) 
			{
				node t=stk.top();
				sz[t.y]-=sz[t.x],fa[t.x]=t.x,
				stk.pop();
			}
			return ;
		}
	}
	if(l==r)
	{
		ans[l]=1;
		while(!stk.empty()) 
		{
			node t=stk.top();
			sz[t.y]-=sz[t.x],fa[t.x]=t.x,
			stk.pop();
		}
		return ;
	}
	int mid=(l+r)>>1;
	solve(l,mid,x<<1),solve(mid+1,r,(x<<1)+1);
	while(!stk.empty()) 
	{
		node t=stk.top();
		sz[t.y]-=sz[t.x],fa[t.x]=t.x,
		stk.pop();
	}
	return ;
}
map<pair<int,int>,int> mp;
signed main()
{
	for(int i=1; i<=n; ++i) fa[i]=i,sz[i]=1;
	node t;
	for(int i=1; i<=m; ++i) 
	{
		t.x=read(),t.y=read();
		if(mp[make_pair(t.x,t.y)])
		{
			update(1,T,mp[make_pair(t.x,t.y)],i-1,1,t);
			mp[make_pair(t.x,t.y)]=0;
		}
		else
		{
			mp[make_pair(t.x,t.y)]=i;
		}
	}
	for(auto i:mp) if(i.second) 
		update(1,T,i.second,T,1,(node){i.first.first,i.first.second});
	solve(1,T,1);
	for(int i=1; i<=T; ++i) puts(ans[i]?"YES":"NO");
	return 0;
}