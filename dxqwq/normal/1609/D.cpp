// Problem: D. Social Network
// Contest: Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1609/problem/D
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
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int fa[1000003],a[1000003],sz[1000003];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; ++i) a[i]=1,sz[i]=1,fa[i]=i;
	int s=0;
	for(int i=1; i<=m; ++i)
	{
		int x=read(),y=read();
		x=find(x),y=find(y);
		if(x!=y) 
		{
			fa[x]=y,sz[y]+=sz[x],sz[x]=0;
		}
		else
		{
			++s;
		}
		for(int i=1; i<=n; ++i) a[i]=sz[i];
		sort(a+1,a+n+1);
		int ans=0;
		for(int i=n; i>=n-s; --i) ans+=a[i];
		printf("%lld\n",ans-1);
	}
	return 0;
}