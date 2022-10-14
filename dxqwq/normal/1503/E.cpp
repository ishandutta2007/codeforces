// Problem: CF1503E 2-Coloring
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1503E
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
int fac[5003],ifac[5003],f[2003][2003],g[2003][2003];
int G(int n,int m)
{
	return fac[n+m]*ifac[n]%p*ifac[m]%p;
}
int F1(int n,int m)
{
	int ans=0;
	for(int j=1; j<m; ++j)
	{
		int sum=0;
		for(int i=1; i<n; ++i)
			sum=(sum+G(i-1,j)*G(n-i,j-1))%p,
			ans=(ans+sum*G(i,m-j-1)%p*G(n-i-1,m-j))%p;
	}
	// printf("%lld\n",ans);
	return ans;
}
int F2(int n,int m)
{
	int ans=0;
	for(int j=1; j<m; ++j)
	{
		int sum=0;
		for(int i=1; i<n; ++i)
			ans=(ans+sum*G(i,m-j-1)%p*G(n-i-1,m-j))%p,
			sum=(sum+G(i-1,j)*G(n-i,j-1))%p;
	}
	// printf("%lld\n",ans);
	return ans;
}
signed main()
{
	int n=read(),m=read();
	fac[0]=ifac[0]=1;
	for(int i=1; i<=5000; ++i) 
		fac[i]=fac[i-1]*i%p,ifac[i]=qp(fac[i],p-2);
	printf("%lld\n",((F1(n,m)+F2(m,n))<<1)%p);
	return 0;
}