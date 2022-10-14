// Problem: A. Array Elimination
// Contest: Codeforces Round #751 (Div. 1)
// URL: https://codeforces.com/contest/1601/problem/A
// Memory Limit:  MB
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
int a[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i)
			a[i]=read();
		int ans=0;
		for(int x=1,i=1; x<=31; ++x,i<<=1)
		{
			int A=0;
			for(int j=1; j<=n; ++j) if(a[j]&i)
				++A;
			if(A) if(ans) ans=__gcd(ans,A);
			else ans=A;
		}
		if(ans==0)
		{
			for(int i=1; i<=n; ++i)
				printf("%lld ",i);
			puts("");
			continue;
		}
		for(int i=1; i<=ans; ++i)
			if(!(ans%i)) printf("%lld ",i);
		puts("");
	}
	return 0;
}