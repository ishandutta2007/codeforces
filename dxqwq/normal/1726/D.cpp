// Problem: D. Edge Split
// Contest: Codeforces Round #819 (Div. 1 + Div. 2) and Grimoire of Code Annual Contest 2022
// URL: https://codeforces.com/contest/1726/problem/D
// Memory Limit: 256 MB
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
pair<int,int> E[300003];
int c=0;
vector<pair<int,int>> e[300003],G;
bool f[300003],vis[300003];
int dfn[300003];
int fat[300003],dep[300003];
void dfs(int x,int fa=0)
{
	vis[x]=1,dfn[x]=++c;
	for(auto [y,z]:e[x]) if(y!=fa)
	{
		if(!vis[y]) dep[y]=dep[x]+1,fat[y]=x,dfs(y,x);
		else if(dfn[y]>dfn[x]) 
			// printf("%d %d\n",x,y),
			f[z]=1,G.push_back(E[z]);
	}
}
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();c=0;
		G.clear();
		for(int i=1; i<=n; ++i) e[i].clear(),vis[i]=0;
		for(int i=1; i<=m; ++i) f[i]=0;
		for(int i=1; i<=m; ++i)
		{
			int x=read(),y=read();
			if(x>y) swap(x,y);
			E[i]=make_pair(x,y);
			e[x].push_back(make_pair(y,i));
			e[y].push_back(make_pair(x,i));
		}
		dfs(1);
		// printf("%d\n",(int)G.size());
		if(G.size()==3)
		{
			map<int,int> mp;
			for(auto [x,y]:G) ++mp[x],++mp[y];
			bool qwq=1;
			for(auto [x,y]:mp) if(y!=2) qwq=0;
			
			if(qwq)
			{
				// puts("moving");
				int A=G[0].first;
				if(dep[G[0].second]>dep[A])
					A=G[0].second;
				vis[A]=0;
				for(int i=1; i<=m; ++i) 
					if(E[i]==G[0]) f[i]=0;
				// printf("%d %d\n",G[0].first,G[0].second);
				pair<int,int> 
				Z=make_pair(min(A,fat[A]),
				max(A,fat[A]));
				// printf("%d %d\n",Z.first,Z.second);
				for(int i=1; i<=m; ++i)
					if(E[i]==Z) f[i]=1;
			}
		}
		for(int i=1; i<=m; ++i) putchar(48+f[i]);
		puts("");
	}
	return 0;
}