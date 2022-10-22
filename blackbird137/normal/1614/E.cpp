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
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f3f3f3f3f

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

const int N=2e5+5;
int n,a[N],rt;

struct Seg
{
	int val[N*35],lc[N*35],rc[N*35],cnt;
	void update(int &x,int l,int r,int p,int v)
	{
		if(p<0||p>1e9)
			return;
		if(!x) x=++cnt;
		if(l==r)
		{
			val[x]+=v;
			return;
		}
		if(p<=mid) update(lc[x],l,mid,p,v);
		else update(rc[x],mid+1,r,p,v);
		val[x]=val[lc[x]]+val[rc[x]];
	}
	int query(int x,int l,int r,int L,int R)
	{
		if(!x) return 0;
		if(L<=l&&r<=R) return val[x];
		int res=0;
		if(L<=mid) res+=query(lc[x],l,mid,L,R);
		if(mid+1<=R) res+=query(rc[x],mid+1,r,L,R);
		return res;
	}
}sum;

signed main()
{
	n=read();
	int lastans=0;
	while(n--)
	{
		int x=read();
		int l=0,r=1e9,ps=-1;
		while(l<=r)
		{
			if(mid-sum.query(rt,0,1e9,0,mid)<x)
				ps=mid,l=mid+1;
			else r=mid-1;
		}
		if(ps!=-1)
		{
			sum.update(rt,0,1e9,0,-1);
			sum.update(rt,0,1e9,ps+1,1);
		}
		l=0,r=1e9,ps=-1;
		while(l<=r)
		{
			if(mid-sum.query(rt,0,1e9,0,mid)>x)
				ps=mid,r=mid-1;
			else l=mid+1;
		}
		if(ps!=-1)
			sum.update(rt,0,1e9,ps,1);
		x=read();
		while(x--)
		{
			int y=(read()+lastans)%(1000000001);
			lastans=y-sum.query(rt,0,1e9,0,y);
			printf("%d\n",lastans);
		}
	}
	return 0;
}