// Problem: A. Stable Arrangement of Rooks
// Contest: Codeforces - Hello 2022
// URL: https://codeforces.com/contest/1621/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
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
		int n=read(),m=read();
		if(((n+1)>>1)<m)
		{
			puts("-1");
			continue;
		}
		for(int i=1; i<=n; ++i,puts(""))
			for(int j=1; j<=n; ++j)
				if(i==j&&(i&1)&&(i>>1)<m) putchar('R'); else putchar('.');
	}
	return 0;
}