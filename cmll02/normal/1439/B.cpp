// Problem: B. Graph Subset Problem
// Contest: Codeforces - Codeforces Round #684 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1439/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
newe(200005);
arr d,vis,deg;
int k,n,m;
void remove(int x)
{
	if(deg[x]>=k)return;
	if(vis[x]==1)return;vis[x]=1;
	fe(x)if(!vis[v])deg[v]--,remove(v);gr
}
int B=1;
#include <unordered_map>
arr tmp;
#ifdef ONLINE_JUDGE
#include <bits/extc++.h>
__gnu_pbds::gp_hash_table<long long,int> mp;
#else 
std::unordered_map<long long,int>mp;
#endif
inline long long make_pair(long long x,long long y)
{
	if(x>y)x^=y^=x^=y;
	return x*n+y;
}
inline void Ins(long long x){mp[x]=1;}
const int MAXN = 2e5, MAXM = 4e5;
const int FULL5 = (1 << 5) - 1;
const int FULL6 = (1 << 6) - 1;

int b1[MAXN + 5][MAXN / (1 << 11) + 5], cnt_b1;
unsigned long long b2[MAXM + 5][FULL5 + 1];

void add_edge(int u, int v) {
	if (!b1[u][v >> 11]) b1[u][v >> 11] = ++cnt_b1;
	b2[b1[u][v >> 11]][(v >> 6) & FULL5] |= 1ull << (v & FULL6);
}
void clear()
{
	rg_(u,n)fe(u)
	b2[b1[u][v >> 11]][(v >> 6) & FULL5]=0;
	gr gr
	rg_(u,n)fe(u)
	b1[u][v >> 11]=0;
	gr gr
	cnt_b1=0;
}
bool have_edge(int u, int v) {
	if (!b1[u][v >> 11]) return false;
	return b2[b1[u][v >> 11]][(v >> 6) & FULL5] & (1ull << (v & FULL6));
}
int iLoveDevinwang(int u)
{
	if(deg[u]!=k)return 0;
	int cc=0;
	tmp[++cc]=u;
	fe(u)if(deg[v]>=k&&vis[v]==0)tmp[++cc]=v;gr
	// assert(cc<=deg[u]+1);
	if(cc!=deg[u]+1)return 0;
	// assert(deg[u]==k);
	rg(cc)rg_(j,i-1)if(have_edge(min(tmp[i],tmp[j]),max(tmp[i],tmp[j])));else return 0;gr gr
	return 1;
}
void printAns(int x)
{
	//TODO
	print(2,'\n');
	rg(k+1)print(tmp[i],' ');gr
	print('\n');
}
int test_remove(int x,int f=0)
{
	odl(x);
	rg(n)odp(vis[i],deg[i]);gr puts("");
	fflush(stdout);
	if(deg[x]==k)
	{
		if(iLoveDevinwang(x))
		{
			printAns(x);
			return 1;
		}
	}
	if(deg[x]>=k&&f==0)return 0;
	if(vis[x]==1)return 0;vis[x]=1;
	// odl(x);fflush(stdout);
	fe(x)if(vis[v])continue;
	deg[v]--;
	if(test_remove(v))return 1;gr
	return 0;
}

void remove1(int x)
{
	if(deg[x]>k)return;
	if(vis[x]==1)return;vis[x]=1;
	fe(x)if(!vis[v])deg[v]--,remove1(v);gr
}
int TrySolve(int x)
{
	// printf("trying %d\n",x);fflush(stdout);
	if(deg[x]>k||vis[x]!=0)return 0;
	if(deg[x]==k&&iLoveDevinwang(x))
	{
		printAns(x);
		return 1;
	}
	// if(test_remove(x,1))return 1;
	// assert(deg[x]==k);
	// remove1(x);
	fe(x)deg[v]--;gr
	vis[x]=1;
	fe(x)
	if(vis[v]==0&&deg[v]<=k&&(TrySolve(v)))return 1;
	gr
	return 0;
}
int v[105];
signed main()
{
	v[2]=v[4]=v[5]=v[7]=v[8]=1;
	int T=read();rg(T)
	n=read(),m=read();k=read();
	memset(h,0,sizeof(int)*(n+3));
	mp.clear();
	memset(vis,0,sizeof(int)*(n+3));
	memset(d,0,sizeof(int)*(n+3));cnt=1;
	rg(m)int x=read(),y=read();addedge(x,y,1);addedge(y,x,1);d[x]++,d[y]++;//Ins(make_pair(x,y));
	add_edge(min(x,y),max(x,y));
	// if(v[x]==0||0==v[y])
	// ;else
	// odp(x,y);
	gr
	// rg(n)odl(d[i]);gr
	rg(n)deg[i]=d[i];gr
	rg(n)if(!vis[i]&&deg[i]<k)remove(i);gr
	int f=0;
	rg(n)if(vis[i]==0)f++;gr
	if(f)
	{
		print('1',' ',f,'\n');
		rg(n)if(vis[i]==0)print(i,' ');gr
		print('\n');
	}
	else
	{
		if(k*(k-1ll)/2>m)puts("-1");
		else
		{	
			// rg_(u,n)fe(u)odb(v);gr puts("");gr
			// puts("");
			rg(n)deg[i]=d[i];gr
			k--;
			rg(n)vis[i]=0;gr
			rg(n)if(!vis[i]&&deg[i]<k)remove(i);gr
			// rg(n)odb(i);odp(vis[i],deg[i]);gr puts("");
			int f=0;
			rg(n)if(vis[i]==0&&deg[i]==k)if(TrySolve(i)){f++;fflush(stdout);break;}gr
			// puts("");
			// rg(n)odp(vis[i],deg[i]);gr puts("");
			// rg(n)if(vis[i]==0&&deg[i]>=k)if(TrySolve(i)){f++;fflush(stdout);break;}gr
			if(0==f)print('-','1','\n');
		}
	}
	// if(i==4971&&T==7000)return 0;
	// printf("test %d end.\n",i);
	clear();
	fflush(stdout);
	gr
	return 0;
}