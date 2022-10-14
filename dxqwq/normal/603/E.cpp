// Problem: E. Pastoral Oddities
// Contest: Codeforces - Codeforces Round #334 (Div. 1)
// URL: https://codeforces.com/problemset/problem/603/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
struct node{int x,y,v,t;bool operator<(const node&tt)const{return 
(v<tt.v)||(v==tt.v&&t<tt.t);}};
node e[300003];
vector<node> v[1200003];
int ans[300003];
int fa[100003],sz[100003];
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
int n=read(),m=read(),s=n>>1,cur=0;
void solve(int l,int r,int x)
{
	stack<node> stk;
	for(node t:v[x])
	{
		while(fa[t.x]!=t.x) t.x=fa[t.x];
		while(fa[t.y]!=t.y) t.y=fa[t.y];
		if(t.x!=t.y)
		{
			if(sz[t.x]>sz[t.y]) swap(t.x,t.y);
			((sz[t.x]&1)&&(sz[t.y]&1))&&(--s),
			stk.push(t),fa[t.x]=t.y,sz[t.y]+=sz[t.x];
		}
	}
	if(l==r)
	{
		while(cur<m&&s)
		{
			node t=e[++cur];
			if(t.t>l) continue;
			update(1,m,t.t,l-1,1,t);	
			while(fa[t.x]!=t.x) t.x=fa[t.x];
			while(fa[t.y]!=t.y) t.y=fa[t.y];
			if(t.x!=t.y)
			{
				if(sz[t.x]>sz[t.y]) swap(t.x,t.y);
				((sz[t.x]&1)&&(sz[t.y]&1))&&(--s),
				stk.push(t),fa[t.x]=t.y,sz[t.y]+=sz[t.x];
			}
		}
		if(!s) ans[l]=e[cur].v;
		while(!stk.empty()) 
		{
			node t=stk.top();
			sz[t.y]-=sz[t.x],fa[t.x]=t.x,
			((sz[t.x]&1)&&(sz[t.y]&1))&&(++s);
			stk.pop();
		}
		return ;
	}
	int mid=(l+r)>>1;
	solve(mid+1,r,(x<<1)+1),solve(l,mid,x<<1);
	while(!stk.empty()) 
	{
		node t=stk.top();
		sz[t.y]-=sz[t.x],fa[t.x]=t.x,
		((sz[t.x]&1)&&(sz[t.y]&1))&&(++s);
		stk.pop();
	}
	return ;
}
signed main()
{
	if(n&1) 
	{
		while(m--) puts("-1");
		return 0;
	}
	for(int i=1; i<=n; ++i) fa[i]=i,sz[i]=1;
	for(int x,y,z,i=1; i<=m; ++i)
		x=read(),y=read(),z=read(),e[i]=(node){x,y,z,i};
	sort(e+1,e+m+1),memset(ans,-1,sizeof(ans)),solve(1,m,1);
	for(int i=1; i<=m; ++i) printf("%d\n",ans[i]);
	return 0;
}