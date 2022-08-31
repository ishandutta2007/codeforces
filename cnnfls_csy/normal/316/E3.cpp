#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
long long n,m,i,j,mod=1e9,fb[100005],pfb[100005],op,x,y,z;
inline long long gfb(long long x)
{
	if (x<0) return 0;
	return fb[x];
}
inline long long gpfb(long long x)
{
	if (x<0) return 0;
	return pfb[x];
}
struct seg_tree
{
	struct seg
	{
		long long l,r,len,add,sum0,sum1;
	}tr[800005];
	/*void pushup(long long x)
	{
		tr[x]=(seg){
		tr[x].l,
		tr[x].r,
		tr[x].r-tr[x].l+1,
		tr[x].add,
		tr[x*2].sum0+tr[x*2+1].sum1*gfb(tr[x].len-2)+tr[x*2+1].sum0*gfb(tr[x].len-1),
		tr[x*2].sum1+tr[x*2+1].sum1*gfb(tr[x].len-1)+tr[x*2+1].sum0*gfb(tr[x].len)};
	}*/
	inline seg add(const seg &x,const seg &y)
	{
		seg ans;
		ans.l=x.l;
		ans.r=y.r;
		ans.len=x.len+y.len;
		ans.add=0;
		(ans.sum0=x.sum0+1ll*y.sum0*gfb(x.len-2)+1ll*y.sum1*gfb(x.len-1))%=mod;
		(ans.sum1=x.sum1+1ll*y.sum0*gfb(x.len-1)+1ll*y.sum1*gfb(x.len))%=mod;
		return ans;
	}
	inline void pushdown(long long x)
	{
		if (tr[x].add)
		{
			if (tr[x].l!=tr[x].r)
			{
				(tr[x*2].add+=tr[x].add)%=mod;
				(tr[x*2+1].add+=tr[x].add)%=mod;
			}
			(tr[x].sum1+=1ll*tr[x].add*(gpfb(tr[x].len-1)))%=mod;
			(tr[x].sum0+=1ll*tr[x].add*gpfb(tr[x].len-2))%=mod;
			tr[x].add=0;
		}
	}
	inline void pushup(long long x)
	{
		tr[x]=add(tr[x*2],tr[x*2+1]);
	}
	inline void build(long long x,long long l,long long r)
	{
		tr[x]=(seg){l,r,r-l+1,0,0,0};
		if (l!=r)
		{
			build(x*2,l,(l+r)/2);
			build(x*2+1,(l+r)/2+1,r);
			pushup(x);
		}
	}
	inline void update(long long x,long long c,long long y)
	{
		pushdown(x);
		if (tr[x].l>c||tr[x].r<c) return;
		if (tr[x].l==c&&tr[x].r==c)
		{
			tr[x].sum0=0;
			tr[x].sum1=y;
			return;
		}
		update(x*2,c,y);
		update(x*2+1,c,y);
		pushup(x);
	}
	inline void update2(long long x,long long l,long long r,long long y)
	{
		pushdown(x);
		if (tr[x].l>r||tr[x].r<l) return;
		if (tr[x].l>=l&&tr[x].r<=r)
		{
			(tr[x].add+=y)%=mod;
			pushdown(x);
			return;
		}
		update2(x*2,l,r,y);
		update2(x*2+1,l,r,y);
		pushup(x);
	}
	inline seg query(long long x,long long l,long long r)
	{
		pushdown(x);
		if (tr[x].l>r||tr[x].r<l) return (seg){0,0,0,0,0,0};
		if (tr[x].l>=l&&tr[x].r<=r) return tr[x];
		return add(query(x*2,l,r),query(x*2+1,l,r));
	}
}tr;
int main()
{
	fb[0]=fb[1]=pfb[0]=1;
	pfb[1]=2;
	for (i=2;i<=100000;i++)
	{
		fb[i]=fb[i-1]+fb[i-2];
		fb[i]%=mod;
		pfb[i]=pfb[i-1]+fb[i];
		pfb[i]%=mod;
	}
	scanf("%I64d%I64d",&n,&m);
	tr.build(1,1,n);
	for (i=1;i<=n;i++)
	{
		scanf("%I64d",&x);
		tr.update(1,i,x);
	}
	for (i=1;i<=m;i++)
	{
		scanf("%I64d",&op); 
		if (op==1)
		{
			scanf("%I64d%I64d",&x,&y);
			tr.update(1,x,y); 
		}
		if (op==2)
		{
			scanf("%I64d%I64d",&x,&y);
			printf("%I64d\n",tr.query(1,x,y).sum1);
		}
		if (op==3)
		{
			scanf("%I64d%I64d%I64d",&x,&y,&z);
			tr.update2(1,x,y,z);
		}
	}
	return 0;
}