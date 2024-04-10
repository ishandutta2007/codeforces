// Problem: E. Magic Stones
// Contest: Codeforces - Codeforces Global Round 1
// URL: https://codeforces.com/contest/1110/problem/E
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
signed main()
{
	int n=read();
	map<int,int> ma,mb;
	const int S=1e9;
	for(int lst=0,x,i=1; i<=n; ++i)
		ma[(x=read())-lst]+=(i==1?S:1),lst=x;
	for(int lst=0,x,i=1; i<=n; ++i)
		mb[(x=read())-lst]+=(i==1?S:1),lst=x;
	if(ma==mb) puts("Yes");
	else puts("No");
	return 0;
}