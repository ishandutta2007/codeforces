// Problem: C. Optimal Insertion
// Contest: Codeforces - Codeforces Round #751 (Div. 1)
// URL: https://codeforces.com/contest/1601/problem/C
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <assert.h>
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
//#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[2*n+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}
#define mgs int fa[1<<22],sz[1<<22];\
inline int f(int x){return x==fa[x]?x:fa[x]=f(fa[x]);}\
inline int u(int x,int y)\
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
int a[1000005],b[1000005],tmp[2000005],q[2000005],p[2000005];
struct GodL{
	int minn[8000005],addv[8000005];
	void build(int o,int l,int r)
	{
		minn[o]=0;addv[o]=0;;
		if(l==r)return ;
		int m = l + r>>1;
		build(o<<1,l,m);
		build(o<<1|1,m+1,r);
	}
	inline void pushdown(int o)
	{
		minn[o<<1]+=addv[o];
		minn[o<<1|1]+=addv[o];
		addv[o<<1]+=addv[o];
		addv[o<<1|1]+=addv[o];
		addv[o]=0;
	}
	void add(int o,int l,int r,int L,int R,int v)
	{
		if(L<=l&&r<=R)
		{
			addv[o]+=v;
			minn[o]+=v;
			return;
		}
		pushdown(o);
		int m=l+r>>1;
		if(L<=m)add(o<<1,l,m,L,R,v);
		if(m<R)add(o<<1|1,m+1,r,L,R,v);
		minn[o]=min(minn[o<<1],minn[o<<1|1]);
	}
	int q(){return minn[1];}
}t;
signed main()
{
	int T=read();
	rg(T)int n=read(),m=read();
	rg(n)a[i]=read();gr
	rg(m)b[i]=read();gr
	std::sort(b+1,b+1+m);
	rg(n)tmp[i]=a[i];gr
	rg(m)tmp[i+n]=b[i];gr
	std::sort(tmp+1,tmp+n+m+1);
	int l=std::unique(tmp+1,tmp+1+n+m)-tmp-1;
	rg(n)a[i]=std::lower_bound(tmp+1,tmp+l+1,a[i])-tmp;gr
	rg(m)b[i]=std::lower_bound(tmp+1,tmp+l+1,b[i])-tmp;gr
	long long ans=1ll*n*(n-1)/2;
	rg(n)
	int p=a[i];
	while(p)ans-=q[p],p-=p&-p;
	p=a[i];
	while(p<=l)q[p]++,p+=p&-p;
//	odl(i);fflush(stdout);
	gr
	
	//odl(ans);	
	rg(n)p[i]=i;gr
	std::sort(p+1,p+1+n,[&](int x,int y){return a[x]<a[y];});
	int c1=1,c2=1;
	t.build(1,1,n+1);
	rg(n)t.add(1,1,n+1,i+1,n+1,1);gr
	rg(m)
//	if(i>1)
	{
		for(;c1<=n&&a[p[c1]]<=b[i];)
			t.add(1,1,n+1,p[c1]+1,n+1,-1),c1++;
		for(;c2<=n&&a[p[c2]]<b[i];)
			t.add(1,1,n+1,1,p[c2],1),c2++;
		ans+=t.q();
		//remove b[i]
	}
	gr
	oldl(ans);
	memset(q,0,sizeof(int)*(n+m+1));
	gr
	return 0;
}