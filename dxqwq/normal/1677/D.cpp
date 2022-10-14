// Problem: D. Tokitsukaze and Permutations
// Contest: Codeforces - Codeforces Round #789 (Div. 1)
// URL: https://codeforces.com/contest/1677/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
	for(int T=read();T--;)
	{
		int n=read(),k=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		int ans=1;
		for(int i=1; i<=k; ++i) ans=ans*i%p;
		for(int i=1; i<=n-k; ++i) 
			if(a[i]>=i) ans=0;
			else if(a[i]==0) ans=ans*(k+1)%p;
			else if(a[i]==-1) ans=ans*(i+k)%p;
		for(int i=n-k+1; i<=n; ++i) if(a[i]>0) ans=0;
		printf("%lld\n",ans);
	}
	return 0;
}