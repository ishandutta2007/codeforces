// Problem: B. Mainak and Interesting Sequence
// Contest: Codeforces Round #819 (Div. 1 + Div. 2) and Grimoire of Code Annual Contest 2022
// URL: https://codeforces.com/contest/1726/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
		if(n>m) puts("No");
		else if(m%n==0)
		{
			puts("Yes");
			for(int i=1; i<=n; ++i) printf("%lld ",m/n);
			puts("");
		}
		else if(n&1)
		{
			puts("Yes");
			for(int i=1; i<n; ++i) printf("1 ");
			printf("%lld\n",m-n+1);
		}
		else
		{
			int z=m-n+2;
			if(z&1) puts("No");
			else{
			puts("Yes");
			for(int i=1; i<=n-2; ++i) printf("1 ");
			printf("%lld %lld\n",z/2,z/2);
			}
		}
	}
	return 0;
}