// Problem: F. Omkar and Akmar
// Contest: Codeforces - Codeforces Round #724 (Div. 2)
// URL: https://codeforces.com/contest/1536/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=1e9+7;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int fac[2000003];
int ifac[2000003];
int C(int n,int m)
{
	if(n<m) return 0;
	return fac[n]*ifac[m]%p*ifac[n-m]%p;
}
int f(int n,int m)
{
	return (C(n,m)+C(n-1,m-1))%p;
}
signed main()
{
	int n=read();
	fac[0]=1,ifac[0]=1;
	for(int i=1; i<=n+5; ++i) 
	fac[i]=fac[i-1]*i%p,ifac[i]=qp(fac[i],p-2);
	int ans=0;
	for(int i=2; i<=n; i+=2)
	{
		ans=(ans+fac[i]*f(i,n-i)%p)%p;
	}
	printf("%lld\n",ans*2%p);
	return 0;
}