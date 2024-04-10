// Problem: F. Ehab and the Big Finale
// Contest: Codeforces - Codeforces Round #563 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1174/F
// Memory Limit: 256 MB
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
vector<int> e[200003];
int fa[200003],dep[200003],sz[200003],hs[200003],lst[200003];
int query(int x)
{
	printf("d %d\n",x),fflush(stdout);
	return read();
}
int qnxt(int x)
{
	printf("s %d\n",x),fflush(stdout);
	return read();
}
int LCA(int d,int x)
{
	int D=(dep[x]+d-query(x))>>1;
	if(dep[x]==D) printf("! %d\n",x),exit(0);
	while(dep[x]>D) x=fa[x];
	return x;
}
int n=read(),D;
void dfs(int x)
{
	sz[x]=1,lst[x]=x;
	if(dep[x]==D) return ;
	for(int y:e[x]) 
		if(y!=fa[x])
		{
			fa[y]=x,dep[y]=dep[x]+1,
			dfs(y),sz[x]+=sz[y];
			if(sz[y]>sz[hs[x]])
				hs[x]=y,lst[x]=lst[y];
		}
	return ;
}
signed main()
{
	int x=1;
	for(int i=1,u,v; i<n; ++i)
		u=read(),v=read(),
		e[u].push_back(v),
		e[v].push_back(u);
	D=query(1),dfs(1);
	while(dep[x]!=D)
		x=qnxt(LCA(D,lst[x]));
	printf("! %d\n",x);
	return 0;
}