// Problem: E. Ela Goes Hiking
// Contest: Dytechlab Cup 2022
// URL: https://codeforces.com/contest/1737/problem/E
// Memory Limit: 256 MB
// Time Limit: 2500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse0,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=1e9+7,h=(p+1)>>1;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int f[1000003],g[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		g[n+1]=0;
		//all right
		for(int i=1; i<n; ++i)
			f[i]=qp(h,(i+1)>>1);
		f[n]=qp(h,((n+1)>>1)-1);
		//2i<=n
		for(int i=n; i>=(n>>1)+1; --i)
			g[i]=(g[i+1]+f[i])%p;
		for(int i=n>>1; i>=1; --i)
			f[i]=f[i]*(p+1-g[i<<1])%p,
			g[i]=(g[i+1]+f[i])%p;
		for(int i=1; i<=n; ++i) printf("%lld\n",f[i]);
	}
	return 0;
}