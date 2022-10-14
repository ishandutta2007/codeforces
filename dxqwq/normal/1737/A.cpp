// Problem: A. Ela Sorting Books
// Contest: Codeforces - Dytechlab Cup 2022
// URL: https://codeforces.com/contest/1737/problem/0
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
int a[26];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),k=read();
		scanf("%s",s+1);
		memset(a,0,sizeof(a));
		for(int i=1; i<=n; ++i) ++a[s[i]-'a'];
		for(int i=1; i<=k; ++i)
		{
			int q=0;
			while(a[q]>=i&&q<(n/k)) ++q;
			putchar('a'+q);
		}
		puts("");
	}
	return 0;
}