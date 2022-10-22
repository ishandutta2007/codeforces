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
#define lowbit(x) (x&(-x))
#define mp(x,y) make_pair(x,y)
#define lc (x<<1)
#define rc (x<<1|1)
#define fi first
#define se second
#define mid ((l+r)>>1)
#define fan(x) (((x-1)^1)+1)
#define max Max
#define min Min
#define abs Abs

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
template<typename T,typename TT>inline T Min(T a,TT b){return a>b?b:a;}
template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}

const int N=4e5+5;
int n,a[N],b[N],dfn[N],low[N],ans[N],cnt;

vector<int> val,lcc,rcc;

struct Edge
{
	int v,ne;
}e[N*2];
int head[N],tot;

struct Line
{
	int k,b;
}c[N];

inline int f(int id,int v);
inline void add(int u,int v);
void dfs1(int u,int fa);
void dfs2(int u,int fa);
void build(int x,int l,int r);
void update1(int x,int l,int r,int p,int v);
int query1(int x,int l,int r,int L,int R,int v);
void update2(int x,int l,int r,int v);
int query2(int x,int l,int r,int v);

signed main()
{
	//freopen("yangli.in","r",stdin);
	//freopen("std.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i) b[i]=read();
	for(int i=1;i<=n-1;++i)
	{
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	c[0].b=1e18;
	dfs1(1,0);
	cnt=0;build(1,1,n);
	for(int i=0;i<=cnt;++i)
	{
		val.push_back(0);
		lcc.push_back(0);
		rcc.push_back(0);
	}
	dfs2(1,0);
	for(int i=1;i<=n;++i)
		printf("%lld ",ans[i]);
	return 0;
}

inline int f(int id,int v)
{
	return c[id].k*v+c[id].b;
}

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}

void dfs1(int u,int fa)
{
	dfn[u]=++cnt;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs1(v,u);
	}
	low[u]=cnt;
}

void dfs2(int u,int fa)
{
	int fl=1;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs2(v,u);fl=0;
	}
	if(fl) ans[u]=0;
	else ans[u]=query1(1,1,n,dfn[u]+1,low[u],a[u]+100001);
	c[u]=(Line){b[u],ans[u]};
	update1(1,1,n,dfn[u],u);
}

void build(int x,int l,int r)
{
	cnt=max(cnt,x);
	if(l==r) return;
	build(lc,l,mid);
	build(rc,mid+1,r);
}

void update1(int x,int l,int r,int p,int v)
{
	update2(x,1,200001,v);
	if(l==r) return;
	if(p<=mid) update1(lc,l,mid,p,v);
	else update1(rc,mid+1,r,p,v);
}

int query1(int x,int l,int r,int L,int R,int v)
{
	if(L<=l&&r<=R) return query2(x,1,200001,v);
	int res=1e18;
	if(L<=mid) res=min(res,query1(lc,l,mid,L,R,v));
	if(mid+1<=R) res=min(res,query1(rc,mid+1,r,L,R,v));
	return res;
}

void update2(int x,int l,int r,int v)
{
	if(l==r)
	{
		if(f(v,l-100001)<f(val[x],l-100001))
			val[x]=v;
		return;
	}
	if(c[v].k>c[val[x]].k)
	{
		if(f(v,mid-100001)<f(val[x],mid-100001))
		{
			if(!rcc[x])
			{
				rcc[x]=++cnt;
				val.push_back(0);
				lcc.push_back(0);
				rcc.push_back(0);
			}
			update2(rcc[x],mid+1,r,val[x]),val[x]=v;
		}
		else
		{
			if(!lcc[x])
			{
				lcc[x]=++cnt;
				val.push_back(0);
				lcc.push_back(0);
				rcc.push_back(0);
			}
			update2(lcc[x],l,mid,v);
		}
	}
	if(c[v].k<c[val[x]].k)
	{
		if(f(v,mid-100001)<f(val[x],mid-100001))
		{
			if(!lcc[x])
			{
				lcc[x]=++cnt;
				val.push_back(0);
				lcc.push_back(0);
				rcc.push_back(0);
			}
			update2(lcc[x],l,mid,val[x]);val[x]=v;
		}
		else
		{
			if(!rcc[x])
			{
				rcc[x]=++cnt;
				val.push_back(0);
				lcc.push_back(0);
				rcc.push_back(0);
			}
			update2(rcc[x],mid+1,r,v);
		}
	}
	if(c[v].k==c[val[x]].k)
	{
		if(f(v,mid-100001)<f(val[x],mid-100001))
			val[x]=v;
		return;
	}
}

int query2(int x,int l,int r,int v)
{
	if(x==0) return 1e18;
	int res=f(val[x],v-100001);
	if(l==r) return res;
	if(v<=mid) return min(res,query2(lcc[x],l,mid,v));
	else return min(res,query2(rcc[x],mid+1,r,v));
}