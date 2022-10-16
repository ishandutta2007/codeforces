// Problem: D. Excellent Arrays
// Contest: Codeforces - Educational Codeforces Round 111 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1550/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[n*2+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}
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
const int mod=1000000007;
int fac[200005],inv[200005];
inline int C(int n,int m)
{
//printf("C %lld %lld\n",n,m);
	if(n<m)return 0;
	if(n==m||m==0)return 1;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main()
{
	int T=read();fac[0]=inv[1]=1;
	int n=200001;
	rg(n)fac[i]=i*fac[i-1]%mod;gr
	rg(n)if(i>1)inv[i]=inv[mod%i]*(mod-mod/i)%mod;gr
	rg(n)if(i>1)inv[i]=inv[i]*inv[i-1]%mod;gr
	rg(T)int n=read(),l=read(),r=read();
	if(n&1)
	{
		int ans=0;
		int L=1-l,R=r-n;
		int cc=C(n,n>>1);
		ans+=min(L,R)*cc%mod*2%mod;
//		odl(ans);
//		oldp(L,R);
		for(int d=min(L,R)+1;d<=min(r-1,n-l);d++)
		{
			int secl=r-d,secr=l+d;
			secl=min(secl,n),secr=max(secr,1);
			secl=max(secl,0),secr=min(secr,n+1);int ll=secl,lr=n-secr+1,LL=n>>1;
			if(ll<LL||lr<LL||ll+lr<n)break;
//			oldp(secl,secr);
			ans+=C(secl-secr+1,(n>>1)-(secr-1));
			ans%=mod;
//			oldl(ans);
			ans+=C(secl-secr+1,(n+1>>1)-(secr-1));
			ans%=mod;
//			oldl(ans);
		}
		oldl(ans);
	}
	else
	{
		int ans=0;
		int L=1-l,R=r-n;
		int cc=C(n,n>>1);
		ans+=min(L,R)*cc%mod;
//		odl(ans);
//		oldp(L,R);
		for(int d=min(L,R)+1;d<=min(r-1,n-l);d++)
		{
			int secl=r-d,secr=l+d;
			secl=min(secl,n),secr=max(secr,1);
			secl=max(secl,0),secr=min(secr,n+1);
			int ll=secl,lr=n-secr+1,LL=n>>1;
			if(ll<LL||lr<LL)break;
//			oldp(secl,secr);
			ans+=C(secl-secr+1,(n>>1)-(secr-1));
			ans%=mod;
		}
		oldl(ans);
	}gr
	return 0;
}