// Problem: F. Ideal Farm
// Contest: Codeforces - Codeforces Round #747 (Div. 2)
// URL: https://codeforces.com/contest/1594/problem/F
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
signed main()
{
	for(int T=read();T--;)
	{
		int s=read(),n=read(),k=read();
		if(s<k)
		{
			puts("NO");
			continue;
		}
		if(s==k)
		{
			puts("YES");
			continue;
		}
		//k<s
		++s;
		int A=s/(k*2),B=s%(k*2);
		int C=A*k,D=min(B,k);
		int E=C+D;
		if(E>=n+1) puts("NO");
		else puts("YES");
	}
	return 0;
}