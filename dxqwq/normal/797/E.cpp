// Problem: E. Array Queries
// Contest: Codeforces - Educational Codeforces Round 19
// URL: https://codeforces.com/problemset/problem/797/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
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
int a[100003];
int f[320][100003];
const int B=320;
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	for(int i=1; i<B; ++i)
		for(int j=n; j>=1; --j)
			f[i][j]=f[i][min(n+1,j+a[j]+i)]+1;
	for(int x,y,z=0,T=read(); T--;)
	{
		x=read(),y=read(),z=0;
		if(y<B)
		{
			printf("%d\n",f[y][x]);
			continue;
		}
		while(x<=n) x+=a[x]+y,++z;
		printf("%d\n",z);
	}
	return 0;
}