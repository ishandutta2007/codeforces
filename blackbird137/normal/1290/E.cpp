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
#define pb(x) push_back(x)
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
int n,a[N],b[N];

struct Seg
{
	int val[N<<2],mx[N<<2],se[N<<2],sm[N<<2];
	int len[N<<2],tg1[N<<2],tg2[N<<2];
	void pushup(int x)
	{
		val[x]=val[lc]+val[rc];
		len[x]=len[lc]+len[rc];
		mx[x]=max(mx[lc],mx[rc]);
		se[x]=max(se[lc],se[rc]);
		if(mx[lc]==mx[rc])
			sm[x]=sm[lc]+sm[rc];
		else
		{
			se[x]=max(se[x],min(mx[lc],mx[rc]));
			sm[x]=(mx[lc]>mx[rc])?sm[lc]:sm[rc];
		}
	}
	void build(int x,int l,int r)
	{
		val[x]=sm[x]=len[x]=tg2[x]=0;
		mx[x]=se[x]=-INF;tg1[x]=INF;
		if(l==r) return;
		build(lc,l,mid);
		build(rc,mid+1,r);
	}
	void pushtag1(int x,int v)
	{
		if(v>=mx[x]) return;
		val[x]-=sm[x]*(mx[x]-v);
		mx[x]=tg1[x]=v;
	}
	void pushtag2(int x,int v)
	{
		val[x]+=len[x]*v;
		mx[x]+=v;se[x]+=v;
		tg1[x]+=v;tg2[x]+=v;
	}
	void pushdown(int x)
	{
		if(tg2[x])
		{
			pushtag2(lc,tg2[x]);
			pushtag2(rc,tg2[x]);
			tg2[x]=0;
		}
		if(tg1[x]!=INF)
		{
			pushtag1(lc,tg1[x]);
			pushtag1(rc,tg1[x]);
			tg1[x]=INF;
		}
	}
	void update1(int x,int l,int r,int L,int R,int v)
	{
		if(L>R||!sm[x]||v>=mx[x]) return;
		if(L<=l&&r<=R&&v>=se[x])
			return pushtag1(x,v),void();
		pushdown(x);
		if(L<=mid) update1(lc,l,mid,L,R,v);
		if(mid+1<=R) update1(rc,mid+1,r,L,R,v);
		pushup(x);
	}
	void update2(int x,int l,int r,int L,int R,int v)
	{
		if(L>R) return;
		if(L<=l&&r<=R)
			return pushtag2(x,v),void();
		pushdown(x);
		if(L<=mid) update2(lc,l,mid,L,R,v);
		if(mid+1<=R) update2(rc,mid+1,r,L,R,v);
		pushup(x);
	}
	void update3(int x,int l,int r,int p,int v)
	{
		if(l==r)
		{
			val[x]=mx[x]=v;
			sm[x]=len[x]=1;
			return;
		}
		pushdown(x);
		if(p<=mid) update3(lc,l,mid,p,v);
		else update3(rc,mid+1,r,p,v);
		pushup(x);
	}
	int query()
	{
		return val[1];
	}
}pre,suc;

struct BIT
{
	int c[N];
	inline void add(int x,int v)
	{
		for(;x<=n;x+=lowbit(x))
			c[x]+=v;
	}
	inline int query(int x)
	{
		int res=0;
		for(;x;x-=lowbit(x))
			res+=c[x];
		return res;
	}
	inline int query(int l,int r)
	{
		return query(r)-query(l-1);
	}
	inline void clear()
	{
		for(int i=1;i<=n;++i)
			c[i]=0;
	}
}sum;

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		int x=read();
		a[x]=i;b[x]=sum.query(x)+1;
		sum.add(x,1);
	}
	pre.build(1,1,n);
	suc.build(1,1,n);
	for(int i=1;i<=n;++i)
	{
		int x=a[i],y=b[i];
		pre.update3(1,1,n,x,0);
		suc.update3(1,1,n,x,i+1);
		pre.update2(1,1,n,x+1,n,-1);
		suc.update2(1,1,n,x+1,n,1);
		pre.update1(1,1,n,x+1,n,-y);
		suc.update1(1,1,n,1,x-1,y);
		write(suc.query()+pre.query()-i);
		puts("");
	}
	return 0;
}