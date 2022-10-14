//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
// #define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003],ans[1000003],sz[1000003];
vector<int> e[1000003];
int dfs1(int u,int fa)
{
	sz[u]=a[u];
	for(int v:e[u]) if(v!=fa)
	{
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[v]>=2&&ans[v]) ans[u]=1;
	}
	return 0; 
}
void dfs2(int u,int fa)
{
	for(int v:e[u]) if(v!=fa)
	{
		if(ans[u] && sz[u]-sz[v]>=2) ans[v]=1;
		sz[u]-=sz[v],sz[v]+=sz[u];
		dfs2(v,u);
		sz[v]-=sz[u],sz[u]+=sz[v];
	}
}
signed main()
{
	int n=read(),s=0;
	for(int i=1; i<=n; ++i) a[i]=read();
	for(int i=1,u,v; i<n; ++i)
		u=read(),v=read(),e[u].push_back(v),e[v].push_back(u);
	for(int i=1; i<=n; ++i)
	{
		ans[i]=a[i];
		for(int j:e[i]) ans[i]|=a[j];
	}
	dfs1(1,0),dfs2(1,0);
	for(int i=1; i<=n; ++i) printf("%d ",ans[i]);
}