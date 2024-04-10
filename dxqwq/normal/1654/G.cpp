// Problem: G. Snowy Mountain
// Contest: Codeforces - Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round)
// URL: https://codeforces.com/problemset/problem/1654/G
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
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
set<int> s[200003];
int d[200003],f[200003],dis[200003];
int lst[200003],pos[200003],cnt;
void dfs1(int x,int fa)
{
	pos[++cnt]=x,lst[cnt]=fa;
	for(int y:e[x]) if(y!=fa) 
		dfs1(y,x),(d[x]>d[y]+1)&&(d[x]=d[y]+1);
}
void dfs2(int x,int fa)
{
	for(int y:e[x]) if(y!=fa)
		(d[y]>d[x]+1)&&(d[y]=d[x]+1),dfs2(y,x);
}
void dfs3(int x,int fa)
{
	for(int y:e[x]) if(y!=fa) 
	{
		dfs3(y,x);
		if(d[x]>d[y]) dis[x]=max(dis[x],min(0,dis[y]+1));
		if(d[x]==d[y]) dis[x]=max(dis[x],dis[y]-1);
	}
}
void dfs4(int x,int fa)
{
	for(int y:e[x]) if(y!=fa)
	{
		if(d[y]>d[x]) dis[y]=max(dis[y],min(0,dis[x]+1));
		if(d[y]==d[x]) dis[y]=max(dis[y],dis[x]-1);
		dfs4(y,x);
	}
}
signed main()
{
	int n=read();
	memset(d,0x3f,sizeof(d));
	for(int i=1; i<=n; ++i) if(read()) d[i]=0;
	for(int i=1,u,v; i<n; ++i)
		u=read(),v=read(),
		e[u].push_back(v),e[v].push_back(u);
	dfs1(1,1),dfs2(1,1);
	for(int i=1; i<=n; ++i) f[i]=d[i];
	for(int i=1; i<=n; ++i)
	{
		bool f=0;
		for(int j:e[i]) if(d[i]==d[j]) f=1;
		if(f) s[d[i]].insert(i);
	}
	for(int i=0; i<=n; ++i) if(!s[i].empty())
	{
		memset(dis,0xc0,sizeof(dis));
		for(int j:s[i]) dis[j]=0;
		for(int j=n; j>1; --j)
			(dis[pos[j]]>0)&&(dis[pos[j]]=0),
			(d[lst[j]]>d[pos[j]]&&dis[lst[j]]<dis[pos[j]]+1)&&(dis[lst[j]]=dis[pos[j]]+1),
			(d[lst[j]]==d[pos[j]]&&dis[lst[j]]<dis[pos[j]]-1)&&(dis[lst[j]]=dis[pos[j]]-1);
		(dis[pos[1]]>0)&&(dis[pos[1]]=0);
		for(int j=2; j<=n; ++j)
			(d[lst[j]]<d[pos[j]]&&dis[lst[j]]+1>dis[pos[j]])&&(dis[pos[j]]=dis[lst[j]]+1),
			(d[lst[j]]==d[pos[j]]&&dis[lst[j]]-1>dis[pos[j]])&&(dis[pos[j]]=dis[lst[j]]-1),
			(dis[pos[j]]>0)&&(dis[pos[j]]=0);
		for(int j=1; j<=n; ++j) 
			(f[j]>i&&dis[j]==0)&&(f[j]=i);
	}
	for(int i=1; i<=n; ++i) printf("%d ",(d[i]<<1)-f[i]);
	return 0;
}