// Problem: D. Jongmah
// Contest: Codeforces - Codeforces Global Round 1
// URL: https://codeforces.com/problemset/problem/1110/D
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
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int f[1000003][7][7],a[1000003];
signed main()
{
	int n=read(),m=read(),t=0;
	while(n--) ++a[read()];
	memset(f,0xc0,sizeof(f));
	f[0][0][0]=0;
	for(int i=1; i<=m; ++i)
		for(int j=0; j<7; ++j)
			for(int k=0; k<7; ++k)
				for(int l=0; l<7&&l<=a[i]; ++l)
					f[i][k-min(l,min(j,k))][l-min(l,min(j,k))]
					=max(f[i][k-min(l,min(j,k))][l-min(l,min(j,k))],
					f[i-1][j][k]+min(l,min(j,k))+(a[i]-l)/3);
	int ans=0;
	for(int i=0; i<7; ++i)
		for(int j=0; j<7; ++j)
			ans=max(ans,f[m][i][j]);
	printf("%d\n",ans);
	return 0;
}