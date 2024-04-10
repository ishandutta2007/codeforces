// Problem: G. Monsters and Potions
// Contest: Codeforces - 2018-2019 ICPC, NEERC, Southern Subregional Contest (Online Mirror, ACM-ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/contest/1070/problem/G
// Memory Limit: 256 MB
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
bool vis[103];
int nxt[103];
int h[103],a[103];
bool f[103];
int id[103];
void dfs(int x)
{
	if(x==-1) return ;
	dfs(nxt[x]);
	printf("%d ",id[x]),vis[x]=0;
	return ;
}
signed main()
{
	int n=read(),m=read();
	int fir=n+1,lst=0,ava=0;
	for(int i=1; i<=m; ++i)
	{
		int x=read();
		vis[x]=1,h[x]=read(),id[x]=++ava;
		if(x<fir) fir=x;
		if(x>lst) lst=x;
	}
	for(int i=1; i<=n; ++i) a[i]=read();
	for(int i=1; i<=n+1; ++i) 
	{
		memset(f,0,sizeof(f));
		bool f1=0,f2=0;
		for(int j=i-1; j>=1; --j) if(vis[j])
		for(int k=j,cur=h[j]; k<=i-1; ++k)
		{
			cur+=a[k];
			if(cur<0) break;
			if(k==i-1) {f[j]=1,nxt[j]=-1;break;}
			else if(f[k]) {f[j]=1,nxt[j]=k;break;}
		}
		for(int j=i; j<=n; ++j) if(vis[j])
		for(int k=j,cur=h[j]; k>=i; --k)
		{
			cur+=a[k];
			if(cur<0) break;
			if(k==i) {f[j]=1,nxt[j]=-1;break;}
			else if(f[k]) {f[j]=1,nxt[j]=k;break;}
		}
		if(fir<i) f1=f[fir]; else f1=1;
		if(lst>=i) f2=f[lst]; else f2=1;
		if(f1&&f2)
		{
			printf("%d\n",min(n,i));
			if(lst>=i) dfs(lst);
			if(fir<i) dfs(fir);
			for(int i=1; i<=n; ++i) if(vis[i]) printf("%d ",id[i]);
			puts("");
			return 0;
		}
	}
	puts("-1");
	return 0;
}