// Problem: F. Crop Squares
// Contest: Codeforces - Codeforces Round #816 (Div. 2)
// URL: https://codeforces.com/contest/1715/problem/F
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
#define ld long double
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
signed main()
{
	int n=read(),m=read();
	ld sx,sy;
	printf("? %d\n",n*2+2);
	for(int i=0; i<n; ++i)
		printf("%d %d\n",i,0),
		printf("%d.999999999999999 %d\n",i,m);
	printf("%d %d\n",n,m);
	printf("0 %d\n",m);
	fflush(stdout);
	cin>>sx;
	printf("? %d\n",m*2+2);
	for(int i=0; i<m; ++i)
		printf("%d %d\n",0,i),
		printf("%d %d.999999999999999\n",n,i);
	printf("%d %d\n",n,m);
	printf("%d 0\n",n);
	fflush(stdout);
	cin>>sy;
	printf("! %.9Lf %.9Lf\n",sy*n-0.5,sx*m-0.5);
	return 0;
}