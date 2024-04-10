// Problem: F. Armor and Weapons
// Contest: Codeforces - Educational Codeforces Round 117 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1612/problem/F
// Memory Limit: 512 MB
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
// #define DEBUG
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
//#define int long long
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
int a[200005],b[200005],dp[200005],g[200005];
const int MAXN = 2e5, MAXM = 4e5;
const int FULL5 = (1 << 5) - 1;
const int FULL6 = (1 << 6) - 1;
 
int b1[MAXN + 5][MAXN / (1 << 11) + 5], cnt_b1;
unsigned long long b2[MAXM + 5][FULL5 + 1];
 
void add_edge(int u, int v) {
	if (!b1[u][v >> 11]) b1[u][v >> 11] = ++cnt_b1;
	b2[b1[u][v >> 11]][(v >> 6) & FULL5] |= 1ull << (v & FULL6);
}
bool have_edge(int u, int v) {
	if (!b1[u][v >> 11]) return false;
	return b2[b1[u][v >> 11]][(v >> 6) & FULL5] & (1ull << (v & FULL6));
}
signed main()
{
	int n=read(),m=read();
	int k=read();rg(k)a[i]=read(),b[i]=read();gr
	if(n>m)
	{
		n^=m^=n^=m;
		rg(k)a[i]^=b[i]^=a[i]^=b[i];gr
	}
	rg(k)add_edge(a[i],b[i]);gr
	memset(dp,0,sizeof dp);
	dp[1]=1;
	// rg(n)rg_(j,m)odb(have_edge(i,j));gr puts("");gr
	rg(214514)
	// memset(g,0,sizeof dp);
	rg(n)g[i]=0;gr
	// memset()
	rg_(j,n)
	if(dp[j]==0)continue;
	//g[i+dp[i]+have_edge(i,dp[i])]=max(g[i+dp[i]+have_edge(i,dp[i])],dp[i]+qwq);
	g[j]=max(g[j],min(m,dp[j]+j+have_edge(j,dp[j])));
	g[min(n,dp[j]+j+have_edge(j,dp[j]))]=max(g[min(n,dp[j]+j+have_edge(j,dp[j]))],dp[j]);
	gr
	// rg(n)odb(g[i]);gr puts("");
	if(g[n]==m)return odl(i),0;
	// memcpy(dp,g,sizeof dp);
	rg(n)dp[i]=g[i];gr
	gr
	return 0;
}