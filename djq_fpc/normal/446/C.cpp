#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<iomanip>
#define sqr(x) (x)*(x)
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(int)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
//#define int long long
using namespace std;
int n,m,i,j,a[300005],mod=1e9+9,lt[1200005],rt[1200005],op,x,y,sum[1200005],add1[1200005],add2[1200005],f[300005],g[300005],invf,invg;
int qp(int x,int y)
{
	if (y==0) return 1;
	int z=qp(x,y/2);
	z=1ll*z*z%mod;
	if (y&1) z=1ll*z*x%mod;
	return z;
}
int qp2(int x,int y)
{
	if (y==0) return 1;
	if (x==691504013)
	{
		if (f[y]) return f[y];
		return f[y]=1ll*qp2(x,y-1)*691504013%mod;
	}
	if (x==308495997)
	{
		if (g[y]) return g[y];
		return g[y]=1ll*qp2(x,y-1)*308495997%mod;
	}
	if (x==691504013-1)
		if (y==mod-2)
		{
			if (invf) return invf;
			return invf=qp(x,y);
		}
	if (x==308495997-1)
		if (y==mod-2)
		{
			if (invg) return invg;
			return invg=qp(x,y);
		}
	exit(-1);
}
void build(int x,int l,int r)
{
	lt[x]=l;rt[x]=r;
	sum[x]=0;
	if (l==r)
	{
		return;
	}
	build(x*2,l,(l+r)/2);
	build(x*2+1,(l+r)/2+1,r);
}
int gts(int sx,int len,int gc)
{
	return (1ll*qp2(gc,len+1)-gc+mod)*sx%mod*qp2(gc-1,mod-2)%mod;
}
void add(int x,int c,int d)
{
	sum[x]=(mod+(sum[x]+gts(c,rt[x]-lt[x]+1,691504013)-gts(d,rt[x]-lt[x]+1,308495997))%mod)%mod;
	(add1[x]+=c)%=mod;
	(add2[x]+=d)%=mod;
}
void pushup(int x)
{
	sum[x]=(sum[x*2]+sum[x*2+1])%mod;
}
void pushdo(int x)
{
	add(x*2,add1[x],add2[x]);
	add(x*2+1,1ll*add1[x]*qp2(691504013,(rt[x*2]-lt[x*2]+1))%mod,1ll*add2[x]*qp2(308495997,(rt[x*2]-lt[x*2]+1))%mod);
	add1[x]=add2[x]=0;
}
void update(int x,int l,int r,int c,int d)
{
	if (lt[x]>r||rt[x]<l) return;
	if (lt[x]>=l&&rt[x]<=r)
	{
		add(x,1ll*c*qp2(691504013,(lt[x]-l))%mod,1ll*d*qp2(308495997,(lt[x]-l))%mod);
		return;
	}
	pushdo(x);
	update(x*2,l,r,c,d);
	update(x*2+1,l,r,c,d);
	pushup(x);
}
int query(int x,int l,int r)
{
	if (lt[x]>r||rt[x]<l) return 0;
	if (lt[x]>=l&&rt[x]<=r) return sum[x];
	pushdo(x);
	return (query(x*2,l,r)+query(x*2+1,l,r))%mod;
}
signed main()
{
	scanf("%d%d",&n,&m);
	fz1(i,n) scanf("%d",&a[i]);
	fz1(i,n) (a[i]+=a[i-1])%=mod;
	build(1,1,n);
	fz1(i,m)
	{
		scanf("%d",&op);
		if (op==1)
		{
			scanf("%d%d",&x,&y);
			update(1,x,y,1,1);
		}
		else
		{
			scanf("%d%d",&x,&y);
			printf("%d\n",(276601605ll*query(1,x,y)+a[y]-a[x-1]+mod)%mod);
		}
	}
	return 0;
}