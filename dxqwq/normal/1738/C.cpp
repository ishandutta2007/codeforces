// Problem: C. Even Number Addicts
// Contest: Codeforces - Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
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
int f[2][2][103][103];
int dfs(int x,int y,int z,int w)
{
	if(f[x][y][z][w]!=-1) return f[x][y][z][w];
	if(z==0&&w==0) return (x==0);
	int ans=0;
	if(y==0)
	{
		if(z>0) ans=max(ans,dfs(x^1,y^1,z-1,w));
		if(w>0) ans=max(ans,dfs(x,y^1,z,w-1));
	}
	else
	{
		ans=1;
		if(z>0) ans=min(ans,dfs(x,y^1,z-1,w));
		if(w>0) ans=min(ans,dfs(x,y^1,z,w-1));
	}
	// printf("%d %d %d %d %d\n",x,y,z,w,ans);
	return f[x][y][z][w]=ans;
}
signed main()
{
	memset(f,-1,sizeof(f));
	for(int T=read();T--;)
	{
		int n=read(),A=0,B=0;
		for(int i=1; i<=n; ++i) if(read()&1) ++A;
		else ++B;
		if(dfs(0,0,A,B)) puts("Alice");
		else puts("Bob");
	}
	return 0;
}