// Problem: B. Present
// Contest: Codeforces - Codeforces Round #626 (Div. 1, based on Moscow Open Olympiad in Informatics)
// URL: https://codeforces.com/contest/1322/problem/B
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int M=10000002;
int a[500003],c[10000003],n=read(),m,ans;
inline int q(int x){return x<m?(x>=0?c[x]:0):n;}
signed main()
{
	for(int i=1; i<=n; ++i) a[i]=read();
	for(int d=0; d<=24; ++d)
	{
		m=min(1<<(d+1),M);
		memset(c,0,m<<2);
		for(int i=1; i<=n; ++i)
			++c[a[i]&((1<<(d+1))-1)];
		for(int i=1; i<m; ++i)
			c[i]+=c[i-1];
		long long sum=1ll*n*n;
		for(int i=1; i<=n; ++i)
			sum-=q((1<<d)-(a[i]&((1<<(d+1))-1))-1),
			sum+=q((2<<d)-(a[i]&((1<<(d+1))-1))-1),
			sum-=q((3<<d)-(a[i]&((1<<(d+1))-1))-1);
		for(int i=1; i<=n; ++i)
			sum-=(((a[i]<<1)>>d)&1);
		// if((sum&1)==1) printf("error %d %d %lld\n",d,
		// (a[1]&((1<<(d+1))-1)),sum);
		ans^=(((sum>>1)&1)<<d);
	}
	printf("%d\n",ans);
	return 0;
}