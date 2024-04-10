// Problem: C. Permutation Operations
// Contest: Codeforces Global Round 23
// URL: https://codeforces.com/contest/1746/problem/C
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
int a[1000003],ans[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		vector<pair<int,int>> t;
		for(int i=1; i<n; ++i) t.push_back(make_pair(a[i]-a[i+1],i+1));
		sort(t.begin(),t.end());
		printf("1 ");
		for(int i=0; i+1<n; ++i) printf("%lld ",t[i].second);
		puts("");
	}
	return 0;
}