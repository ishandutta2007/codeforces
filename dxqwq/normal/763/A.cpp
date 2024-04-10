// Problem: A. Timofey and a tree
// Contest: Codeforces Round #395 (Div. 1)
// URL: https://codeforces.com/contest/763/problem/A
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
vector<int> e[1000003];
int a[1000003],d[1000003];
int s[1000003];
signed main()
{
	int n=read();
	for(int i=1; i<n; ++i)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1; i<=n; ++i) a[i]=read();
	int S=0;
	for(int i=1; i<=n; ++i) for(int j:e[i]) if(a[i]!=a[j]) ++S;
	S>>=1;
	for(int i=1; i<=n; ++i) 
	{
		int T=0;
		for(int j:e[i]) if(a[i]!=a[j]) ++T;
		if(S==T)
		{
			puts("YES");
			printf("%lld\n",i);
			return 0;
		}
	}
	puts("NO");
	return 0;
}