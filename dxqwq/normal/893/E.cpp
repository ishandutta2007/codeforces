// Problem: E. Counting Arrays
// Contest: Codeforces - Educational Codeforces Round 33 (Rated for Div. 2)
// URL: https://codeforces.com/contest/893/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=1000000007;
int qp(int x,int y)
{
	if(y==0) return 1;
	int res=1;
	for(int now=x; y; y>>=1,now=now*now%p) if(y&1) res=res*now%p;
	return res;
}
int ans[21][1000003],fac[1000003],ifac[1000003];
int C(int n,int m)
{
	return fac[n]*ifac[m]%p*ifac[n-m]%p;
}
signed main()
{
	fac[0]=ifac[0]=1;
	for(int i=1; i<=1000000; i++) fac[i]=fac[i-1]*i%p,ifac[i]=qp(fac[i],p-2);
	for(int i=2; i<=1000000; i++) ans[1][i]=1;
	for(int i=1; i<=18; ++i)
	{
		for(int j=qp(2,i); j<=500000; ++j)
		for(int k=2; j*k<=1000000; ++k) (ans[i+1][j*k]+=ans[i][j])%=p;
	}
 	for(int T=read();T--;)
 	{
 		int n=read(),m=read();
 		if(n==1)
 		{
 			printf("%lld\n",qp(2,m-1));
 			continue;
 		}
 		long long A=0;
 		for(int i=1; i<=min(19ll,m); ++i) A=(A+ans[i][n]*C(m,i)%p*qp(2,m-1)%p)%p;
 		printf("%lld\n",A);
 	}
	return 0;
}