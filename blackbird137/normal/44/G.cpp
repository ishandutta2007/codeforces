#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=1e5+5;
int n,m,ans[N],ps[N];

struct Plane
{
	int xl,xr,yl,yr,z,id;
	bool operator < (const Plane &x)const
	{
		return z<x.z;
	}
}a[N],c[N<<2];

struct Point
{
	int x,y,z;
}b[N];

inline bool cmpX(Point &a,Point &b)
{
	return a.x<b.x;
}

inline bool cmpY(Point &a,Point &b)
{
	return a.y<b.y;
}

void build(int x,int l,int r,bool kd)
{
	if(l==r)
	{
		c[x].xl=c[x].xr=b[l].x;
		c[x].yl=c[x].yr=b[l].y;
		c[x].z=b[l].z;ps[b[l].z]=l;return;
	}
	nth_element(b+l,b+mid,b+r+1,kd?cmpX:cmpY);
	build(lc,l,mid,!kd);
	build(rc,mid+1,r,!kd);
	c[x].z=min(c[lc].z,c[rc].z);
	c[x].xl=min(c[lc].xl,c[rc].xl);
	c[x].yl=min(c[lc].yl,c[rc].yl);
	c[x].xr=max(c[lc].xr,c[rc].xr);
	c[x].yr=max(c[lc].yr,c[rc].yr);
}

void update(int x,int l,int r,int p)
{
	if(l==r){c[x].z=m+1;return;}
	if(p<=mid) update(lc,l,mid,p);
	else update(rc,mid+1,r,p);
	c[x].z=min(c[lc].z,c[rc].z);
}

Plane p;
void query(int x)
{
	if(c[x].z>=p.z) return;
	if(p.xr<c[x].xl||p.xl>c[x].xr) return;
	if(p.yr<c[x].yl||p.yl>c[x].yr) return;
	if(p.xl<=c[x].xl&&p.xr>=c[x].xr&&p.yl<=c[x].yl&&p.yr>=c[x].yr)
		{p.z=min(p.z,c[x].z);return;}
	int res=1e9;
	if(c[lc].z<c[rc].z)
		query(lc),query(rc);
	else query(rc),query(lc);
}

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		a[i].xl=read();
		a[i].xr=read();
		a[i].yl=read();
		a[i].yr=read();
		a[i].z=read();a[i].id=i;
	}
	sort(a+1,a+1+n);
	m=read();
	for(int i=1;i<=m;++i)
	{
		b[i].x=read();
		b[i].y=read();
		b[i].z=i; 
	}
	build(1,1,m,0);
	for(int i=1;i<=n;++i)
	{
		p=a[i];p.z=m+1;
		query(1);
		if(p.z==m+1)
			continue;
		ans[p.z]=p.id;
		update(1,1,m,ps[p.z]);
	}
	for(int i=1;i<=m;++i)
		write(ans[i]),puts("");
	return 0;
}