// Problem: G. Choosing Ads
// Contest: Codeforces - VK Cup 2016 - Round 3
// URL: https://codeforces.com/problemset/problem/643/G
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
int n=read(),m=read(),S=100/read();
int a[1000003];
struct seg
{
	int tag,val[10],cnt[10];
}f[600003];
seg merge(seg x,seg y)
{
	// for(int i=0; i<S; ++i) printf("(%d %d),",x.val[i],x.cnt[i]);
	// puts("");
	// for(int i=0; i<S; ++i) printf("(%d %d),",y.val[i],y.cnt[i]);
	// puts("");
	for(int j=0; j<S; ++j) if(y.cnt[j])
	{
		int qwq=0x3f3f3f3f;
		bool flg=0;
		for(int i=0; !flg&&i<S; ++i) 
			flg|=(x.cnt[i]&&x.val[i]==y.val[j]),
			(x.cnt[i]&&x.val[i]==y.val[j])&&(x.cnt[i]+=y.cnt[j]);
		if(flg) continue;
		for(int i=0; i<S; ++i)
			(qwq>x.cnt[i])&&(qwq=x.cnt[i]);
		if(y.cnt[j]>=qwq)
		{
			for(int i=0; i<S; ++i)
				x.cnt[i]-=qwq;
			for(int i=0; !flg&&i<S; ++i)
				(!x.cnt[i])&&(x.val[i]=y.val[j],x.cnt[i]=y.cnt[j]-max(qwq,1)+1,flg=1);
		}
		else
		{
			for(int i=0; i<S; ++i)
				x.cnt[i]-=y.cnt[j];
		}
	}
	x.tag=0;
	// for(int i=0; i<S; ++i) printf("(%d %d),",x.val[i],x.cnt[i]);
	// puts("");puts("");
	return x;
}
void build(int l,int r,int x)
{
	if(l==r)
	{
		// memset(f[x].cnt,0,sizeof(f[x].cnt));
		f[x].val[0]=a[l],f[x].cnt[0]=2;
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,x<<1),build(mid+1,r,(x<<1)+1);
	f[x]=merge(f[x<<1],f[(x<<1)+1]);
	return ;
}
void update(int nl,int nr,int l,int r,int x,int v)
{
	if(nr<l||r<nl) return ;
	if(l<=nl&&nr<=r)
	{
		f[x].tag=v;
		memset(f[x].cnt,0,sizeof(f[x].cnt));
		f[x].val[0]=v,f[x].cnt[0]=nr-nl+2;
		return ;
	}
	int mid=(nl+nr)>>1;
	if(f[x].tag)
	{
		f[x<<1].tag=f[(x<<1)+1].tag=f[x].tag;
		memset(f[x<<1].cnt,0,sizeof(f[x<<1].cnt)),
		memset(f[(x<<1)+1].cnt,0,sizeof(f[(x<<1)+1].cnt));
		f[x<<1].val[0]=f[x].tag,f[x<<1].cnt[0]=mid-nl+2,
		f[(x<<1)+1].val[0]=f[x].tag,f[(x<<1)+1].cnt[0]=nr-mid+1;
		f[x].tag=0;
	}
	update(nl,mid,l,r,x<<1,v),update(mid+1,nr,l,r,(x<<1)+1,v);
	f[x]=merge(f[x<<1],f[(x<<1)+1]);
	return ;
}
seg query(int nl,int nr,int l,int r,int x)
{
	if(nr<l||r<nl) return f[0];
	if(l<=nl&&nr<=r) return f[x];
	int mid=(nl+nr)>>1;
	if(f[x].tag)
	{
		f[x<<1].tag=f[(x<<1)+1].tag=f[x].tag;
		memset(f[x<<1].cnt,0,sizeof(f[x<<1].cnt)),
		memset(f[(x<<1)+1].cnt,0,sizeof(f[(x<<1)+1].cnt));
		f[x<<1].val[0]=f[x].tag,f[x<<1].cnt[0]=mid-nl+2,
		f[(x<<1)+1].val[0]=f[x].tag,f[(x<<1)+1].cnt[0]=nr-mid+1;
		f[x].tag=0;
	}
	return merge(query(nl,mid,l,r,x<<1),query(mid+1,nr,l,r,(x<<1)+1));
}
signed main()
{
	for(int i=1; i<=n; ++i) a[i]=read();
	build(1,n,1);
	for(int op,l,r; m--;)
	{
		op=read(),l=read(),r=read();
		if(op==1) update(1,n,l,r,1,read());
		else 
		{
			printf("%d ",S);
			seg t=query(1,n,l,r,1);
			for(int i=0; i<S; ++i) printf("%d ",t.val[i]);
			puts("");
		}
	}
	return 0;
}