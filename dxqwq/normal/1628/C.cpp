// Problem: C. Grid Xor
// Contest: Codeforces - Codeforces Round #767 (Div. 1)
// URL: https://codeforces.com/contest/1628/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
int a[2003][2003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),ans=0;
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=n; ++j)
				a[i][j]=read();
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=n; ++j)
				if(((i+j)&3)==0&&(((i&1)==0)^(i+j<=n+1))) 
					ans^=a[i][j];
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=(n>>1); ++j)
				swap(a[i][j],a[i][n+1-j]);
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=n; ++j)
				if(((i+j)&3)==0&&(((i&1)==0)^(i+j<=n+1)))
					ans^=a[i][j];
		printf("%d\n",ans);
	}
	return 0;
}