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

const int N=1e6+5;
int n,q,a[4][N],v1[N],v2[N],dp[N],DP[N],ans=-INF;

struct Seg
{
	int val[N<<2];
	void build(int x,int l,int r)
	{
		val[x]=-INF;
		if(l==r) return;
		build(lc,l,mid);
		build(rc,mid+1,r);
	}
	void update(int x,int l,int r,int p,int v)
	{
		if(l==r)
		{
			val[x]=max(val[x],v);
			return;
		}
		if(p<=mid) update(lc,l,mid,p,v);
		else update(rc,mid+1,r,p,v);
		val[x]=max(val[lc],val[rc]);
	}
	int query(int x,int l,int r,int L,int R)
	{
		if(L==0) L=1;
		if(L<=l&&r<=R) return val[x];
		int res=-INF;
		if(L<=mid) res=max(res,query(lc,l,mid,L,R));
		if(mid+1<=R) res=max(res,query(rc,mid+1,r,L,R));
		return res;
	}
}s0,s1;

struct node
{
	int v,s1,s2;
	node operator + (const node &x)const
	{
		node res;
		res.v=max(v,x.v);
		res.v=max(res.v,s1+x.s2);
		res.s1=max(s1,x.s1);
		res.s2=max(s2,x.s2);
		return res;
	}
};

struct Seg2
{
	node val[N<<2];
	void build(int x,int l,int r)
	{
		val[x]=(node){-INF,-INF,-INF};
		if(l==r) return;
		build(lc,l,mid);
		build(rc,mid+1,r);
	}
	void update(int x,int l,int r,int p,int v1,int v2)
	{
		if(l==r)
		{
			val[x]=(node){v1+v2,v1,v2};
			return;
		}
		if(p<=mid) update(lc,l,mid,p,v1,v2);
		else update(rc,mid+1,r,p,v1,v2);
		val[x]=val[lc]+val[rc];
	}
	node query(int x,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R)
			return val[x];
		if(L<=mid&&mid+1<=R)
			return query(lc,l,mid,L,R)+query(rc,mid+1,r,L,R);
		else if(L<=mid) return query(lc,l,mid,L,R);
		else return query(rc,mid+1,r,L,R);
	}
}s2;

struct Node
{
	int l,r,v;
	bool operator < (const Node &x)const
	{
		if(r==x.r)
			return l<x.l;
		return r<x.r;
	}
}b[N];

signed main()
{
	n=read();q=read();
	for(int i=1;i<=3;++i)
		for(int j=1;j<=n;++j)
			a[i][j]=read();
	for(int i=1;i<=q;++i)
	{
		b[i].l=read();
		b[i].r=read();
		b[i].v=read();
	}
	sort(b+1,b+1+q);
	for(int i=1;i<=n;++i)
	{
		a[1][i]+=a[1][i-1];
		a[2][i]+=a[2][i-1];
		a[3][i]+=a[3][i-1];
	}
	for(int i=1;i<=n;++i)
	{
		v1[i]=a[1][i]-a[2][i-1];
		v2[i]=a[3][n]-a[3][i-1]+a[2][i];
	}
	s0.build(1,1,n);
	s1.build(1,1,n);
	s2.build(1,1,n);
	for(int i=1;i<=n;++i)
	{
		s0.update(1,1,n,i,v1[i]);DP[i]=-INF;
		s2.update(1,1,n,i,v1[i],v2[i]);
	}
	for(int i=1;i<=q;++i)
	{
		node tmp=s2.query(1,1,n,b[i].l,b[i].r);
		ans=max(ans,tmp.v-b[i].v);
	}
	for(int i=1;i<=q;++i)
		dp[i]=-INF;
	for(int i=1;i<=q;++i)
	{
		dp[i]=s0.query(1,1,n,b[i].l,b[i].r)-b[i].v;
		dp[i]=max(dp[i],s1.query(1,1,n,b[i].l-1,b[i].r)-b[i].v);
		s1.update(1,1,n,b[i].r,dp[i]);
	}
	for(int i=1;i<=q;++i)
		DP[b[i].r]=max(DP[b[i].r],dp[i]);
	s2.build(1,1,n);
	for(int i=1;i<=n;++i)
		s2.update(1,1,n,i,DP[i],v2[i]);
	for(int i=1;i<=q;++i)
	{
		node tmp=s2.query(1,1,n,b[i].l-1,b[i].r);
		ans=max(ans,tmp.v-b[i].v);
	}
	write(ans);
	return 0;
}