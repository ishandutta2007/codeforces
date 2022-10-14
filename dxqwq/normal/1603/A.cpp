// Problem: A. Di-visible Confusion
// Contest: Codeforces Round #752 (Div. 1)
// URL: https://codeforces.com/contest/1603/problem/A
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
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i)	a[i]=read();
		bool f=1;
		for(int i=1; i<=n; ++i)
		{
			f=0;
			for(int j=2; j<=i+1; ++j) if(a[i]%j)
			{
				f=1;
				break;
			}
			if(!f) break;
		}
		if(f) puts("YES"); else puts("NO");
	}
	return 0;
}