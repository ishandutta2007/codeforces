// Problem: F. Diameter Cuts
// Contest: Codeforces - Educational Codeforces Round 106 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1499/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const int p=998244353;
vector<int> e[5003];
int n=read(),m=read();
int f[5003][5003],tf[5003],sz[5003];
void dfs(int x,int fa=0)
{
	sz[x]=1,f[x][0]=1;
	for(int y:e[x]) if(y!=fa)
	{
		dfs(y,x);
		memset(tf,0,(sz[x]+sz[y]+1)<<2);
		for(int j=0; j<=sz[x]&&j<=m; ++j)
			for(int k=0; k<=sz[y]&&k<=m; ++k)
				tf[j]=(1ll*f[x][j]*f[y][k]+tf[j])%p;
		for(int j=0; j<=sz[x]&&j<=m; ++j)
			for(int k=0; k<=sz[y]&&j+k+1<=m; ++k)
				tf[max(j,k+1)]=(1ll*f[x][j]*+f[y][k]+tf[max(j,k+1)])%p;
		memcpy(f[x],tf,(sz[x]+sz[y]+1)<<2),sz[x]+=sz[y];
	}
	return ;
}
signed main()
{
	for(int i=1,x,y; i<n; ++i) 
		x=read(),y=read(),e[x].push_back(y),e[y].push_back(x);
	dfs(1);
	int ans=0;
	for(int i=0; i<=m; ++i) ans=(ans+f[1][i])%p;
	printf("%d\n",ans);
	return 0;
}