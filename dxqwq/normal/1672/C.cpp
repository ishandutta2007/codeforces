// Problem: C. Unequal Array
// Contest: Codeforces Global Round 20
// URL: https://codeforces.com/contest/1672/problem/C
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
int a[1000003],b[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) b[i]=a[i]=read();
		int A=0,B=0;
		for(int i=1; i<n; ++i) if(a[i]==a[i+1]) {A=i;break;}
		for(int i=n; i>1; --i) if(a[i]==a[i-1]) {B=i;break;}
		if(B-A<=1) puts("0");
		else if(B-A==2) puts("1");
		else printf("%lld\n",B-A-2);
	}
	return 0;
}