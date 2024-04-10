#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[300030];
namespace seg
{
	int mi[1200010],mip[1200010],ad[1200010];
	#define ls k<<1,l,(l+r)>>1
	#define rs k<<1|1,((l+r)>>1)+1,r
	void build(int k,int l,int r)
	{
		if(l==r)
		{
			if(a[l]>l)mi[k]=0x3f3f3f3f;
			else mi[k]=l-a[l],mip[k]=l;
			return;
		}
		build(ls),build(rs);
		mi[k]=min(mi[k<<1],mi[k<<1|1]);
		mip[k]=mi[k<<1|1]==mi[k]?mip[k<<1|1]:mip[k<<1];
	}
	void pushdown(int k)
	{
		mi[k<<1]+=ad[k];ad[k<<1]+=ad[k];
		mi[k<<1|1]+=ad[k];ad[k<<1|1]+=ad[k];
		ad[k]=0;
	}
	void upd(int k,int l,int r,int p)
	{
		if(l==r)return mi[k]=0x3f3f3f3f,void();
		if(ad[k])pushdown(k);
		if(p<=(l+r)>>1)upd(ls,p);
		else upd(rs,p);
		mi[k]=min(mi[k<<1],mi[k<<1|1]);
		mip[k]=mi[k<<1|1]==mi[k]?mip[k<<1|1]:mip[k<<1];
	}
	void add(int k,int l,int r,int ll,int rr)
	{
		if(l>rr||r<ll)return;
		if(l>=ll&&r<=rr)
		{
			--mi[k],--ad[k];
			return;
		}
		if(ad[k])pushdown(k);
		add(ls,ll,rr);
		add(rs,ll,rr);
		mi[k]=min(mi[k<<1],mi[k<<1|1]);
		mip[k]=mi[k<<1|1]==mi[k]?mip[k<<1|1]:mip[k<<1];
	}
}
using namespace seg;
namespace BIT
{
	int sum[300030];
	inline void add(int p){while(p<=n)++sum[p],p+=p&-p;}
	inline int qry(int p){int s=0;while(p)s+=sum[p],p-=p&-p;return s;}
}
int st[300030],tp;
struct query
{
	int l,r,id;
	friend bool operator < (query a,query b){return a.l>b.l;}
}q[300030];
int ans[300030];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	build(1,1,n);
	while(mi[1]==0)
	{
		int x=mip[1];
		st[++tp]=x;
		upd(1,1,n,x);
		add(1,1,n,x+1,n);
		// printf("%d ",x);
	}
	// printf("\n");
	for(int i=1;i<=m;++i)scanf("%d %d",&q[i].l,&q[i].r),q[i].id=i;
	sort(q+1,q+1+m);
	for(int i=1,last=1;i<=m;++i)
	{
		while(last<=tp&&st[last]>q[i].l)BIT::add(st[last]),++last;
		ans[q[i].id]=BIT::qry(n-q[i].r);
	}
	for(int i=1;i<=m;++i)printf("%d\n",ans[i]);
	return 0;
}