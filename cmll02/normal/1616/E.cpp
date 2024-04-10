// Problem: E. Lexicographically Small Enough
// Contest: Codeforces - Good Bye 2021: 2022 is NEAR
// URL: https://codeforces.com/contest/1616/problem/E
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
char a[1000005],b[1000005];
struct SegT
{
	int maxn[800005],tag[800005];//pos[2000005];
	// int save[800005][26];
	void build(int o,int l,int r)
	{
		if(l==r)
		{
			tag[o]=l;
			// maxn[o]=(deg[id[l]]==0?dep[id[l]]:-0x3f3f3f3f3f3f3f3fll);
			// maxn[o]=dep[idfn[l]];
			// sum[o]=
			// odl(maxn[o]);
			return;
		}
		int m=l+r>>1;
		tag[o]=0;
		build(o<<1,l,m);
		build(o<<1|1,m+1,r);
		// maxn[o]=max(maxn[o<<1],maxn[o<<1|1]);
		// pos[o]=(maxn[o]==maxn[o<<1]?pos[o<<1]:pos[o<<1|1]);
	}
	void add(int o,int l,int r,int L,int R,int v)
	{
		// for(int i=L;i<=R;i++)minn[i]+=v;
		if(L<=l&&r<=R)
		{
			// maxn[o]+=v;
			tag[o]+=v;
			return;
		}
		int m=l+r>>1;
		// pushdown(o);
		if(L<=m)add(o<<1,l,m,L,R,v);
		if(m<R)add(o<<1|1,m+1,r,L,R,v);
		// maxn[o]=max(maxn[o<<1],maxn[o<<1|1]);
		// pos[o]=(maxn[o]==maxn[o<<1]?pos[o<<1]:pos[o<<1|1]);
	}
	int que(int o,int l,int r,int p)
	{
		if(l==r)return tag[o];
		int m=l+r>>1;
		if(p<=m)return tag[o]+que(o<<1,l,m,p);
		return tag[o]+que(o<<1|1,m+1,r,p);
	}
	// pair que(int o,int l,int r,int L,int R)
	// {
		// // int res=minn[L];
		// // for(int i=L;i<=R;i++)res=min(res,minn[i]);
		// // return res;
		// if(L<=l&&r<=R)
		// {
			// return (pair){pos[o],maxn[o]};
		// }
		// int m=l+r>>1,res=-0x3f3f3f3f3f3f3f3fll-1;
		// pair la,ra;la.v=res,ra.v=res;
		// pushdown(o);
		// // if(L<=m)res=max(res,que(o<<1,l,m,L,R));
		// // if(m<R)res=max(res,que(o<<1|1,m+1,r,L,R));
		// if(L<=m)la=que(o<<1,l,m,L,R);
		// if(m<R)ra=que(o<<1|1,m+1,r,L,R);
		// if(la.v>ra.v)return la;
		// return ra;
		// // maxn[o]=max(maxn[o<<1],maxn[o<<1|1]);
		// // pos[o]=(maxn[o]==maxn[o<<1]?pos[o<<1]:pos[o<<1|1]);
		// // return res;
	// }
}t;
std::set<int>ss[27];
int GET(int j,int i,int n)
{
	return *ss[j].begin();
}
int fGET(int j,int i,int n)
{
	if(ss[j].empty())return 1e18;
	int tt=GET(j,i,n);
	return t.que(1,1,n,tt)-i;
}
signed main()
{
	int T=read();rg(T)
	int n=read();
	scanf("%s%s",a+1,b+1);
	for(int i=0;i<27;i++)ss[i].clear();
	t.build(1,1,n);
	int f=0;rg(n)f|=a[i]!=b[i];gr
	// if(f==0){puts("-1");continue;}
	// puts("?");
	int sum=0,ans=1e18;;
	rg(n)a[i]-=97,b[i]-=97;gr
	// b[n]++;
	rg(n)ss[a[i]].insert(i);gr
	rg(n)
	int tq=1e18;
	for(int j=0;j<b[i];j++)tq=min(tq,fGET(j,i,n));
	ans=min(ans,tq+sum);
	if(ss[b[i]].empty())break;
	int pos=GET(b[i],i,n);
	int Pos=t.que(1,1,n,pos);
	sum+=Pos-i;
	ss[b[i]].erase(pos);
	// printf("move Pos = %d cost %d - %d\n",Pos,Pos-i,pos);fflush(stdout);
	t.add(1,1,n,1,pos,1);
	// odl(sum);
	// MODIFY(i,n);
	gr
	if(ans>1e14)puts("-1");
	else oldl(ans);
	gr
	return 0;
}