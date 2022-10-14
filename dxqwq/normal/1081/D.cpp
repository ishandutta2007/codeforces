// Problem: D. Maximum Distance
// Contest: Codeforces - Avito Cool Challenge 2018
// URL: https://codeforces.com/contest/1081/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int fa[1000003];
struct node
{
	int u,v,w;
	bool operator<(const node&x){return w<x.w;}
}a[1000003];
int sz[1000003];
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int ans[1000003];
signed main()
{
    int n=read(),m=read(),k=read();
    for(int i=1; i<=k; i++) sz[read()]=1;
    for(int i=1; i<=m; i++) a[i].u=read(),a[i].v=read(),a[i].w=read();
    sort(a+1,a+m+1);
    for(int i=1; i<=n; i++) fa[i]=i;
    for(int i=1; i<=m; i++)
    {
    	int u=find(a[i].u),v=find(a[i].v);
    	if(u!=v) {fa[u]=v,sz[v]+=sz[u];
    	if(sz[v]==k)
    	{
    		for(int j=1; j<=k; j++) printf("%d ",a[i].w);
    		puts("");
    		return 0;
    	}}
    }
	return 0;
}