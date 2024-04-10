// Problem: C. Wish I Knew How to Sort
// Contest: Codeforces Round #829 (Div. 1)
// URL: https://codeforces.com/contest/1753/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003];
int f[1000003];
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),s=n;
		for(int i=1; i<=n; ++i) a[i]=read(),s-=a[i];
		int t=0;
		for(int i=1; i<=s; ++i) t+=a[i];
		f[0]=0;
		int G=n*(n-1)/2;
		G%=p;
		for(int i=1; i<=t; ++i)
			f[i]=(f[i-1]+qp(i*i%p,p-2)*G%p)%p;
		printf("%lld\n",f[t]);
	}
	return 0;
}