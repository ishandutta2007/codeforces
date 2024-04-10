// Problem: A. Long Comparison
// Contest: Educational Codeforces Round 118 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1613/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
		int n1=read(),m1=read();
		int n2=read(),m2=read();
		if(m1-m2>=10) puts(">");
		else if(m2-m1>=10) puts("<");
		else
		{
			for(int i=1; i<=m1-m2; ++i) n1*=10;
			for(int i=1; i<=m2-m1; ++i) n2*=10;
			if(n1>n2) puts(">");
			else if(n1==n2) puts("=");
			else puts("<");
		}
	}
	return 0;
}