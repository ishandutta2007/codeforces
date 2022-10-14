// Problem: E. Balance Addicts
// Contest: Codeforces - Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
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
int a[100003];
int fac[100003],ifac[100003];
int C(int n,int m)
{
	return fac[n]*ifac[m]%p*ifac[n-m]%p;
}
int F(int x,int y)
{
	if(x>y) swap(x,y);
	if(x==0) return 1;
	int r=1;
	for(int i=1; i<=x; ++i)
		r=(r+C(x,i)*C(y,i))%p;
	return r;
}
signed main()
{
	fac[0]=ifac[0]=1;
	for(int i=1; i<=100000; ++i)
	fac[i]=fac[i-1]*i%p,ifac[i]=qp(fac[i],p-2);
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		int s=0;
		for(int i=1; i<=n; ++i) s+=a[i];
		if(s==0)
		{
			printf("%lld\n",qp(2,n-1));
			continue;
		}
		a[n+1]=0;
		int ans=1,m=0,ss=0;
		while(ss*2<s) ss+=a[++m];
		if(ss*2!=s)
		{
			map<int,int> ma,mb;
			for(int i=1,pr=0; i<=m; ++i)
				pr+=a[i],++ma[pr];
			for(int i=n,pr=0; i>m; --i)
				pr+=a[i],++mb[pr];
			for(auto it:ma)
			{
				int A=mb[it.first];
				int B=it.second;
				ans=ans*F(A,B)%p;
			}
		}
		else
		{
			int k=m+1,z=1;
			while(!a[k]) ++z,++k;
			map<int,int> ma,mb;
			for(int i=1,pr=0; i<=m; ++i)
				pr+=a[i],++ma[pr];
			for(int i=n,pr=0; i>=k; --i)
				pr+=a[i],++mb[pr];
			for(auto it:ma) if(it.first!=s/2)
			{
				int A=mb[it.first];
				int B=it.second;
				ans=ans*F(A,B)%p;
			}
			ans=ans*qp(2,z)%p;
		}
		printf("%lld\n",ans);
	}
	return 0;
}