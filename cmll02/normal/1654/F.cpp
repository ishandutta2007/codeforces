#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
char a[1000005];
typedef int arr[1000005];
arr t,sa;
int *r,*f,*qwq;
int main()
{
	r=new int[1000005];
	f=new int[1000005];
	read();
	scanf("%s",a+1);
	int n=strlen(a+1),m='z';
	rg(n)r[i]=a[i],f[i]=i;gr
	rg(n)t[r[i]]++;gr
	rg(m)t[i]+=t[i-1];gr
	rg(n)sa[t[r[f[n-i+1]]]--]=f[n-i+1];gr
	for(int k=1;k<n;k<<=1)
	{
		int cc=0;
		rg(n)f[++cc]=(i-1^k)+1;gr
		// rg(n)if(sa[i]>k)f[++cc]=sa[i]-k;gr
		rg(n)f[i]=(sa[i]-1^k)+1;gr
		memset(t,0,sizeof(t));
		rg(n)t[r[i]]++;gr
		rg(m)t[i]+=t[i-1];gr
		rg(n)sa[t[r[f[n-i+1]]]--]=f[n-i+1];gr
		qwq=r;r=f;f=qwq;
		r[sa[1]]=1;cc=1;
		rg(n)if(i==1)continue;
		r[sa[i]]=(f[sa[i]]==f[sa[i-1]]&&f[(sa[i]-1^k)+1]==f[(sa[i-1]-1^k)+1])?cc:++cc;
		gr if(cc==n)break;m=cc;
	}
	// rg(n)odb(sa[i]);gr
	rg(n)putchar(a[(i-1^sa[1]-1)+1]);gr
	delete[] r;delete[] f;
	return 0;
}