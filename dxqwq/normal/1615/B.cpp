// Problem: B. And It's Non-Zero
// Contest: Codeforces Global Round 18
// URL: https://codeforces.com/contest/1615/problem/B
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int solve(int x,int y)
{
	++x;
	int g=x/(y*2);
	int q=max(0ll,(x%(y*2))-y);
	return g*y+q;
}
signed main()
{
	for(int T=read();T--;)
	{
		int l=read()-1,r=read();
		int ans=1;
		for(int i=1; i<=r; i<<=1)
			ans=max(solve(r,i)-solve(l,i),ans);
		printf("%lld\n",r-l-ans);
	}
	return 0;
}