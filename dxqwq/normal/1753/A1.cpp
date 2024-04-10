// Problem: A1. Make Nonzero Sum (easy version)
// Contest: Codeforces Round #829 (Div. 1)
// URL: https://codeforces.com/contest/1753/problem/A1
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
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int a[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		int s=0;
		for(int i=1; i<=n; ++i)
			if(a[i]!=0) ++s;
		if(s%2)
		{
			puts("-1");continue;
		}
		int A=0;
		for(int i=1; i<=n; i+=2)
		{
			if(a[i]==a[i+1]) ++A;
			else A+=2;
		}
		printf("%d\n",A);
		for(int i=1; i<=n; i+=2)
		{
			if(a[i]==a[i+1]) printf("%d %d\n",i,i+1);
			else printf("%d %d\n%d %d\n",i,i,i+1,i+1);
		}
	}
	return 0;
}