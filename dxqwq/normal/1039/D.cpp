// Problem: D. You Are Given a Tree
// Contest: Codeforces - Codeforces Round #507 (Div. 1, based on Olympiad of Metropolises)
// URL: https://codeforces.com/problemset/problem/1039/D
// Memory Limit: 512 MB
// Time Limit: 7000 ms
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
vector<int> e[100003];
int fa[100003],fi[100003],se[100003],p[100003],c;
int f[100003],n=read();
void dfs(int x,int f=0)
{
	for(int y:e[x]) if(y!=f) fa[y]=x,dfs(y,x);
	p[++c]=x;
	return ;
}
int query(int x)
{
	if(~f[x]) return f[x];
	memset(fi,0,sizeof(fi)),memset(se,0,sizeof(se));
	int ans=0;
	for(int ii=1,i=p[1]; ii<=n; ++ii,i=p[ii]) 
		(fi[i]+se[i]+1>=x)?++ans:
			(fi[i]+1>fi[fa[i]]?
				(se[fa[i]]=fi[fa[i]],fi[fa[i]]=fi[i]+1):
				fi[i]+1>se[fa[i]]?se[fa[i]]=fi[i]+1:0);
	return f[x]=ans;
}
signed main()
{
	memset(f,-1,sizeof(f));
	for(int i=1,x,y; i<n; ++i) 
		x=read(),y=read(),e[x].push_back(y),e[y].push_back(x);
	dfs(1);
	for(int i=1; i<=n&&i<=1000; ++i) printf("%d\n",query(i));
	for(int i=1001,t=i,l=i+1,r=n; i<=n; i=t+1,t=i,l=i+1,r=n)
	{
		int v=query(i);
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(query(mid)==v) t=mid,l=mid+1;
			else r=mid-1;
		}
		for(int j=i; j<=t; ++j) printf("%d\n",v);
	} 
	return 0;
}