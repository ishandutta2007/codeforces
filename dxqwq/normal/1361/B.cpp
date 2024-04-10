// Problem: B. Johnny and Grandmaster
// Contest: Codeforces Round #647 (Div. 1) - Thanks, Algo Muse!
// URL: https://codeforces.com/contest/1361/problem/B
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
const int p=1e9+7;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int a[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		sort(a+1,a+n+1);
		int ans=0;
		int dif=0;
		if(m==1)
		{
			printf("%lld\n",(n&1));
			continue;
		}
		for(int i=n; i>=1; --i)
		{
			if(!dif)
			{
				ans=(ans+qp(m,a[i]))%p;
				dif=1;
			}
			else if(a[i]==a[i+1])
			{
				ans=(p+ans-qp(m,a[i]))%p;
				--dif;
			}
			else
			{
				int q=a[i+1]-a[i];
				while(dif<=1000000000&&q--)
				{
					dif*=m;
				}
				if(dif>1000000000)
				{
					for(int j=1; j<=i; ++j)
					{
						ans=(p+ans-qp(m,a[j]))%p;
						
					}
					break;
				}
				else
				{
					ans=(p+ans-qp(m,a[i]))%p;
					--dif;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}