// Problem: C. Digital Logarithm
// Contest: Codeforces - Educational Codeforces Round 135 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1728/problem/C
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
int aa[13],bb[13];
int L(int x)
{
	if(x<10) return x;
	int s=0;
	while(x) ++s,x/=10;
	return s;
}
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		map<int,int> a,b;
		for(int i=1; i<=n; ++i) 
		{
			int x=read();
			++a[x];
		}
		for(int i=1; i<=n; ++i)
		{
			int x=read();
			if(a[x]>0) --a[x];
			else ++b[x];
		}
		for(int i=2; i<=9; ++i) aa[i]=bb[i]=0;
		int s=0;
		for(auto it:a) 
		{
			if(it.first>=10) s+=it.second;
			aa[L(it.first)]+=it.second;
		}
		for(auto it:b) 
		{
			if(it.first>=10) s+=it.second;
			bb[L(it.first)]+=it.second;
		}
		for(int i=2; i<=9; ++i) s+=abs(aa[i]-bb[i]);
		printf("%lld\n",s);
	}
	return 0;
}