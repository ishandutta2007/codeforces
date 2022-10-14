// Problem: B. Destruction of a Tree
// Contest: Codeforces - Tinkoff Internship Warmup Round 2018 and Codeforces Round #475 (Div. 1)
// URL: https://codeforces.com/contest/963/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
vector<int> e[1000003];
int sz[1000003],S[1000003];
bool vis[1000003];
void dfs(int x,int fa=0)
{
	for(int y:e[x]) if(y!=fa)
	{
		if(sz[y]&1);
		else dfs(y,x);
	}
	vis[x]=1;
	printf("%d\n",x);
	for(int y:e[x]) if(y!=fa&&!vis[y]) --S[y],dfs(y,x);
	return ;
}
void init(int x,int fa=0)
{
	sz[x]=1;
	for(int y:e[x]) if(y!=fa) init(y,x),sz[x]+=sz[y];
	return ;
}
signed main()
{
	int n=read();
	if((n+1)&1) puts("NO"),exit(0);
	for(int i=1,x; i<=n; ++i)
		if((x=read()))
			e[i].push_back(x),
			e[x].push_back(i);
	for(int i=1; i<=n; ++i) S[i]=e[i].size();
	init(1);
	puts("YES"),dfs(1);
	return 0;
}