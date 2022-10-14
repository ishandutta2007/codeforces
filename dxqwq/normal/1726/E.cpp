// Problem: E. Almost Perfect
// Contest: Codeforces - Codeforces Round #819 (Div. 1 + Div. 2) and Grimoire of Code Annual Contest 2022
// URL: https://codeforces.com/contest/1726/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
int fac[1000003],ifac[1000003];
int C(int n,int m)
{
	return fac[n]*ifac[m]%p*ifac[n-m]%p;
}
int F[1000003],G[1000003];
signed main()
{
	const int N=1000000;
	fac[0]=ifac[0]=1;
	for(int i=1; i<=N; ++i) fac[i]=fac[i-1]*i%p;
	ifac[N]=qp(fac[N],p-2);
	for(int i=N-1; i>=1; --i) ifac[i]=ifac[i+1]*(i+1)%p;
	//of 1: 1 ways
	//of 2: 2 ways
	//of 4: 
	F[0]=1;G[0]=1,G[1]=1;
	for(int i=2; i<=N; i+=2) F[i]=F[i-2]*(i-1)%p;
	for(int i=2; i<=N; ++i)
	{
		G[i]=(G[i-1]+(i-1)*G[i-2])%p;
	}
	const int inv4=qp(4,p-2);
	for(int T=read();T--;)
	{
		int n=read(),ans=0;
		for(int i=0,cur=1; i*2<=n; i+=2)
		{
			ans=(ans+C(n-i,i)*qp(2,i/2)%p*F[i]%p*G[n-i*2])%p;
			// printf("%lld %lld\n",i,
			// C(n-i,i)*qp(2,i/2)%p*F[i]%p*G[n-i*2]%p);
			// cur=cur*(n-i*2)%p;
			// cur=cur*(n-i*2-1)%p;
			// cur=cur*(n-i*2-2)%p;
			// cur=cur*(n-i*2-3)%p;
			// cur=cur*inv4%p;
		}
		printf("%lld\n",ans);
	}
	return 0;
}