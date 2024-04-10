#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define lowbit(k) (k&-k)
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,K,tree[300001],num[300001],cnt;
long long ans;
struct data
{
	int x,r,q,L,R;
}mem[100001];
int cmp1(data x,data y)
{
	return x.r>y.r;
}
int cmp2(data x,data y)
{
	return x.q<y.q;
}
void xg(int zone,int v)
{
	while(zone<=cnt)
	{
		tree[zone]+=v;
		zone+=lowbit(zone);
	}
}
int cx(int zone)
{
	int bck=0;
	while(zone)
	{
		bck+=tree[zone];
		zone-=lowbit(zone);
	}
	return bck;
}
void CDQ(int l,int r)
{
	if(l==r)
		return;
	int mid=(l+r)/2;
	CDQ(l,mid);
	CDQ(mid+1,r);
	sort(mem+l,mem+mid+1,cmp2);
	sort(mem+mid+1,mem+r+1,cmp2);
	int bjl=l,bjr=l-1;
	for(int i=mid+1;i<=r;++i)
	{
		while(bjl<=mid && mem[bjl].q<mem[i].q-K)
		{
			xg(mem[bjl].x,-1);
			++bjl;
		}
		while(bjr+1<=mid && mem[bjr+1].q<=mem[i].q+K)
		{
			++bjr;
			xg(mem[bjr].x,1);
		}
		ans+=cx(mem[i].R)-cx(mem[i].L-1);
	}
	while(bjl<=bjr)
	{
		xg(mem[bjl].x,-1);
		++bjl;
	}
}
int main()
{
	n=read(),K=read();
	for(int i=1;i<=n;++i)
	{
		mem[i].x=read(),mem[i].r=read(),mem[i].q=read();
		num[++cnt]=mem[i].x;
		num[++cnt]=mem[i].x-mem[i].r;
		num[++cnt]=mem[i].x+mem[i].r;
	}
	sort(num+1,num+cnt+1);
	cnt=unique(num+1,num+cnt+1)-num-1;
	for(int i=1;i<=n;++i)
	{
		mem[i].L=lower_bound(num+1,num+cnt+1,mem[i].x-mem[i].r)-num;
		mem[i].R=lower_bound(num+1,num+cnt+1,mem[i].x+mem[i].r)-num;
		mem[i].x=lower_bound(num+1,num+cnt+1,mem[i].x)-num;
	}
	sort(mem+1,mem+n+1,cmp1);
	CDQ(1,n);
	printf("%lld\n",ans);
	return 0;
}