// Problem: F. Connectivity Addicts
// Contest: Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/F
// Memory Limit: 512 MB
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
bool vis[1003];
int a[1003],fa[1003];
int find(int x)
{
	return x==fa[x]?x:(fa[x]=find(fa[x]));
}
int query(int x)
{
	printf("? %d\n",x);fflush(stdout);
	return read();
}
signed main()
{
	a[0]=-1;
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) a[i]=read(),vis[i]=0,fa[i]=i;
		int s=n;
		while(s)
		{
			int x=0;
			for(int i=1; i<=n; ++i) if(!vis[i])
			{
				if(a[i]>a[x]) x=i;
			}
			--s,vis[x]=1;
			while(a[x]--)
			{
				int y=query(x);
				int fy=find(y);
				if(vis[y])
				{
					fa[x]=fy;
					break;
				}
				else
				{
					vis[y]=1,--s;
					fa[fy]=x;
				}
			}
		}
		printf("! ");
		for(int i=1; i<=n; ++i) printf("%d ",find(i));
		puts("");fflush(stdout);
	}
	return 0;
}