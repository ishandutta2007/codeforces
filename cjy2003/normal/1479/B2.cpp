#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,c[100010];
int mi[400010],ad[400010];
void build(int k,int l,int r)
{
	mi[k]=l==0?0:0x3f3f3f3f;
	if(l==r)return;
	build(k<<1,l,(l+r)>>1);
	build(k<<1|1,((l+r)>>1)+1,r);
}
void pushdown(int k)
{
	mi[k<<1]+=ad[k],mi[k<<1|1]+=ad[k];
	ad[k<<1]+=ad[k],ad[k<<1|1]+=ad[k];
	ad[k]=0;
}
void add(int k,int l,int r,int ll,int rr,int w)
{
	if(l>rr||r<ll)return ;
	if(l>=ll&&r<=rr)return mi[k]+=w,ad[k]+=w,void();
	if(ad[k])pushdown(k);
	add(k<<1,l,(l+r)>>1,ll,rr,w);
	add(k<<1|1,((l+r)>>1)+1,r,ll,rr,w);
	mi[k]=min(mi[k<<1],mi[k<<1|1]);
}
void upd(int k,int l,int r,int p,int w)
{
	if(l==r)return mi[k]=min(mi[k],w),void();
	if(ad[k])pushdown(k);
	if(p<=(l+r)>>1)upd(k<<1,l,(l+r)>>1,p,w);
	else upd(k<<1|1,((l+r)>>1)+1,r,p,w);
	mi[k]=min(mi[k<<1],mi[k<<1|1]);
}
int qmin(int k,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll)return 0x3f3f3f3f;
	if(l>=ll&&r<=rr)return mi[k];
	if(ad[k])pushdown(k);
	return min(qmin(k<<1,l,(l+r)>>1,ll,rr),qmin(k<<1|1,((l+r)>>1)+1,r,ll,rr));
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	build(1,0,n);
	for(int i=1;i<=n;++i)
	{
		int s=min(min(qmin(1,0,n,0,c[i]-1)+1,qmin(1,0,n,c[i]+1,n)+1),qmin(1,0,n,c[i],c[i]));
		if(c[i]!=c[i-1])++ad[1],++mi[1];
		upd(1,0,n,c[i-1],s);
	}
	printf("%d",mi[1]);
	return 0;
}