#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
const int MAXN=1e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,K,num[MAXN*3],m;
long long ans;
struct data
{
	int x,r,f;
	int L,R;
}a[MAXN];
int cmp1(data x,data y){return x.r<y.r;}
int cmp2(data x,data y){return x.f<y.f;}
int tree[MAXN*3],dfn[MAXN*3],tim;
#define lowbit(k) (k&-k)
void xg(int zone,int v)
{
	while(zone<=m)
	{
		if(dfn[zone]!=tim) dfn[zone]=tim,tree[zone]=0;
		tree[zone]+=v;
		zone+=lowbit(zone);
	}
}
int cx(int zone)
{
	int bck=0;
	while(zone)
	{
		if(dfn[zone]!=tim) dfn[zone]=tim,tree[zone]=0;
		bck+=tree[zone];
		zone-=lowbit(zone);
	}
	return bck;
}
void CDQ(int l,int r)
{
	if(l==r) return;
	int mid=(l+r)>>1;
	CDQ(l,mid);
	CDQ(mid+1,r);
	sort(a+l,a+mid+1,cmp2);
	sort(a+mid+1,a+r+1,cmp2);

	++tim;
	for(int i=l,L=mid,R=mid;i<=mid;++i)
	{
		while(R+1<=r && a[R+1].f<=a[i].f)
		{
			++R;
			xg(a[R].x,1);
		}
		while(L!=R && a[i].f-a[L+1].f>K)
		{
			++L;
			xg(a[L].x,-1);
		}
		ans+=cx(a[i].R)-cx(a[i].L-1);
	}

	++tim;
	for(int i=mid,L=r+1,R=r+1;i>=l;--i)
	{
		while(L-1>mid && a[L-1].f>a[i].f)
		{
			--L;
			xg(a[L].x,1);
		}
		while(L!=R && a[R-1].f-a[i].f>K)
		{
			--R;
			xg(a[R].x,-1);
		}
		ans+=cx(a[i].R)-cx(a[i].L-1);
	}
}
int main()
{
	n=read(),K=read();
	for(int i=1;i<=n;++i)
	{
		num[++m]=a[i].x=read(),a[i].r=read(),a[i].f=read();
		num[++m]=a[i].L=a[i].x-a[i].r;
		num[++m]=a[i].R=a[i].x+a[i].r;
	}
	sort(num+1,num+m+1);
	m=unique(num+1,num+m+1)-num-1;
	for(int i=1;i<=n;++i)
	{
		a[i].x=lower_bound(num+1,num+m+1,a[i].x)-num;
		a[i].L=lower_bound(num+1,num+m+1,a[i].L)-num;
		a[i].R=lower_bound(num+1,num+m+1,a[i].R)-num;
	}
	sort(a+1,a+n+1,cmp1);
	CDQ(1,n);
	printf("%lld\n",ans);
	return 0;
}