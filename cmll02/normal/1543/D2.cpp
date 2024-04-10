// Problem: D2. RPD and Rap Sheet (Hard Version)
// Contest: Codeforces - Codeforces Round #730 (Div. 2)
// URL: https://codeforces.com/contest/1543/problem/D2
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
//#define int long long
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
int a[105],b[105],c[105];
//#define c b
signed main()
{
	int T=read();
	rg(T)int n=read(),k=read();
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	int aa=0,o=1;
	for(int i=0;i<n;i++)
	{
		int c=0;
		int c1=0,c2=0;
		int s=aa,t=i;
		while(s)a[c1++]=s%k,s/=k;
		while(t)b[c2++]=t%k,t/=k;
		while(c1<c2)a[c1++]=0;
		while(c2<c1)b[c2++]=0;
		int qwq=0;
		for(int i=c1-1;~i;i--)qwq=qwq*k+((a[i]+o*b[i])%k+k)%k;
		odl(qwq);
		fflush(stdout);
		int r=read();
		if(r)break;
		o=-o;
		c1=c2=0;
		s=qwq,t=aa;
		while(s)a[c1++]=s%k,s/=k;
		while(t)b[c2++]=t%k,t/=k;
		while(c1<c2)a[c1++]=0;
		while(c2<c1)b[c2++]=0;
		qwq=0;
		for(int i=c1-1;~i;i--)qwq=qwq*k+((a[i]-b[i])%k+k)%k;
		aa=qwq;
	}
	
	//x+z==y
	//y-x==z
	//y-x=z
	//y y-x
	//
	// U U-
	gr
	return 0;
}