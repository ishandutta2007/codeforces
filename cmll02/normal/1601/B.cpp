// Problem: B. Frog Traveler
// Contest: Codeforces - Codeforces Round #751 (Div. 1)
// URL: https://codeforces.com/contest/1601/problem/B
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
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}//printf("%d %d %d\n",u,v,w);}
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
int a[300005],b[300005],id[300005],st,d[300005],pre[300005],fr[300005],vis[300005],get[300005];
void print(int s,int t)
{
	if(s==t)return;
	print(pre[s],t);
	odb(fr[s]);
}
signed main()
{
	int n=read();
	rg(n)a[i]=read();gr
	rg(n)b[i]=read();gr
	std::queue<int>q;
	q.push(n);id[n]=vis[n]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		//odl(u);
		for(int i=u-a[u];i<u;i++)
		{
			//odp(u,i);
			if(i==0)
			{
				pre[0]=u;
				odl(d[u]+1);
				print(0,n);
				return 0;
			}
			if(get[i])break;
			get[i]=1;
			if(vis[i+b[i]])continue;
			if(!id[i+b[i]])
			{
				d[i+b[i]]=d[u]+1;
				fr[i+b[i]]=i;
				pre[i+b[i]]=u;
				//odp(i+b[i],d[i]);
				q.push(i+b[i]);
				vis[i+b[i]]=1;
			}
			//id[i]=1;
		}
	}
	puts("-1");
}
// newe(13000005);
// arr pre,inv;
// void build(int o,int l,int r)
// {
	// st=max(st,o);
	// if(l==r)
	// {
		// id[l]=o;
		// inv[o]=l;
		// return;
	// }
	// int m=l+r>>1;
	// build(o<<1,l,m);
	// build(o<<1|1,m+1,r);
	// addedge(o,o<<1,0);
	// addedge(o,o<<1|1,0);
// }
// void add(int from,int o,int l,int r,int L,int R)
// {
	// if(L<=l&&r<=R)
	// {
		// addedge(from,o,1);
		// return;
	// }
	// int m=l+r>>1;
	// if(L<=m)add(from,o<<1,l,m,L,R);
	// if(m<R)add(from,o<<1|1,m+1,r,L,R);
// }
// int dis[13000005];
// void print(int s,int t)
// {
	// if(s==t)return;
	// print(s,pre[t]);
	// if(inv[t])odb(inv[t]);
// }
// void bfs(int s,int t)
// {
	// std::deque<int>q;
	// q.push_front(s);
	// memset(dis,0x3f,sizeof(dis));
	// dis[s]=0;
	// while(!q.empty())
	// {
		// int u=q.front();q.pop_front();
		// if(u==t)
		// {
			// odl(dis[t]);
			// print(s,t);
			// odb(0);
			// return;
		// }
		// fe(u)
		// if(e[i].w==0&&dis[v]>1000000000)
		// {
			// dis[v]=dis[u];
			// q.push_front(v);
			// pre[v]=u;
		// }
		// gr
		// fe(u)
		// if(e[i].w==1&&dis[v]>1000000000)
		// {
			// dis[v]=dis[u]+1;
			// q.push_back(v);
			// pre[v]=u;
		// }
		// gr
	// }
	// puts("-1");
// }
// signed main()
// {
	// int n=read();
	// rg(n)a[i]=read();gr
	// rg(n)b[i]=read();gr
	// build(1,0,n);
	// rg(n)addedge(id[i],st+i+b[i],0);gr
	// rg(n)add(st+i,1,0,n,i-a[i],i);gr
	// bfs(st+n,id[0]);
	// return 0;
// }