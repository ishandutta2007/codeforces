// Problem: C. Need for Pink Slips
// Contest: Codeforces - Codeforces Round #730 (Div. 2)
// URL: https://codeforces.com/contest/1543/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
inline double min(double a,double b){return a>b?b:a;}
inline double max(double a,double b){return a<b?b:a;}
double e;
double eps=1e-10;
double dfs(double a,double b,double c,int d)
{
//	if(a+b+c<0.99||a+b+c>1.01)puts("???");
	if(a<eps&&b<eps)return 1;
	if(d>19)return 0;
	if(b<eps)return 1+dfs(max(a-e,0),0,min(1,c+e),d+1)*a;
	if(a<eps)return 1+dfs(0,max(b-e,0),min(1,c+e),d+1)*b;
	return 1+dfs(a+min(b,e)/2,max(0,b-e),c+min(b,e)/2,d+1)*b+dfs(max(0,a-e),b+min(a,e)/2,c+min(a,e)/2,d+1)*a;
}
signed main()
{
	int T=read();
	rg(T)double a,b,c;
	scanf("%lf%lf%lf%lf",&a,&b,&c,&e);
	printf("%.9lf\n",dfs(a,b,c,0));gr
	return 0;
}