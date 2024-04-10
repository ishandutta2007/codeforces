// Problem: F1. Array Shuffling
// Contest: Codeforces Global Round 20
// URL: https://codeforces.com/contest/1672/problem/F1
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
pair<int,int> a[1000003],b[1000003];
int A[1000003],p[1000003],l[1000003];
int OP(int x,int y)
{
	return a[l[b[x].second]+y-1].second;
}
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) 
		a[i]=make_pair(A[i]=read(),i);
		sort(a+1,a+n+1);
		for(int i=1; i<=n; ++i) p[i]=-1;
		int sz=0;
		for(int i=1; i<=n; ++i)
		{
			int z=i,g=1;
			++sz;
			while(i<n&&a[i].first==a[i+1].first) ++i,++g;
			l[sz]=z,b[sz]=make_pair(g,sz);
			// printf("--- %lld %lld\n",z,i);
		}
		sort(b+1,b+sz+1);
		for(int o=1,pos=1; ; ++o)
		{
			while(pos<=sz&&b[pos].first<o)
			{
				++pos;
			}
			if(pos>sz) break;
			if(pos==sz){p[OP(sz,o)]=A[OP(sz,o)];}
			else
			{
				for(int i=pos; i<sz; ++i)
					p[OP(i,o)]=A[OP(i+1,o)];
				p[OP(sz,o)]=A[OP(pos,o)];
			}
		// for(int i=1; i<=n; ++i) printf("%lld ",p[i]);
		// puts("");
		}
		for(int i=1; i<=n; ++i) printf("%lld ",p[i]);
		puts("");
	}
	return 0;
}