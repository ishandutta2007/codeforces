// Problem: B. Permutation Sort
// Contest: Codeforces - Educational Codeforces Round 109 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1525/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
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
		for(int i=1; i<=n; ++i) a[i]=read();
		if(n==1)
		{
			puts("0");
			continue;
		}
		bool F=1;
		for(int i=1; i<n; ++i) if(a[i]>a[i+1]) F=0;
		if(F)
		{
			puts("0");
			continue;
		}
		if(a[1]==1)
		{
			puts("1");
			continue;
		}
		if(a[n]==n)
		{
			puts("1");
			continue;
		}
		if(a[1]==n&&a[n]==1)
		{
			puts("3");
			continue;
		}
		puts("2");
	}
	return 0;
}