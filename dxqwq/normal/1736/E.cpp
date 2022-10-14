// Problem: E. Swap and Take
// Contest: Codeforces - Codeforces Round #825 (Div. 2)
// URL: https://codeforces.com/contest/1736/problem/E
// Memory Limit: 1024 MB
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
int f[503][503],g[503][503],gg[503][503],a[503];
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	memset(f,0xc0,sizeof(f)),f[0][0]=0;
	memset(g,0xc0,sizeof(g)),g[1][1]=0,g[0][2]=0,
	memset(gg,0xc0,sizeof(gg));
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j)
		{
			if(j>i)
			for(int l=max(0,j-i-2); l<=i; ++l)
				gg[l-(j-i-2)][j]=max(gg[l-(j-i-2)][j],
				f[i][l]-i*a[j]);
			for(int k=0; k<=i; ++k)
				f[i][k]=max(f[i][k],g[k][j]+a[j]*i);
		}
		for(int j=i+1; j<=n; ++j)
			for(int l=max(0,j-i-2); l<=i; ++l)
				g[l-(j-i-2)][j]=
				max(g[l-(j-i-2)][j],gg[l-(j-i-2)][j]);
	}
	int ans=0;
	for(int i=0; i<=n; ++i) ans=max(ans,f[n][i]);
	printf("%d\n",ans);
	return 0;
}