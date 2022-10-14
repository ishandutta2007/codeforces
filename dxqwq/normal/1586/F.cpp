// Problem: F. Defender of Childhood Dreams
// Contest: Codeforces - Codeforces Round #749 (Div. 1 + Div. 2, based on Technocup 2022 Elimination Round 1)
// URL: https://codeforces.com/contest/1586/problem/F
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
int f[1003][1003];
int n=read(),m=read();
int ans=0;
void solve(int k,int C)
{
	if(k>=n) return ;
	ans=C;
	for(int i=1; i<=n; ++i)
		for(int j=i+1; j<=n; ++j)
			if((i-1)/k!=(j-1)/k)
				f[i][j]=C;
	solve(k*m,C+1);
}
signed main()
{
	solve(1,1);
	printf("%d\n",ans);
	for(int i=1; i<=n; ++i)
		for(int j=i+1; j<=n; ++j)
			printf("%d ",f[i][j]);
	return 0;
}