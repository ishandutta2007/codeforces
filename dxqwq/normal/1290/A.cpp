// Problem: A. Mind Control
// Contest: Codeforces - Codeforces Round #616 (Div. 1)
// URL: https://codeforces.com/contest/1290/problem/A
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
int a[5003],b[5003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read(),k=read();
		k=min(k,m-1);
		for(int i=1; i<=n; ++i) a[i]=read();
		int len=n-m+1;
		for(int i=1; i+len-1<=n; ++i)
			b[i]=max(a[i],a[i+len-1]);
		n=n-len+1;
		len=m-k;
		int ans=0;
		for(int i=1; i+len-1<=n; ++i)
		{
			int z=1e18;
			for(int j=i; j<i+len; ++j) z=min(z,b[j]);
			ans=max(ans,z);
		}
		printf("%lld\n",ans);
	}
	return 0;
}