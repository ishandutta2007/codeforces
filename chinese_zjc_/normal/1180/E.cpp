// This code Write By chtholly_micromaker(MicroMaker)
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <algorithm>
#define reg register
#define int long long
using namespace std;
const int MaxN=600005;
template <class t> inline void rd(t &s)
{
	s=0;
	reg char c=getchar();
	while(!isdigit(c))
		c=getchar();
	while(isdigit(c))
		s=(s<<3)+(s<<1)+(c^48),c=getchar();
	return;
}
int a[MaxN],b[MaxN],vis[MaxN*3];
struct Quetion
{
	int idx,pos,val;
}que[MaxN];
struct SegTree
{
	#define rt (u>>1)
	#define lson (u<<1)
	#define rson (u<<1|1)
	struct Node
	{
		int val,lazy;
	};
	Node tr[MaxN<<2];
	inline void clear()
	{
		memset(tr,0,sizeof tr);
		return;
	}
	inline void pushup(int u)
	{
		tr[u].val=max(tr[lson].val,tr[rson].val);
		return;
	}
	inline void pushdown(int u,int l,int r)
	{
		if(tr[u].lazy)
		{
			tr[lson].lazy+=tr[u].lazy;
			tr[rson].lazy+=tr[u].lazy;
			tr[lson].val+=tr[u].lazy;
			tr[rson].val+=tr[u].lazy;
			tr[u].lazy=0;	
		}
		return;
	}
	inline void buildtr(int u,int l,int r)
	{
		if(l==r)
		{
			tr[u].val=0;
			return;
		}
		reg int mid=(l+r)>>1;
		buildtr(lson,l,mid);
		buildtr(rson,mid+1,r);
		pushup(rt);
		return;
	}
	inline void change(int u,int l,int r,int ql,int qr,int x)
	{
		if(ql==l&&r==qr)
		{
			tr[u].val+=x;
			tr[u].lazy+=x;
			return;
		}
		if(l==r)
			return;
		reg int mid=(l+r)>>1;
		pushdown(u,l,r);
		if(qr<=mid)
			change(lson,l,mid,ql,qr,x);
		else if(mid<ql)
			change(rson,mid+1,r,ql,qr,x);
		else
		{
			change(lson,l,mid,ql,mid,x);
			change(rson,mid+1,r,mid+1,qr,x);
		}
		pushup(u);
		return;
	}
	inline int query(int u,int l,int r,int ql,int qr)
	{
		if(l==r)
			return l;
		reg int mid=(l+r)>>1;
		pushdown(u,l,r);
		if(tr[rson].val>0)
			return query(rson,mid+1,r,ql,qr);
		else
			return query(lson,l,mid,ql,qr);
	}
	#undef rt
	#undef lson
	#undef rson
}segtree;
signed main(void)
{
	int n,m,q;
	reg int cnt=0;
	rd(n);rd(m);
	for(int i=1;i<=n;++i)
		rd(a[i]),vis[++cnt]=a[i];
	for(int i=1;i<=m;++i)
		rd(b[i]),vis[++cnt]=b[i];
	rd(q);
	for(int i=1;i<=q;++i)
	{
		rd(que[i].idx);rd(que[i].pos);rd(que[i].val);
		vis[++cnt]=que[i].val;
	}
	sort(vis+1,vis+cnt+1);
	cnt=unique(vis+1,vis+cnt+1)-vis-1;
	for(int i=1;i<=n;++i)
		a[i]=lower_bound(vis+1,vis+cnt+1,a[i])-vis;
	for(int i=1;i<=m;++i)
		b[i]=lower_bound(vis+1,vis+cnt+1,b[i])-vis;
	for(int i=1;i<=q;++i)
		que[i].val=lower_bound(vis+1,vis+cnt+1,que[i].val)-vis;
	segtree.buildtr(1,1,cnt);
	for(int i=1;i<=n;++i)
		segtree.change(1,1,cnt,1,a[i],1);
	for(int i=1;i<=m;++i)
		segtree.change(1,1,cnt,1,b[i],-1);
	for(int i=1;i<=q;++i)
	{
		if(que[i].idx==1)
		{
			segtree.change(1,1,cnt,1,a[que[i].pos],-1);
			a[que[i].pos]=que[i].val;
			segtree.change(1,1,cnt,1,a[que[i].pos],1);
		}
		else
		{
			segtree.change(1,1,cnt,1,b[que[i].pos],1);
			b[que[i].pos]=que[i].val;
			segtree.change(1,1,cnt,1,b[que[i].pos],-1);
		}
		if(segtree.tr[1].val<=0)
			puts("-1");
		else
			printf("%lld\n",vis[segtree.query(1,1,cnt,1,cnt)]);
	}
	return 0;
}