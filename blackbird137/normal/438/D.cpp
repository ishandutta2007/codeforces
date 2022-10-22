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

const int N=1e5+5;
int n,m;

struct Seg
{
	int val[N<<2],mx[N<<2];
	inline void pushup(int x)
	{
		val[x]=val[lc]+val[rc];
		mx[x]=max(mx[lc],mx[rc]);
	}
	void build(int x,int l,int r)
	{
		if(l==r)
		{
			val[x]=read();
			mx[x]=val[x];
			return;
		}
		build(lc,l,mid);
		build(rc,mid+1,r);
		pushup(x);
	}
	void update1(int x,int l,int r,int L,int R,int v)
	{
		if(l==r)
		{
			val[x]%=v;
			mx[x]=val[x];
			return;
		}
		if(L<=mid&&mx[lc]>=v) update1(lc,l,mid,L,R,v);
		if(mid+1<=R&&mx[rc]>=v) update1(rc,mid+1,r,L,R,v);
		pushup(x);
	}
	void update2(int x,int l,int r,int p,int v)
	{
		if(l==r)
		{
			val[x]=v;
			mx[x]=val[x];
			return;
		}
		if(p<=mid) update2(lc,l,mid,p,v);
		else update2(rc,mid+1,r,p,v);
		pushup(x);
	}
	int query(int x,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return val[x];
		int res=0;
		if(L<=mid) res+=query(lc,l,mid,L,R);
		if(mid+1<=R) res+=query(rc,mid+1,r,L,R);
		return res;
	}
}sum;

signed main()
{
	n=read();m=read();
	sum.build(1,1,n);
	while(m--)
	{
		int opt=read();
		if(opt==1)
		{
			int l=read(),r=read();
			write(sum.query(1,1,n,l,r));
			puts("");
		}
		else if(opt==2)
		{
			int l=read(),r=read(),x=read();
			sum.update1(1,1,n,l,r,x);
		}
		else
		{
			int l=read(),x=read();
			sum.update2(1,1,n,l,x);
		}
	}
	return 0;
}