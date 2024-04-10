// Problem: B. Factorial Divisibility
// Contest: Codeforces Round #829 (Div. 1)
// URL: https://codeforces.com/contest/1753/problem/B
// Memory Limit: 256 MB
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
int a[500003];
bool vis[500003];
int t[500003];
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; ++i) ++a[read()];
	for(int i=1; i<m; ++i)
	{
		if(a[i]%(i+1)) puts("No"),exit(0);
		else a[i+1]+=a[i]/(i+1);
	}
	puts("Yes");
	return 0;
}