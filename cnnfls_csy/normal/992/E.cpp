#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x)(x)*(x)
#define fz1(i,n) for (i=1;i<=n;i++)
#define fd1(i,n) for (i=n;i>=1;i--)
#define fz0g(i,n) for (i=0;i<=n;i++)
#define fd0g(i,n) for (i=n;i>=0;i--)
#define fz0k(i,n) for (i=0;i<n;i++)
#define fd0k(i,n) for (i=(long long)(n-1);i>=0;i--)
#define fz(i,x,y) for (i=x;i<=y;i++)
#define fd(i,y,x) for (i=y;i>=x;i--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
long long n,m,i,j,num[200005],x,y;
struct bit
{
	long long arr[200005];
	int lowbit(int x){return x&(-x);}
	void add(int x,long long y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}
	long long query(int x){long long s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}
};
bit b;
struct seg_tree
{
	struct treedot
	{
		int l,r;
		long long add,mx;
		void update(long long x)
		{
			mx+=x;
			add+=x;
		}
	}c[800005];
	void pushdown(int id)
	{
		if (c[id].add)
		{
			c[id*2].update(c[id].add);
			c[id*2+1].update(c[id].add);
			c[id].add=0;
		}
	}
	void pushup(int id)
	{
		c[id].mx=max(c[id*2].mx,c[id*2+1].mx);
	}
	void build(int id,int l,int r)
	{
		if (l>r) return;
		c[id].l=l;
		c[id].r=r;
		c[id].mx=0;
		c[id].add=0;
		if (l==r) c[id].mx=0;
		else
		{
			int mid=l+(r-l)/2;
			build(id*2,l,mid);
			build(id*2+1,mid+1,r);
			pushup(id);
		}
	}
	void update(int id,int le,int ri,long long x)
	{
		if (le>c[id].r||ri<c[id].l) return;
		if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);
		else
		{
			pushdown(id);
			update(id*2,le,ri,x);
			update(id*2+1,le,ri,x);
			pushup(id);
		}
	}
	int query(int x,long long y,int l)
	{
		if (c[x].r<l) return -1;
		if (c[x].mx<y) return -1;
		if (c[x].l==c[x].r)
		{
			if (b.query(c[x].l-1)==c[x].mx) return c[x].l;
			if (y<=c[x].mx) return -c[x].l;
			return -1;
		}
		int ans=-1;
		if (c[x*2].mx>=y&&c[x*2].r!=1) ans=query(x*2,y,l);
		if (ans==-1&&c[x*2+1].r!=1&&c[x*2+1].mx>=y) ans=query(x*2+1,y,l);
		return ans;
	}
	int query2()
	{
		int x=query(1,num[1],1);
		for(;;)
		{
			if (x==-1) return -1;
			if (x>0) return x;
			x=query(1,b.query(-x),-x);
		}
		return -1;
	}
}seg;
int main()
{
	scanf("%I64d%I64d",&n,&m);
	seg.build(1,2,n);
	fz1(i,n)
	{
		scanf("%I64d",&num[i]);
		b.add(i,num[i]);
		if (i!=1) seg.update(1,i,i,num[i]);
	}
//	seg.update(1,1,1,-1ll<<50);
	fz1(i,m)
	{
		scanf("%I64d%I64d",&x,&y);
		long long t=y-num[x];
		num[x]=y;
		b.add(x,t);
		if (x!=1) seg.update(1,x,x,t);
		if (num[1]==0)
		{
			puts("1");
			continue;
		}
		printf("%d\n",seg.query2());
	}
	return 0;
}