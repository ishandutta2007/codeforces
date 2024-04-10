// Problem: F2. Korney Korneevich and XOR (hard version)
// Contest: Codeforces - Codeforces Round #750 (Div. 2)
// URL: https://codeforces.com/contest/1582/problem/F2
// Memory Limit: 512 MB
// Time Limit: 1500 ms
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
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
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
//#define int long long
#define newe(n) struct Edge{int w,nxt;}e[5005*8192];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int w){e[cnt]=(Edge){w,h[u]};h[u]=cnt++;}
#define mgs int fa[1<<22],sz[1<<22],t[1<<22];\
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
const int Q=5001;
bool a[Q][8192];
int tag[Q][8192];
int sz[Q];
bool hav[Q][8192];
signed main()
{
	int n=read(),D=0;
	rrg(Q)a[i][0]=1,tag[i][sz[i]=1]=i,hav[i][i]=hav[i][0]=1;
	rg(n)int x=read();
	if(x==0)continue;
	rg_(k,sz[x])a[x][tag[x][k]]=1;//odp(x,tag[x][k]);
	for(int j=x+1;j<Q;j++)
	{
		if(!hav[j][tag[x][k]^j])
		{
			hav[j][tag[x][k]^j]=1;
			tag[j][++sz[j]]=tag[x][k]^j;
			//printf("%d has tag %d\n",j,tag[x][k]^j);
		}
		else 
		{
			//printf("- %d has tag %d\n",j,tag[x][k]^j);
			break;
		}
	}
	for(int j=x+1;j<Q;j++)if(!a[j][tag[x][k]])
	{
		if(!hav[j][tag[x][k]^j])tag[j][++sz[j]]=j^tag[x][k],hav[j][tag[x][k]^j]=1;
		hav[j][tag[x][k]]=1;a[j][tag[x][k]]=1;//printf("%d %d get 1;\n",j,tag[x][k]);
	}else break;
	gr
	sz[x]=0;
	// for(int j=h[x-1];j;j=e[i].nxt)
	// {
		// if(a[x-1][j]==0)continue;
		// int u=j^x;
		// for(int I=x;I<512;I++)
		// {
// //			u^=I;//,a[i][j^u]|=a[j]
			// if(a[I][u])break;
			// a[I][u]=1;
		// }
	// }
	gr
	
	//tag[i] biao shi i cong na li kai shi you
	
	
	int ans=0;
	rrg(8192)if(a[(Q-1)][i])ans++;
	odl(ans);
	rrg(8192)if(a[(Q-1)][i])odb(i);
	puts("");
	return 0;
}