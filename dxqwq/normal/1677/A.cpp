// Problem: CF1677A Tokitsukaze and Strange Inequality
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1677A
// Memory Limit: 250 MB
// Time Limit: 1500 ms
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
int a[10003],f[10003],g[10003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		int s=0;
		for(int i=2; i<n; ++i)
		{
			int t=0;
			for(int j=i+1; j<=n; ++j)
				t+=(a[i]>a[j]);
			for(int j=1; j<=n; ++j) f[j]=0;
			for(int j=1; j<i; ++j) ++f[a[j]];
			for(int j=1; j<=n; ++j) f[j]+=f[j-1];
			for(int j=i+1; j<n; ++j)
			{
				t-=(a[i]>a[j]);
				s+=t*f[a[j]];
			}
		}
		printf("%lld\n",s);
	}
	return 0;
}