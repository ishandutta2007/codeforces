// Problem: F. RBS
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1598/problem/F
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
char s[22][400005];int sum[22],pre[22];
int g[22][800005],L[22],lst[22][800005],ok[22][800005];
bool fail[22][800005];
struct GodL
{
	int minn[800005];
	inline void build(int o,int l,int r)
	{
		minn[o]=0x3f3f3f3f;
		if(l==r)return;
		int m=l+r>>1;
		build(o<<1,l,m);
		build(o<<1|1,m+1,r);
	}
	inline int que(int o,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R)return minn[o];
		int m=l+r>>1,ans=0x3f3f3f3f;
		if(L<=m)ans=min(ans,que(o<<1,l,m,L,R));
		if(m<R)ans=min(ans,que(o<<1|1,m+1,r,L,R));
		return ans;
	}
	inline void add(int o,int l,int r,int p,int v)
	{
		if(l==r)minn[o]=v;
		else
		{
			int m=l+r>>1;
			if(p<=m)add(o<<1,l,m,p,v);
			else add(o<<1|1,m+1,r,p,v);
			minn[o]=min(minn[o<<1],minn[o<<1|1]);
		}
	}
}seg;
inline int ct(int i)
{
	int l=strlen(s[i]+1);L[i]=l;
	seg.build(1,1,l+l);
	rg_(j,l)if(s[i][j]=='(')sum[i]++;else sum[i]--;pre[i]=min(pre[i],sum[i]);g[i][l+sum[i]]++;
	seg.add(1,1,l,j,l+sum[i]);
	int k=seg.que(1,1,l,lst[i][l+sum[i]]+1,j);
	//odb(sum[i]);
	if(fail[i][l+sum[i]]==0&&k==l+sum[i])ok[i][l+sum[i]]++;//printf("%d %d\n",i,l+sum[i]);
	else fail[i][l+sum[i]]=1;
	lst[i][l+sum[i]]=j;
	gr
	//puts("");
}
int dp[1<<21],P[1<<21],valid[1<<21];
signed main()
{
	int n=read();
	rg(n)scanf("%s",s[i]+1);gr
	rg(n)ct(i);gr
	int ans=0;memset(valid,1,sizeof(valid));
	valid[0]=0;
	//odl(ok[1][7]);
	for(int S=0;S<(1<<n);S++)
	{
		rg(n)if((S>>i-1)&1)P[S]+=sum[i];gr
		if(valid[S])continue;
		rg(n)if((S>>i-1)&1)continue;
		int T=S|(1<<i-1);
		int k=P[S];
		int Y=ok[i][L[i]-k];
		ans=max(ans,dp[S]+Y);//printf("from %d to %d : %d %d\n",S,T,dp[S],dp[S]+Y);
		if(pre[i]+k>=0)dp[T]=max(dp[T],Y+dp[S]),valid[T]=0;
		gr
	}
	//for(int i=0;i<(1<<n);i++)odb(dp[i]);puts("");
	//for(int i=0;i<(1<<n);i++)odb(valid[i]);puts("");
	odl(ans);
	return 0;
}