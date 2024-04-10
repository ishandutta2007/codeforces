// Problem: E. Moment of Bloom
// Contest: Codeforces - Codeforces Round #749 (Div. 1 + Div. 2, based on Technocup 2022 Elimination Round 1)
// URL: https://codeforces.com/contest/1586/problem/E
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
vector<int> e[300003];
int fa[300003],d[300003];
bool vis[300003];
void dfs(int x,int f=0)
{
	vis[x]=1;
	d[x]=d[f]+1,fa[x]=f;
	for(auto y:e[x]) 
		if(!vis[y]) dfs(y,x);
}
vector<int> ans[300003];
int t[300003];
int a[300003];
int res=0;
void dfs1(int x,int t)
{
	for(auto y:e[x]) if(fa[y]==x) if(a[y])
	{++t;dfs1(y,0);}
	else dfs1(y,1);
	res+=t>>1;
	return ;
}
signed main()
{
	int n=read(),m=read();
	for(;m--;)
	{
		int u=read(),v=read();
		//U[i]=u,V[i]=v;
		e[u].push_back(v),e[v].push_back(u);
	}	
	dfs(1);
	int Q=read(),OVO=0;
	for(int T=Q;T--;)
	{
		int ind=++OVO;
		int u=read(),v=read();
		vector<int> t;
		while(d[u]>d[v])
		{
			a[u]^=1;ans[ind].push_back(u);
			u=fa[u];
		}
		while(d[u]<d[v])
		{
			a[v]^=1;t.push_back(v);
			v=fa[v];
		}
		while(u!=v)
		{
			ans[ind].push_back(u);t.push_back(v);
			a[u]^=1;
			u=fa[u];
			a[v]^=1;
			v=fa[v];
		}
		ans[ind].push_back(u);
		while(!t.empty()) ans[ind].push_back(t.back()),t.pop_back();
	}
	for(int i=1; i<=n; ++i) if(a[i])
	{
		puts("NO");
		dfs1(1,1);
		printf("%d\n",res);
		return 0;
	}
	puts("YES");
	for(int i=1; i<=Q; ++i)
	{
		printf("%d\n",(int)ans[i].size());
		for(auto j:ans[i]) printf("%d ",j);
		puts("");
	}
	return 0;
}