// Problem: B. Plus and Multiply
// Contest: Codeforces - Codeforces Round #729 (Div. 2)
// URL: https://codeforces.com/contest/1542/problem/B
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//lost in rain
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <bitset>
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
#define int long long
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
signed main()
{
	int T=read();
	rg(T)int x=read(),a=read(),b=read();
	if(a==1)
	{
		if((x-1)%b==0)puts("Yes");
		else puts("No");
	}
	else
	{
		for(int i=1;i<=x;i*=a)if((x-i)%b==0)goto nn;
		puts("No");
		continue;
		nn:;
		puts("Yes");
	}gr
	return 0;
}