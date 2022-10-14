// Problem: E. Conveyor
// Contest: Codeforces - Codeforces Round #821 (Div. 2)
// URL: https://codeforces.com/contest/1733/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define ll long long
inline ll read(){
   ll s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
ll f[123][123],g[123][123];
signed main()
{
	for(int T=read();T--;)
	{
		ll t=read();
		int x=read(),y=read();
		if(t<x+y){puts("NO");continue;}
		memset(f,0,sizeof(f)),memset(g,0,sizeof(g));
		f[0][0]=t-x-y+1,g[0][0]=t-x-y;
		for(int i=0; i<=x; ++i)
			for(int j=0; j<=y; ++j)
				f[i+1][j]+=f[i][j]>>1,
				f[i][j+1]+=(f[i][j]+1)>>1,
				g[i+1][j]+=g[i][j]>>1,
				g[i][j+1]+=(g[i][j]+1)>>1;
		if(f[x][y]!=g[x][y]) puts("YES");
		else puts("NO");
	}
	return 0;
}