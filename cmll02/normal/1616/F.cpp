// Problem: H. Keep XOR Low
// Contest: Codeforces - Good Bye 2021: 2022 is NEAR
// URL: https://codeforces.com/contest/1616/problem/H
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
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
struct bitset{
	int s[298];
	void reset()
	{
		memset(s,0,sizeof(s));
	}
	bitset(){reset();}
	void operator^=(const bitset&b)
	{
		for(int i=0;i<=288;i++)s[i]=(s[i]-b.s[i]+3)%3;
	}
	void set(int x){s[x]=1;}
};
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
inline void swap(int &a,int &b)
{
	int t=a;a=b,b=t;
}
#include <bitset>
struct liner_base{
	bitset s[298];
	int ins(bitset &x)
	{
		// return 1;
		for(int i=288;i>=0;i--)
		{
			if(x.s[i]==0)
			{
				if(s[i].s[i]==0)
				{
					s[i]=x;
					return 1;
				}
				x^=s[i];
			}
		}
		return 0;
	}
	void clear()
	{
		for(int i=0;i<=288;i++)s[i].reset();
	}
}base;
int a[64*64*64/6+129][257];
int G[65][65];
int x[64*64*64/6+129],y[64*64*64/6+129],z[64*64*64/6+129],W[64*64*64/6+129],ans[266];
int X[64*64*64/6+129],Y[64*64*64/6+129],Z[64*64*64/6+129],WW[64*64*64/6+129];
#include <time.h>
int main()
{
	srand(time(0));
	int T=read();rg(T)
#define ms(x)	memset(x,0,sizeof(x));
ms(x)
ms(y)
ms(z)
ms(W)
ms(ans)
ms(X)
ms(Y)
ms(Z)
ms(WW)
	int n=read(),s=read(),N=s,che=0;
	base.clear();
	memset(G,-1,sizeof(G));
	memset(a,0,sizeof(a));
	int m=0;
	rg(s)
	int u=read(),v=read(),w=read();if(w==3)w=0;
	if(w>=0)
	{
		bitset s;
		s.set(i-1);
		if(base.ins(s)){
		a[m][i-1]=1;
		a[m][N]=w;
		x[m]=i-1;
		y[m]=-1;
		z[m]=-1;
		W[m]=w;
		m++;}else
		{
			X[che]=i-1;
			Y[che]=-1;
			Z[che]=-1;
			WW[che]=w;
			che++;
		}
	}
	G[u][v]=G[v][u]=i-1;
	gr
	rg(n)rg_(j,i-1)rg_(k,j-1)
	if(G[i][j]>=0&&G[j][k]>=0&&G[i][k]>=0)
	{
		bitset s;
		s.set(G[i][j]);
		s.set(G[i][k]);
		s.set(G[k][j]);
		if(base.ins(s)){
		a[m][G[i][j]]=1;
		a[m][G[i][k]]=1;
		a[m][G[k][j]]=1;
		x[m]=G[i][j];
		y[m]=G[i][k];
		z[m]=G[j][k];
		W[m]=0;
		m++;}else
		{
			X[che]=G[i][j];
		Y[che]=G[i][k];
		Z[che]=G[j][k];
		WW[che]=0;
		che++;
		}
	}
	gr gr gr
	for(int i=1;i<m;i++)
	{
		if(y[i]==-1)continue;
		int d=rand()%(i+1);
		if(y[d]==-1)continue;
		if(d==i)continue;
		for(int j=0;j<=N;j++)
			swap(a[d][j],a[i][j]);
		swap(x[i],x[d]);
		swap(y[i],y[d]);
		swap(z[i],z[d]);
		swap(W[i],W[d]);
	}
	// int bb=m;
	m=min(m,1024);
	// for(int i=0;i<m;i++)
	// {
		// for(int j=0;j<=N;j++)
			// printf("%d ",a[i][j]);
		// puts("");
	// }
	// for(int i=0;i<n;i++)
		// for(int j=0;j<=n;j++)a[i][j]=0.0+read();
	for(int i=0;i<N;i++)
	{
		int amxn=i;
		for(int j=i+1;j<m;j++)if((a[j][i])>(a[amxn][i]))amxn=j;
		for(int j=0;j<=N;j++)swap(a[i][j],a[amxn][j]);
		swap(x[i],x[amxn]);
		swap(y[i],y[amxn]);
		swap(z[i],z[amxn]);
		swap(W[i],W[amxn]);
		if((a[i][i]==0))
		{
			for(int j=0;j<=N;j++)swap(a[i][j],a[m][j]);
			a[i][i]=1;
			a[i][N]=0;
			x[m]=x[i];
			y[m]=y[i];
			z[m]=z[i];
			W[m]=W[i];
			x[i]=i;
			y[i]=-1;
			z[i]=-1;
			W[i]=0;
			++m;
		}
	//	for(int i=0;i<n;i++,puts(""))
	//		for(int j=0;j<=n;j++)printf("%.2lf ",a[i][j]);puts("");
	
		for(int j=i+1;j<=N;j++)
		{
			a[i][j]=a[i][j]*a[i][i]%3;
		}
		a[i][i]=1;
		for(int j=0;j<m;j++)
		{
			if(i^j)
			{
				for(int k=i+1;k<=N;k++)a[j][k]=(a[j][k]+3-a[j][i]*a[i][k]%3)%3;
				a[j][i]=0;
			}
		}
			
		
	//	for(int i=0;i<n;i++,puts(""))
	//		for(int j=0;j<=n;j++)printf("%.2lf ",a[i][j]);puts("");
	}
	for(int i=0;i<N;i++)ans[i]=a[i][N];
	// for(int i=0;i<m;i++)
	// {
		// for(int j=0;j<=N;j++)
			// printf("%d ",a[i][j]);
		// puts("");
	// }
	// for(int i=0;i<N;i++)printf("%d ",a[i][N]); puts("");
	for(int i=0;i<m;i++)
	{
		int t=0;
		if(x[i]>=0)t+=ans[x[i]];
		if(y[i]>=0)t+=ans[y[i]];
		if(z[i]>=0)t+=ans[z[i]];
		if(t%3==W[i]);
		else 
		{
			puts("-1");
			goto fail;
		}
	}
	#define x X
	#define y Y
	#define z Z
	#define W WW
	for(int i=0;i<che;i++)
	{
		int t=0;
		if(x[i]>=0)t+=ans[x[i]];
		if(y[i]>=0)t+=ans[y[i]];
		if(z[i]>=0)t+=ans[z[i]];
		if(t%3==W[i]);
		else 
		{
			puts("-1");
			goto fail;
		}
	}
	
	for(int i=0;i<N;i++)printf("%d ",a[i][N]==0?3:a[i][N]);
	puts("");
	fail:;
	// puts("");
	// puts("");
	gr
	return 0;
}