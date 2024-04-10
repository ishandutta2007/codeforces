// Problem: E. Purple Crayon
// Contest: Codeforces - Codeforces Global Round 18
// URL: https://codeforces.com/contest/1615/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//  - /

/*
+
++
+++
++++
+++++
++++++
+++++++
++++++++
+++++++++
++++++++++
+++++++++++
++++++++++++
+++++++++++++
++++++++++++++
+++++++++++++++
++++++++++++++++
+++++++++++++++++
++++++++++++++++++
+ +++++++++++++++++
+  ++++++++++++++ ++
+   +++++++++++++  ++
+    ++++++++++++   ++
+     +++++++++++    ++
+      ++++++++++     ++
+       +++++++++      ++
+        ++++++++       ++
+         +++++++++++++++++
+          +++++++++++++++++
+           ++++++++++++++
+            +++++++++++
+             ++++++++
+              +++++
+               ++
+               +
+               +
+              ++
+             +++
+            ++++
+           +++++
+           +++++
+           +++++
+           +++++
+     +     +++++
+    +++    +++++
+   ++ ++   +++++
+  ++   ++  +++++
+ ++  +  ++ +++++
+++  +++  +++++++
++  ++ ++  ++++++
 
 
 ++++++++      +++++++++++     +++      +++        ++++++++        ++++++++
+++++++++     +++++++++++++    +++      +++       +++    +++      +++    +++
+++          +++   +++   +++   +++      +++      +++   ++++++    +++      +++
+++          +++   +++   +++   +++      +++      +++ +++  +++           +++
+++          +++   +++   +++   +++ ++   +++ ++   ++++++   +++         +++
+++++++++    +++   +++   +++   +++ ++   +++ ++    +++    +++        +++    ++
 ++++++++    +++   +++   +++   +++++    +++++      ++++++++       +++++++++++
*/
#ifndef ONLINE_JUDGE
#define DEBUG
#endif
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <assert.h>
#include <set>
#define od(x) printf("%d",x)
#define odb(x) printf("%d ",x)
#define odl(x) printf("%d\n",x)
#define odp(x,y) printf("%d %d\n",x,y)
#define ol(x) puts("")
#define old(x) printf("%lld",x)
#define oldb(x) printf("%lld ",x)
#define oldl(x) printf("%lld\n",x)
#define oldp(x,y) printf("%lld %lld\n",x,y)
#define rg(x) for(int i=1;i<=(x);i++){
#define rg_(i,x) for(int i=1;i<=(x);i++){
#define fe(u) for(int i=h[u];i;i=e[i].nxt){int v=e[i].v;
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
template<typename T>
void print(T x){}
template<>
void print<int>(int x){od(x);}
template<>
void print<const int>(const int x){od(x);}
template<>
void print<long long>(long long x){old(x);}
template<>
void print<const long long>(const long long x){old(x);}
template<>
void print<char>(char x){putchar(x);}
template<>
void print<const char>(const char x){putchar(x);}
template<>
void print<double>(double x){printf("%.12lf",x);}
template<typename T,typename... qwq>
void print(T x,qwq ...args)
{
	print(x);
	print(args...);
}
#ifdef DEBUG
template<typename T>
void debug(T x){}
template<>
void debug<int>(int x){od(x);}
template<>
void debug<const int>(const int x){od(x);}
template<>
void debug<long long>(long long x){old(x);}
template<>
void debug<const long long>(const long long x){old(x);}
template<>
void debug<char>(char x){putchar(x);}
template<>
void debug<const char>(const char x){putchar(x);}
template<>
void debug<double>(double x){printf("%.12lf",x);}
template<typename T,typename... qwq>
void debug(T x,qwq ...args)
{
	debug(x);
	debug(args...);
}
#define dflush fflush
#else
#define dflush(...) 0
template<typename T,typename... qwq>
void debug(T x,qwq ...args)
{
	
}
#endif
#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[2*n+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}
#define mgs int fa[1<<22],sz[1<<22];\
inline int f(int x){return x==fa[x]?x:fa[x]=f(fa[x]);}\
inline int uf(int x,int y)\
{\
    int fx=f(x),fy=f(y);\
    if(fx==fy)return 0;\
    if(sz[fx]>sz[fy])fx^=fy^=fx^=fy;\
    fa[fx]=fy,sz[fy]+=sz[fx];\
    return 1;\
}
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=num*10+(c^48),c=getchar();
    return num*f;
}
inline int re1d()
{
    char c=getchar();
    while(c<48||c>49)c=getchar();
    return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
newe(1000005);
arr deg;
int ans=0;
int n=read(),k=read();
int f(int t)
{
	return t*t-n*t;
}
arr dfn,dep,l,r,id;
int F[200005][20];
int cc=0;
void dfs(int u,int fa)
{
	dfn[u]=++cc;dep[u]=dep[fa]+1;
	F[u][0]=fa;
	// for(int i=1;(1<<i)<=dep[u];i++)F[u][i]=F[F[u][i-1]][i-1];
	id[cc]=u;
	l[u]=cc;
	fe(u)
	if(v==fa)continue;
	deg[u]++;
	dfs(v,u);
	gr
	if(deg[u]==0)ans++;
	r[u]=cc;
}
struct pair{
	int p,v;
};
struct SegT
{
	int maxn[2000005],tag[2000005],pos[2000005];
	void pushdown(int o)
	{
		int&t=tag[o];
		maxn[o<<1]+=t;
		maxn[o<<1|1]+=t;
		tag[o<<1]+=t;
		tag[o<<1|1]+=t;
		t=0;
	}
	void build(int o,int l,int r)
	{
		if(l==r)
		{
			pos[o]=l;
			maxn[o]=(deg[id[l]]==0?dep[id[l]]:-0x3f3f3f3f3f3f3f3fll);
			// odl(maxn[o]);
			return;
		}
		int m=l+r>>1;
		build(o<<1,l,m);
		build(o<<1|1,m+1,r);
		maxn[o]=max(maxn[o<<1],maxn[o<<1|1]);
		pos[o]=(maxn[o]==maxn[o<<1]?pos[o<<1]:pos[o<<1|1]);
	}
	void add(int o,int l,int r,int L,int R,int v)
	{
		// for(int i=L;i<=R;i++)minn[i]+=v;
		if(L<=l&&r<=R)
		{
			maxn[o]+=v;
			tag[o]+=v;
			return;
		}
		int m=l+r>>1;
		pushdown(o);
		if(L<=m)add(o<<1,l,m,L,R,v);
		if(m<R)add(o<<1|1,m+1,r,L,R,v);
		maxn[o]=max(maxn[o<<1],maxn[o<<1|1]);
		pos[o]=(maxn[o]==maxn[o<<1]?pos[o<<1]:pos[o<<1|1]);
	}
	pair que(int o,int l,int r,int L,int R)
	{
		// int res=minn[L];
		// for(int i=L;i<=R;i++)res=min(res,minn[i]);
		// return res;
		if(L<=l&&r<=R)
		{
			return (pair){pos[o],maxn[o]};
		}
		int m=l+r>>1,res=-0x3f3f3f3f3f3f3f3fll-1;
		pair la,ra;la.v=res,ra.v=res;
		pushdown(o);
		// if(L<=m)res=max(res,que(o<<1,l,m,L,R));
		// if(m<R)res=max(res,que(o<<1|1,m+1,r,L,R));
		if(L<=m)la=que(o<<1,l,m,L,R);
		if(m<R)ra=que(o<<1|1,m+1,r,L,R);
		if(la.v>ra.v)return la;
		return ra;
		// maxn[o]=max(maxn[o<<1],maxn[o<<1|1]);
		// pos[o]=(maxn[o]==maxn[o<<1]?pos[o<<1]:pos[o<<1|1]);
		// return res;
	}
}t;
int ka(int u,int k)
{
	for(int i=19;i>=0;i--)if((k>>i)&1)u=F[u][i];
	return u;
}
signed main()
{
	rg(n-1)
	int u=read(),v=read();
	addedge(u,v,1),addedge(v,u,1);
	gr
	dfs(1,0);
	// int D=n>>1;D++;
	// int D=1;
	// odl(f(0)-f(D));
	// odl(f(1)-f(D+1));
	if(ans<=k)
	{
		if(ans<(n>>1)&&k>(n>>1))oldl(f(0)-f(n>>1));
		else oldl(f(0)-min(f(ans),f(k)));
	}
	else
	{
		t.build(1,1,n);
		int A=0,K=k,R=-1e18;;
		while(k--)
		{
			pair x=t.que(1,1,n,1,n);
			int u=id[x.p],ans=x.v;A+=ans;
			// odl(u);fflush(stdout);
			while(ans--)
			{
				// odp(l[u],r[u]);fflush(stdout);
				t.add(1,1,n,l[u],r[u],-1);
				u=F[u][0];
			}
			R=max(R,-f(K)+f(min(n-A,n>>1)));
			// int U=ka(id[u],ans-1);
			// t.add(1,1,n,l[U],r[U],);
		}
		// odl(f(1)-f(2));
		// odl(f(2)-f(1));
		// odp(A,K);
		oldl(R);
	}
	return 0;
}