// Problem: CF815B Karen and Test
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF815B
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
int a[1000003];
const int N=200000;
int fac[200003],ifac[200003];
int C(int n,int m)
{
	return fac[n]*ifac[m]%p*ifac[n-m]%p;
}
signed main()
{
	fac[0]=ifac[0]=1;
	for(int i=1; i<=N; ++i) fac[i]=fac[i-1]*i%p,ifac[i]=qp(fac[i],p-2);
	int n=read();
	if(n%4==0)
	{
		int N=(n>>1)-1,ans=0;
		for(int i=0; i<n; ++i)
		{
			int A=read();
			if(i&1)
			{
				ans=(ans+p-C(N,i>>1)*A%p)%p;
			}
			else
			{
				ans=(ans+C(N,i>>1)*A%p)%p;
			}
		}
		printf("%lld\n",ans);
	}
	else if(n%4==1)
	{
		int N=(n-1)>>1,ans=0;
		for(int i=0; i<n; ++i)
		{
			int A=read();
			if(i&1)
			{
				continue;
			}
			else
			{
				ans=(ans+C(N,i>>1)*A%p)%p;
			}
		}
		printf("%lld\n",ans);
	}
	else if(n%4==2)
	{
		int N=(n>>1)-1,ans=0;
		for(int i=0; i<n; ++i)
		{
			int A=read();
			ans=(ans+C(N,i>>1)*A%p)%p;
		}
		printf("%lld\n",ans);
	}
	else 
	{
		int N=(n-3)>>1,ans=0;
		int S=(p+1)>>1;
		for(int i=0; i<n; ++i)
		{
			int A=read();
			if(i&1)
			{
				ans=(ans+C(N,(i-1)>>1)*A%p*2%p)%p;
			}
			else
			{
				ans=(ans+(p+C(N,(i>>1))-C(N,(i>>1)-1)%p)*A%p)%p;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}