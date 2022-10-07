#include<bits/stdc++.h>
using namespace std;
int n,L,l,r,lar,i,k;
long double s,tree[2000005],ans,mn[2000005],e[500005];
struct str{
	int x,l;
	long double v;
}a[500005],b[500005];
bool cmp(str a,str b)
{
	return a.v<b.v;
}
void pushup(int i)
{
	tree[i]=tree[i<<1]+tree[i<<1|1];
	mn[i]=min(mn[i<<1],mn[i<<1|1]+tree[i<<1]);
}
void modify(int i,int l,int r,int x,double y)
{
	if(l==r)
	{
		tree[i]+=y;
		mn[i]+=y;
		return;
	}
	int mid=l+r>>1;
	if(mid>=x)
		modify(i<<1,l,mid,x,y);
	else
		modify(i<<1|1,mid+1,r,x,y);
	pushup(i);
}
long double Query(int i,int l,int r,int ll,int rr,long double ad)
{
	if(l>=ll&&r<=rr)
		return mn[i]+ad;
	int mid=l+r>>1;
	long double ans=100000000000000.0;
	if(mid>=ll)
		ans=Query(i<<1,l,mid,ll,rr,ad);
	if(mid<rr)
		ans=min(ans,Query(i<<1|1,mid+1,r,ll,rr,ad+tree[i<<1]));
	return ans;
}
int main()
{
	scanf("%d %d",&n,&L);
	for(i=1;i<=n;++i)
	{
		scanf("%d %d %LF",&l,&r,&s);
		a[++k].v=1;
		a[k].l=l-lar;
		a[k].x=k;
		lar=r;
		a[++k].v=s+1;
		a[k].l=r-l;
		a[k].x=k;
	}
	a[++k].v=1;
	a[k].l=L-lar;
	a[k].x=k;
	for(i=1;i<=k;++i)
	{
		ans+=a[i].l/a[i].v;
		if(a[i].v==1)
			e[i]=a[i].l;
		else
			e[i]=a[i].l/(a[i].v-1);
		ans+=e[i]/a[i].v;
		modify(1,1,k,i,e[i]);
	}
	sort(a+1,a+1+k,cmp);
	for(i=1;i<=k;++i)
	{
		long double ad=min(Query(1,1,k,a[i].x,k,0),e[a[i].x]+a[i].l/(a[i].v+1));
		e[a[i].x]-=ad;
		ans-=ad/a[i].v;
		modify(1,1,k,a[i].x,-ad);
	}
	printf("%.12LF",ans);
}