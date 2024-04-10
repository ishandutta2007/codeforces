//  /
 
/*
   ###
 #######
#########   #######           ##########################################
#########   #######  ####     ##########################################
 #######
   #####
    
        ###
      #######
     #########   ##############            ####   ########################
     #########   ##############   ####     ####   ########################
      #######
        ###
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
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
//#define int long long
#define newe(n) struct Edge{int v,nxt;}e[n*2+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v){e[cnt]=(Edge){v,h[u]};h[u]=cnt++;}
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
newe(1000005);
arr sz,ans;
int zx;
int n;
int lim;
void dfs(int u,int fa)
{
    sz[u]=1;int q=0;
    for(int i=h[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v==fa)continue;
        dfs(v,u),sz[u]+=sz[v];
        if(sz[v]>lim)q=1;
    }
    if(n-sz[u]>lim)q=1;
    if(q==0)
    {
        if(zx)zx=-1;
        else zx=u;
    }
}
void dfs3(int u,int fa,int x)
{
    if (n-sz[u]-x<=lim)ans[u]=1;
    for(int i=h[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v!=fa)
        dfs3(v,u,x);
    }
}
signed main()
{
#ifndef explpl
#endif
    int T=1;
    rg(T)n=read();memset(h,0,sizeof(int)*(n+3));cnt=1;lim=n>>1;zx=0;
    rg(n-1)int x=read(),y=read();addedge(x,y),addedge(y,x);gr
    memset(ans,0,sizeof(int)*(n+3));
    dfs(1,0);int maxn=0,max2=0;
    if(zx==-1){rg(n)printf("1 ");gr puts("");continue;}
    int t=zx;zx=0;
    dfs(t,0);
    for(int i=h[zx];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(sz[v]>sz[maxn])max2=maxn,maxn=v;
        else if(sz[v]>sz[max2])max2=v;
    }
    ans[zx]=1;
    for(int i=h[zx];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v==maxn)dfs3(v,zx,sz[max2]);
        else dfs3(v,zx,sz[maxn]);
    }
    rg(n)odb(ans[i]);gr
    puts("");gr
    return 0;
}