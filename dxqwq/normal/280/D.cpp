// Problem: D. k-Maximum Subsequence Sum
// Contest: Codeforces - Codeforces Round #172 (Div. 1)
// URL: https://codeforces.com/problemset/problem/280/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
// #define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[100003];
struct range{int l,r,v;};
range max(range x,range y){return x.v>y.v?x:y;}
struct node{range pre,suf,ans,val;}f[400003],g[400003];
bool rev[400003];
node merge(node x,node y)
{
	return (node)
	{
		max(x.pre,(range){x.val.l,y.pre.r,x.val.v+y.pre.v}),
		max(y.suf,(range){x.suf.l,y.val.r,x.suf.v+y.val.v}),
		max(max(x.ans,y.ans),(range){x.suf.l,y.pre.r,x.suf.v+y.pre.v}),
		(range){x.val.l,y.val.r,x.val.v+y.val.v}
	};
}
void build(int nl,int nr,int x)
{
	if(nl==nr)
	{
		f[x].pre=f[x].suf=f[x].ans=f[x].val=(range){nl,nr,a[nl]},
		g[x].pre=g[x].suf=g[x].ans=g[x].val=(range){nl,nr,-a[nl]};
		return ;
	}
	int mid=(nl+nr)>>1;
	build(nl,mid,x<<1),build(mid+1,nr,(x<<1)+1);
	f[x]=merge(f[x<<1],f[(x<<1)+1]),
	g[x]=merge(g[x<<1],g[(x<<1)+1]);
	return ;
}
void update(int nl,int nr,int t,int x,int v)
{
	if(nl==nr)
	{
		rev[x]=0,
		f[x].pre=f[x].suf=f[x].ans=f[x].val=(range){nl,nr,v},
		g[x].pre=g[x].suf=g[x].ans=g[x].val=(range){nl,nr,-v};
		return ;
	}
	int mid=(nl+nr)>>1;
	if(rev[x]) 
		rev[x<<1]^=1,rev[(x<<1)+1]^=1,
		swap(f[x<<1],g[x<<1]),swap(f[(x<<1)+1],g[(x<<1)+1]),
		rev[x]=0;
	if(t<=mid) update(nl,mid,t,x<<1,v);
	else update(mid+1,nr,t,(x<<1)+1,v);
	f[x]=merge(f[x<<1],f[(x<<1)+1]),
	g[x]=merge(g[x<<1],g[(x<<1)+1]);
	return ;
}
void flip(int nl,int nr,int l,int r,int x)
{
	if(nr<l||r<nl) return ;
	if(l<=nl&&nr<=r) 
	{
		rev[x]^=1,swap(f[x],g[x]);
		return ;
	}
	int mid=(nl+nr)>>1;
	if(rev[x]) 
		rev[x<<1]^=1,rev[(x<<1)+1]^=1,
		swap(f[x<<1],g[x<<1]),swap(f[(x<<1)+1],g[(x<<1)+1]),
		rev[x]=0;
	flip(nl,mid,l,r,x<<1),flip(mid+1,nr,l,r,(x<<1)+1);
	f[x]=merge(f[x<<1],f[(x<<1)+1]),
	g[x]=merge(g[x<<1],g[(x<<1)+1]);
	return ;
}
node query(int nl,int nr,int l,int r,int x)
{
	if(nr<l||r<nl) exit(998244353);
	if(l<=nl&&nr<=r) return f[x];
	int mid=(nl+nr)>>1;
	if(rev[x]) 
		rev[x<<1]^=1,rev[(x<<1)+1]^=1,
		swap(f[x<<1],g[x<<1]),swap(f[(x<<1)+1],g[(x<<1)+1]),
		rev[x]=0;
	if(r<=mid) return query(nl,mid,l,r,x<<1);
	if(l>mid) return query(mid+1,nr,l,r,(x<<1)+1);
	return merge(query(nl,mid,l,r,x<<1),query(mid+1,nr,l,r,(x<<1)+1));
}
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	build(1,n,1);
	for(int T=read(),op,l,r,x,ans; T--;)
	{
		op=read();
		if(op)
		{
			l=read(),r=read(),x=read(),ans=0;
			vector<range> v;
			for(int k=1; k<=x; ++k)
			{
				range t=query(1,n,l,r,1).ans;
				// printf("%d %d %d\n",t.l,t.r,t.v);
				if(t.v<=0) break;
				ans+=t.v,flip(1,n,t.l,t.r,1),v.push_back(t);
			}
			printf("%d\n",ans);
			for(range i:v) flip(1,n,i.l,i.r,1);
		}
		else l=read(),x=read(),update(1,n,l,1,x);
	}
	return 0;
}