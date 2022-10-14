// Problem: I. Mashtali vs AtCoder
// Contest: Codeforces
// URL: https://codeforces.com/contest/1610/problem/I
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
vector<int> e[1000003];
int a[1000003],f[1000003];
int lim;
void dfs(int x,int fa=0)
{
	a[x]=0,f[x]=fa;
	for(int y:e[x]) if(y!=fa)
		dfs(y,x),a[x]^=(a[y]+1);
	return ;
}
bool vis[1000003],qwq[1000003];
signed main()
{
	int n=read();
	for(int i=1; i<n; ++i)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1);
	int s=a[1],ss=0;
	for(int i:e[1]) qwq[i]=1;
	// for(int i=1; i<=n; ++i) if(qwq[i]) printf("(%d)",i);
	// puts("");
	vis[1]=1,putchar(49+(s==0));
	for(int i=2; i<=n; ++i)
	{
		int t=i;
		while(!vis[t])
		{
			++ss,vis[t]=1;
			if(qwq[t]) s^=a[t]+1,qwq[t]=0;
			for(int y:e[t]) if(y!=f[t]&&!vis[y]&&!qwq[y])
				qwq[y]=1,s^=a[y]+1; 
			t=f[t];
		}
		// for(int i=1; i<=n; ++i) if(qwq[i]) printf("(%d)",i);
		// puts("");
		putchar(49+((s^(ss&1))==0));
	}
	return 0;
}