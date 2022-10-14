// Problem: E. AmShZ and G.O.A.T.
// Contest: Codeforces
// URL: https://codeforces.com/contest/1610/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int a[200003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		int mx=0;
		a[n+1]=-1;
		for(int i=1,nxt; i<=n; i=nxt)
		{
			nxt=i;
			while(a[i]==a[nxt]) ++nxt;
			int t=nxt,sum=nxt-i+1;
			if(t==n+1)
			{
				mx=max(mx,n-i+1);
				break;
			}
			while(1)
			{
				int g=lower_bound(a+1,a+n+1,a[t]+(a[t]-a[i]))-a;
				if(g==n+1) break;
				else t=g,++sum;
			}
			mx=max(mx,sum);
		}
		printf("%lld\n",n-mx);
	}
	return 0;
}