// Problem: G. Shortest Path Queries
// Contest: Codeforces - Educational Codeforces Round 38 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/938/G
// Memory Limit: 512 MB
// Time Limit: 3500 ms
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
struct lb{int n[33];}L[103];
int top=0;
void insert(lb&res,int y)
{
	int tmp=1<<30;
	for(int i=30; i>=0; i--,tmp>>=1) if(tmp&y) if(res.n[i]) y^=res.n[i]; else { res.n[i]=y; break; } 
	return ;
}
//     
int getmax(lb x,int y)
{
	int res=y;
	for(int i=30; i>=0; i--) if(x.n[i]) res=min(res,res^x.n[i]);
	return res; 
}
struct node{int x,y,z;};
vector<node> v[800003];
bool ans[200003];
int fa[200003],sz[200003],dis[200003];
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
int n=read(),m=read(),T,cur;
int X[200003],Y[200003];
void solve(int l,int r,int x)
{
	if(l>cur) return ; 
	stack<node> stk;
	++top,L[top]=L[top-1];
	for(node t:v[x])
	{
		// printf("%d %d %d\n",t.x,t.y,t.z);
		int d=t.z;
		while(fa[t.x]!=t.x) d^=dis[t.x],t.x=fa[t.x];
		while(fa[t.y]!=t.y) d^=dis[t.y],t.y=fa[t.y];
		if(t.x!=t.y)
		{
			if(sz[t.x]>sz[t.y]) swap(t.x,t.y);
			stk.push(t),fa[t.x]=t.y,dis[t.x]=d,sz[t.y]+=sz[t.x];
		}
		else insert(L[top],d);
		// for(int i=1; i<=n; ++i) printf("%d ",fa[i]);
		// puts("");
		// for(int i=1; i<=n; ++i) printf("%d ",dis[i]);
		// puts("");
	}
	if(l==r)
	{
		int res=0;
		while(X[l]!=fa[X[l]]) res^=dis[X[l]],X[l]=fa[X[l]];
		while(Y[l]!=fa[Y[l]]) res^=dis[Y[l]],Y[l]=fa[Y[l]];
		printf("%d\n",getmax(L[top],res));
		--top;
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
	--top;
	while(!stk.empty()) 
	{
		node t=stk.top();
		sz[t.y]-=sz[t.x],fa[t.x]=t.x,
		stk.pop();
	}
	return ;
}
map<pair<int,int>,int> mp,val;
signed main()
{
	for(int i=1; i<=n; ++i) fa[i]=i,sz[i]=1;
	node t;
	for(int i=1; i<=m; ++i) 
		t.x=read(),t.y=read(),t.z=read(),
		mp[make_pair(t.x,t.y)]=1,val[make_pair(t.x,t.y)]=t.z;
	T=read();
	for(int i=1,op; i<=T; ++i) 
	{
		op=read(),t.x=read(),t.y=read();
		if(op==1)
			mp[make_pair(t.x,t.y)]=cur+1,
			val[make_pair(t.x,t.y)]=read();
		else if(op==2)
		{
			if(mp[make_pair(t.x,t.y)]<=cur)
				t.z=val[make_pair(t.x,t.y)],
				update(1,T,mp[make_pair(t.x,t.y)],cur,1,t);
			mp[make_pair(t.x,t.y)]=0;
		}
		else ++cur,X[cur]=t.x,Y[cur]=t.y;
	}
	for(auto i:mp) if(i.second&&i.second<=cur) 
		update(1,T,i.second,T,1,(node){i.first.first,i.first.second,val[i.first]});
	solve(1,T,1);
	return 0;
}