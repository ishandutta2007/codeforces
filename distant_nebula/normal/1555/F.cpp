#include <cstdio>
#include <algorithm>
#include <assert.h>
const int N=1000005;
int n, q, pa[N];
inline int findfa(int x)
{ return x==pa[x]?x:pa[x]=findfa(pa[x]); }
#define ls ch[u][0]
#define rs ch[u][1]
namespace LCT{
	int ch[N][2], tag[N], is[N], sum[N], sz[N], w[N], rv[N], fa[N], rev[N];
	inline int gid(int u) { return ch[fa[u]][1]==u; }
	inline int isroot(int u) { return ch[fa[u]][0]!=u&&ch[fa[u]][1]!=u; }
	inline void upt(int u)
	{
		sz[u]=sz[ls]+sz[rs]+(u>n);
		sum[u]=(tag[ls]?sz[ls]:sum[ls])+(tag[rs]?sz[rs]:sum[rs])+is[u];
		w[u]=w[ls]^w[rs]^rv[u];
	}
	inline void rotate(int x)
	{
		int y=fa[x], z=fa[y], id=gid(x);
		if(x==z) exit(114);
		if(!isroot(y)) ch[z][gid(y)]=x;
		fa[x]=z, fa[y]=x;
		ch[y][id]=ch[x][id^1], ch[x][id^1]=y;
		if(ch[y][id]) fa[ch[y][id]]=y;
		upt(y), upt(x);
	}
	inline void pushdown(int u)
	{
		if(tag[u])
		{
			is[u]=u>n;
			sum[u]=sz[u];
			tag[ls]=tag[rs]=1;
//			printf("is %d %d %d %d %d\n", u, sz[u], ls, rs, sum[u]);
			tag[u]=0;
		}
		if(rev[u])
		{
			std::swap(ls, rs);
			rev[ls]^=1, rev[rs]^=1;
			rev[u]=0;
		}
	}
	inline void pushup(int u)
	{
		if(!isroot(u)) pushup(fa[u]);
		pushdown(u);
	}
	inline void splay(int u)
	{
		pushup(u);
		for(int f; (f=fa[u]), !isroot(u); rotate(u)) if(!isroot(f))
		rotate(gid(f)==gid(u)?f:u);
	}
	inline void access(int u)
	{
		for(int p=0; u; p=u, u=fa[u])
		{
//			 printf("u %d %d\n", u, sum[u]);
			splay(u);
			rs=p;
			upt(u);
		}
	}
	inline void mroot(int x) { access(x), splay(x); rev[x]^=1; }
	inline void split(int x, int y) { mroot(x), access(y), splay(y); }
	inline void link(int x, int y)
	{
//		printf("link %d %d\n", x, y);
		split(x, y);
		fa[x]=y;
	}
}
using namespace LCT;
int main()
{
	scanf("%d%d", &n, &q);
//	std::fill(sz+1, sz+n+1, 1);
	std::iota(pa, pa+n+1, 0);
	for(int i=1, x, y, v; i<=q; ++i)
	{
		scanf("%d%d%d", &x, &y, &v);
		if(findfa(x)==findfa(y))
		{
			split(x, y);
//			printf("fa %d %d %d\n", sum[y], w[y], v);
//			for(int u=1; u<=n+i; ++u) printf("ch %d %d %d %d %d %d\n", u, ls, rs, rv[u], w[u], sum[u]);
			if(sum[y]||(w[y]^v)!=1) { puts("NO"); }
			else { tag[y]=1; puts("YES"); }
		}
		else
		{
			pa[findfa(x)]=findfa(y);
			link(x, i+n), link(y, i+n);
			access(i+n);
			splay(i+n);
			rv[i+n]=v;
			sz[i+n]=1;
			upt(i+n);
			puts("YES");
		}
	}
	return 0;
}