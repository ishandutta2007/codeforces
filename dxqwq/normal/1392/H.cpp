// Problem: CF1392H ZS Shuffles Cards
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1392H
// Memory Limit: 500 MB
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
const int N=4000000;
int fac[N+3],ifac[N+3],inv[N+3];
int C(int n,int m)
{
	return fac[n]*ifac[n-m]%p*ifac[m]%p;
}
const int h=(p+1)>>1;
signed main()
{
	int n=read(),m=read();
	fac[0]=ifac[0]=inv[1]=1;
	for(int i=1; i<=N; ++i) fac[i]=fac[i-1]*i%p;
	ifac[N]=qp(fac[N],p-2);
	for(int i=N-1; i>=1; --i) ifac[i]=ifac[i+1]*(i+1)%p;
	for(int i=2; i<=N; ++i) inv[i]=fac[i-1]*ifac[i]%p;
	int ans=0,z=1,pz=0;
	for(int i=0; i<=n; ++i)
		pz=(pz+z)%p,z=z*inv[n+m-i]%p*(n-i)%p;
	for(int i=1; i<=n; ++i)
	{
		int s=C(n,i)*inv[i]%p*(i+m)%p;
		if(i&1) ans=(ans+s)%p;
		else ans=(ans+p-s)%p;
	}
	printf("%lld\n",ans*pz%p);
	return 0;
}