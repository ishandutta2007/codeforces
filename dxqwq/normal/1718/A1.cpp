// Problem: A2. Burenka and Traditions (hard version)
// Contest: Codeforces Round #814 (Div. 1)
// URL: https://codeforces.com/contest/1718/problem/A2
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
int a[1000003],dp[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) a[i]=read()^a[i-1];
		map<int,int> mp;
		mp[0]=0;
		for(int i=1; i<=n; ++i)
		{
			dp[i]=dp[i-1]+1;
			if(mp.find(a[i])!=mp.end())
				dp[i]=min(dp[i],i+mp[a[i]]-1);
			mp[a[i]]=dp[i]-i;
		}
		printf("%lld\n",dp[n]);
	}
	return 0;
}