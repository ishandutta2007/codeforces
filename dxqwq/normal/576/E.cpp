// Problem: E. Painting Edges
// Contest: Codeforces Round #319 (Div. 1)
// URL: https://codeforces.com/contest/576/problem/E
// Memory Limit: 600 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int u[500003],v[500003],col[500003];
int id[500003],R[500003],val[500003],lst[500003];
struct node{int x,y,z;};
vector<node> e[2000003];
int fa[51][500003],sz[51][500003],dis[51][500003];
void update(int nl,int nr,int l,int r,int x,node t)
{
	if(nr<l||r<nl) return ;
	if(l<=nl&&nr<=r)
	{
		e[x].push_back(t);
		return ;
	}
	int mid=(nl+nr)>>1;
	update(nl,mid,l,r,x<<1,t),update(mid+1,nr,l,r,(x<<1)+1,t);
	return ;
}
int n=read(),m=read(),k=read(),q=read();
void solve(int l,int r,int x)
{
	stack<node> stk;
	for(node t:e[x])
	{
		int d=1;
		while(fa[t.z][t.x]!=t.x) d+=dis[t.z][t.x],t.x=fa[t.z][t.x];
		while(fa[t.z][t.y]!=t.y) d+=dis[t.z][t.y],t.y=fa[t.z][t.y];
		if(t.x!=t.y)
		{
			if(sz[t.z][t.x]>sz[t.z][t.y]) swap(t.x,t.y);
			stk.push(t),fa[t.z][t.x]=t.y,dis[t.z][t.x]=d&1,sz[t.z][t.y]+=sz[t.z][t.x];
		}
	}
	if(l==r)
	{
		int tx=u[id[l]],ty=v[id[l]],tz=val[l],d=0;
		while(fa[tz][tx]!=tx) d+=dis[tz][tx],tx=fa[tz][tx];
		while(fa[tz][ty]!=ty) d+=dis[tz][ty],ty=fa[tz][ty];
		if(tx!=ty||(d&1))
		{
			puts("YES");
			if(l!=q) col[id[l]]=val[l],update(1,q,l+1,R[l],1,(node){u[id[l]],v[id[l]],val[l]});
		}
		else
		{
			puts("NO");
			if(l!=q&&col[id[l]]) update(1,q,l+1,R[l],1,(node){u[id[l]],v[id[l]],col[id[l]]});
		}
		while(!stk.empty()) 
		{
			node t=stk.top();
			sz[t.z][t.y]-=sz[t.z][t.x],fa[t.z][t.x]=t.x,stk.pop();
		}
		return ;
	}
	int mid=(l+r)>>1;
	solve(l,mid,x<<1),solve(mid+1,r,(x<<1)+1);
	while(!stk.empty()) 
	{
		node t=stk.top();
		sz[t.z][t.y]-=sz[t.z][t.x],fa[t.z][t.x]=t.x,stk.pop();
	}
	return ;
}
signed main()
{
	for(int t=1; t<=k; ++t)
		for(int i=1; i<=n; ++i) 
			fa[t][i]=i,sz[t][i]=1;
	for(int i=1; i<=m; ++i) u[i]=read(),v[i]=read();
	for(int i=1; i<=q; ++i) 
		id[i]=read(),val[i]=read(),
		R[lst[id[i]]]=i,lst[id[i]]=i;
	for(int i=1; i<=m; ++i) R[lst[i]]=q;
	solve(1,q,1);
	return 0;
}