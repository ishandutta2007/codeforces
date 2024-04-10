#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<random>
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
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
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

const int N=5e5+5;
int n,dep[N],nm[N],siz[N],dfn[N],low[N],id[N],F[N],cnt,ans;

struct edge
{
	int u,v,w;
}a[N];

struct Edge
{
	int v,ne;
}e[N*2];
int head[N],tot;

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}

void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;siz[u]=1;
	dfn[u]=++cnt;id[cnt]=u;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);siz[u]+=siz[v];
	}
	low[u]=cnt;
}

struct Seg
{
	int val[N<<2];
	void build(int x,int l,int r)
	{
		if(!val[x])
			return;
		val[x]=0;
		if(l==r) return;
		build(lc,l,mid);
		build(rc,mid+1,r);
	}
	void update(int x,int l,int r,int p,int v)
	{
		if(l==r)
		{
			val[x]+=v;
			return;
		}
		if(p<=mid) update(lc,l,mid,p,v);
		else update(rc,mid+1,r,p,v);
		val[x]=val[lc]+val[rc];
	}
	void work(int x,int l,int r,int L,int R,int p)
	{
		if(!val[x])
			return;
		if(l==r)
		{
			val[x]=0;F[id[l]]=p;
			return;
		}
		if(L<=mid) work(lc,l,mid,L,R,p);
		if(mid+1<=R) work(rc,mid+1,r,L,R,p);
		val[x]=val[lc]+val[rc];
	}
	int query(int x,int l,int r,int L,int R)
	{
		if(!val[x])
			return 0;
		if(l==r)
		{
			int tmp=val[x];
			val[x]=0;return tmp;
		}
		int res=0;
		if(L<=mid) res+=query(lc,l,mid,L,R);
		if(mid+1<=R) res+=query(rc,mid+1,r,L,R);
		val[x]=val[lc]+val[rc];return res;
	}
}s1,s2;

vector<int> hv[N];

bool cmp(int x,int y)
{
	return dep[x]>dep[y];
}

signed main()
{
	n=read();
	for(int i=1;i<n;++i)
	{
		a[i].u=read();
		a[i].v=read();
		a[i].w=read();
		add(a[i].u,a[i].v);
		add(a[i].v,a[i].u);
	}
	dfs(1,0);
	for(int i=1;i<n;++i)
	{
		if(dep[a[i].u]<dep[a[i].v])
			swap(a[i].u,a[i].v);
		hv[a[i].w].push_back(a[i].u);
	}
	for(int i=1;i<=n;++i)
		if(hv[i].size())
		{
			sort(hv[i].begin(),hv[i].end(),cmp);
			hv[i].push_back(1);
			s1.build(1,1,n);s2.build(1,1,n);
			for(int j=0;j<hv[i].size();++j)
			{
				nm[hv[i][j]]=siz[hv[i][j]]-s2.query(1,1,n,dfn[hv[i][j]],low[hv[i][j]]);
				s1.work(1,1,n,dfn[hv[i][j]],low[hv[i][j]],hv[i][j]);s1.update(1,1,n,dfn[hv[i][j]],1);
				s2.update(1,1,n,dfn[hv[i][j]],siz[hv[i][j]]);
			}
			for(int j=0;j<hv[i].size();++j)
				ans+=nm[hv[i][j]]*nm[F[hv[i][j]]];
		}
	write(ans);
	return 0;
}