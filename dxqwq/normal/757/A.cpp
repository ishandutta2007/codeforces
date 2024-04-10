// Problem: A. Gotta Catch Em' All!
// Contest: Codeforces - Codecraft-17 and Codeforces Round #391 (Div. 1 + Div. 2, combined)
// URL: https://codeforces.com/contest/757/problem/A
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
char s[1000003];
char t[]="Bulbasaur";
int A[256],B[256];
signed main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	int c=1e18;
	for(int i=1; i<=n; ++i) ++A[s[i]];
	for(int i=0; i<9; ++i) ++B[t[i]];
	for(int i=0; i<256; ++i) if(B[i]) c=min(c,A[i]/B[i]);
	printf("%lld\n",c);
	return 0;
}