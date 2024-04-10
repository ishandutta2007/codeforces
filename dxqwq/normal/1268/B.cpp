// Problem: B. Domino for Young
// Contest: Codeforces - Codeforces Round #609 (Div. 1)
// URL: https://codeforces.com/contest/1268/problem/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int a[1000003];
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	int s=0,t=0;
	for(int i=1; i<=n; ++i) 
	{s+=(a[i]>>1); t+=((a[i]+1)>>1); swap(s,t);}
	printf("%lld\n",min(s,t));
	return 0;
}