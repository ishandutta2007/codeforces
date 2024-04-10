#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,c[100010];
int mx[400010],ad[400010];
void pushdown(int k)
{
	mx[k<<1]+=ad[k],mx[k<<1|1]+=ad[k];
	ad[k<<1]+=ad[k],ad[k<<1|1]+=ad[k];
	ad[k]=0;
}
void add(int k,int l,int r,int ll,int rr,int w)
{
	if(l>rr||r<ll)return ;
	if(l>=ll&&r<=rr)return mx[k]+=w,ad[k]+=w,void();
	if(ad[k])pushdown(k);
	add(k<<1,l,(l+r)>>1,ll,rr,w);
	add(k<<1|1,((l+r)>>1)+1,r,ll,rr,w);
	mx[k]=max(mx[k<<1],mx[k<<1|1]);
}
void upd(int k,int l,int r,int p,int w)
{
	if(l==r)return mx[k]=max(mx[k],w),void();
	if(ad[k])pushdown(k);
	if(p<=(l+r)>>1)upd(k<<1,l,(l+r)>>1,p,w);
	else upd(k<<1|1,((l+r)>>1)+1,r,p,w);
	mx[k]=max(mx[k<<1],mx[k<<1|1]);
}
int qmax(int k,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll)return 0;
	if(l>=ll&&r<=rr)return mx[k];
	if(ad[k])pushdown(k);
	return max(qmax(k<<1,l,(l+r)>>1,ll,rr),qmax(k<<1|1,((l+r)>>1)+1,r,ll,rr));
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	for(int i=1;i<=n;++i)
	{
		int s=max(max(qmax(1,1,n,1,c[i]-1)+1,qmax(1,1,n,c[i]+1,n)+1),qmax(1,1,n,c[i],c[i]));
		if(c[i]!=c[i-1])++ad[1],++mx[1];
		upd(1,1,n,c[i-1],s);
	}
	printf("%d",mx[1]);
	return 0;
}