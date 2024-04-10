// Problem: C. Knights
// Contest: Codeforces - Codeforces Round #518 (Div. 1) [Thanks, Mail.Ru!]
// URL: https://codeforces.com/problemset/problem/1067/C
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
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
signed main()
{
	int n=read();
	for(int i=0; i<n; ++i) printf("%d %d\n",(i/3)*2+(i%3==1),i%3);
	return 0;
}