// Problem: D. Difficult Mountain
// Contest: Codeforces - Codeforces Round #751 (Div. 1)
// URL: https://codeforces.com/contest/1601/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int int
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int tag[4000003],ans[4000003];
void push_down(int x)
{
	tag[x<<1]+=tag[x],tag[(x<<1)+1]+=tag[x];
	ans[x<<1]+=tag[x],ans[(x<<1)+1]+=tag[x];
	tag[x]=0;
	return ;
}
void update(int l,int r,int L,int R,int id,int val)
{
	if(L<=l && r<=R) 
	{
		tag[id]+=val,ans[id]+=val;
		return ;
	}
	int mid=(l+r)>>1;
	push_down(id);
	if(L<=mid) update(l,mid,L,R,id<<1,val);
	if(R>=mid+1) update(mid+1,r,L,R,(id<<1)+1,val);
	ans[id]=max(ans[(id<<1)],ans[(id<<1)+1]);
	return ;
}
int query(int l,int r,int L,int R,int id)
{
	if(L<=l && r<=R) return ans[id];
	int mid=(l+r)>>1;
	push_down(id);
	int res=0;
	if(L<=mid) res=max(res,query(l,mid,L,R,id<<1));
	if(R>=mid+1) res=max(res,query(mid+1,r,L,R,(id<<1)+1));
	return res;
}
struct node{int x,y,op;}a[500003];
int lsh[1000003];
signed main()
{
	int n=read(),d=read(),m=1;
	lsh[1]=d;
	for(int i=1; i<=n; ++i)
	{
		a[i].x=read(),a[i].y=max(read(),d);
		if(a[i].x<d) --i,--n;
		else lsh[++m]=a[i].x,lsh[++m]=a[i].y;
	}
	sort(lsh+1,lsh+m+1),m=unique(lsh+1,lsh+m+1)-lsh-1;
	for(int i=1; i<=n; ++i)
	{
		a[i].x=lower_bound(lsh+1,lsh+m+1,a[i].x)-lsh,
		a[i].y=lower_bound(lsh+1,lsh+m+1,a[i].y)-lsh;
		if(a[i].x>a[i].y)
			swap(a[i].x,a[i].y),a[i].op=1;
	}
	sort(a+1,a+n+1,[&](node p,node q){return 1ll*p.x*p.y<1ll*q.x*q.y;});
	for(int i=1; i<=n; ++i)
	{
		if(a[i].op)
		{
			int z=query(1,m,1,a[i].x,1),
			w=query(1,m,a[i].x,a[i].x,1);
			if(z-w>0) update(1,m,a[i].x,a[i].x,1,z-w);
			update(1,m,a[i].x,a[i].y,1,1);
		}
		else
		{
			int z=query(1,m,1,a[i].x,1),
			w=query(1,m,a[i].y,a[i].y,1);
			if(z+1-w>0) update(1,m,a[i].y,a[i].y,1,z+1-w);
		}
	}
	printf("%d\n",ans[1]);
	return 0;
}