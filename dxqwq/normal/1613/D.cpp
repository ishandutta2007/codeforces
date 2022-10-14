// Problem: D. MEX Sequences
// Contest: Educational Codeforces Round 118 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1613/problem/D
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
int a[1000003],f[1000003][2];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=0; i<=n+1; ++i) f[i][0]=f[i][1]=0;
		for(int i=1; i<=n; ++i) a[i]=read();
		for(int i=1; i<=n; ++i)
		{
			if(a[i]!=0)
			f[a[i]-1][1]=(f[a[i]-1][1]<<1)%p;
			f[a[i]-1][1]=(f[a[i]-1][1]+f[a[i]-1][0])%p;
			
			f[a[i]+1][0]=(f[a[i]+1][0]<<1)%p,
			f[a[i]+1][1]=(f[a[i]+1][1]<<1)%p;
			
			f[a[i]+1][0]=(f[a[i]+1][0]+f[a[i]][0])%p;
				
			if(a[i]==0) f[1][0]=(f[1][0]+1)%p;
			else if(a[i]==1) f[0][1]=(f[0][1]+1)%p;
		}
		int ans=0;
		for(int i=0; i<=n+1; ++i) ans=(ans+f[i][0]+f[i][1])%p;
		printf("%lld\n",ans);
	}
	return 0;
}
//mex-1
//mex      mex+=1
//mex+1
//1 -1 1 -1(0)2 0 2 0(1)3 1 3 1(2)4 2 4 2