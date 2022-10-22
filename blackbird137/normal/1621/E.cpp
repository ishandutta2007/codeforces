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

#define int long long
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

const int N=3e5+5;
int t,n,m,a[N],k[N],sm[N],c[N];
double b[N];

vector<int> p[N];

bool cmp(int a,int b)
{
	return a>b;
}

struct Node
{
	double x;
	int y;
	bool operator < (const Node &p)const
	{
		return x>p.x;
	}
}B[N];

struct Seg
{
	int val[N<<2];
	void build(int x,int l,int r)
	{
		val[x]=0;
		if(l>=r) return;
		build(lc,l,mid);
		build(rc,mid+1,r);
	}
	void update(int x,int l,int r,int p)
	{
		if(l==r)
		{
			val[x]=1;
			return;
		}
		if(p<=mid) update(lc,l,mid,p);
		else update(rc,mid+1,r,p);
		val[x]=(val[lc]&val[rc]);
	}
	int query(int x,int l,int r,int L,int R)
	{
		if(L>R) return 1;
		if(L<=l&&r<=R) return val[x];
		int res=1;
		if(L<=mid) res&=query(lc,l,mid,L,R);
		if(mid+1<=R) res&=query(rc,mid+1,r,L,R);
		return res;
	}
}s0,s1,s2;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=m;++i)
		{
			p[i].clear();
			k[i]=read();sm[i]=0;
			for(int j=1;j<=k[i];++j)
			{
				int x=read();
				p[i].push_back(x);
				sm[i]+=x;
			}
			B[i].x=(sm[i]+0.0)/k[i];
			B[i].y=i;
		}
		sort(B+1,B+1+m);
		s0.build(1,2,m);
		s1.build(1,1,m);
		s2.build(1,1,m-1);
		s1.query(1,1,m,2,3);
		for(int i=1;i<=m;++i)
		{
			c[B[i].y]=i;b[i]=B[i].x;
			if(i!=1&&a[i-1]>=b[i]) s0.update(1,2,m,i);
			if(a[i]>=b[i]) s1.update(1,1,m,i);
			if(i!=m&&a[i+1]>=b[i]) s2.update(1,1,m-1,i);
		}
		for(int i=1;i<=m;++i)
			for(int j=1;j<=k[i];++j)
			{
				double now=(sm[i]-p[i][j-1]+0.0)/(k[i]-1);
				int l=1,r=m,ps=0;
				while(l<=r)
				{
					if(b[mid]>now)
						ps=mid,l=mid+1;
					else r=mid-1;
				}
				if(ps<c[i]) ps++;
				if(now>b[c[i]])
				{
					int flag=1;
					flag&=s1.query(1,1,m,1,ps-1);
					flag&=s1.query(1,1,m,c[i]+1,m);
					flag&=s2.query(1,1,m-1,ps,c[i]-1);
					flag&=(now<=a[ps]);
					write(flag);
				}
				else
				{
					int flag=1;
					flag&=s1.query(1,1,m,1,c[i]-1);
					flag&=s1.query(1,1,m,ps+1,m);
					flag&=s0.query(1,2,m,c[i]+1,ps);
					flag&=(now<=a[ps]);
					write(flag);
				}
			}
		puts("");
	}
	return 0;
}