// Problem: CF1129A2 Toy Train
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1129A2
// Memory Limit: 250 MB
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
vector<int> v[5003];
int f[5003],g[5003];
signed main()
{
	int n=read(),m=read();
	memset(g,0x3f,sizeof(g));
	for(int i=1,x,y; i<=m; ++i)
	{
		x=read()-1,y=read()-1,y=(y-x+n)%n;
		if(y) ++f[x],g[x]=min(g[x],y);
	}
	for(int i=0; i<n; ++i)
	{
		int ans=0;
		for(int j=0; j<n; ++j) if(f[(i+j)%n])
			ans=max(ans,j+(f[(i+j)%n]-1)*n+g[(i+j)%n]);
		printf("%lld ",ans);
	}
	return 0;
}