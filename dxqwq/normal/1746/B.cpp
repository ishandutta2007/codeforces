// Problem: B. Rebellion
// Contest: Codeforces Global Round 23
// URL: https://codeforces.com/contest/1746/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int a[1000003],f[1000003],g[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		for(int i=1; i<=n; ++i) f[i]=f[i-1]+(a[i]==1);
		int z=0;
		g[n+1]=0;
		for(int i=n; i>=1; --i) g[i]=g[i+1]+(a[i]==0);
		int ans=1e18;
		for(int i=0; i<=n; ++i)
			ans=min(ans,f[i]+max(0ll,g[i+1]-f[i]));
		printf("%lld\n",ans);
	}
	return 0;
}