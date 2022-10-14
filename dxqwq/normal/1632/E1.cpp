// Problem: E2. Distance Tree (hard version)
// Contest: Codeforces - Codeforces Round #769 (Div. 2)
// URL: https://codeforces.com/contest/1632/problem/E2
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
int dep[1000003],mx[1000003],ans[1000003];
int in[1000003],out[1000003],cnt;
int val[1000003],pre[1000003],suf[1000003];
vector<int> e[1000003];
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	in[x]=++cnt,val[cnt]=dep[x];
	for(int y:e[x]) if(y!=fa) dfs(y,x);
	out[x]=cnt;
	return ;
}
int f[1000003],ff[1000003];
void dfs2(int x,int fa)
{
	for(int y:e[x]) if(y!=fa) 
	{
		dfs2(y,x);
		ans[x]=max(ans[x],mx[x]+mx[y]+1);
		ans[x]=max(ans[x],ans[y]);
		mx[x]=max(mx[x],mx[y]+1);
	}
	int g=(ans[x]+1)>>1,gg=max(pre[in[x]-1],suf[out[x]+1]);
	if(g>=gg)
	{
		f[1]=min(f[1],g);
	}
	else
	{
		ff[gg-g]=min(ff[gg-g],gg);
		f[gg-g]=min(f[gg-g],g);
	}
	//ans=max(g+q,max(pre[in[x]-1],suf[out[x]+1]))
	return ;
}
signed main()
{
	dep[0]=-1;
	for(int T=read();T--;)
	{
		int n=read();
		cnt=0;
		for(int i=1; i<=n; ++i) e[i].clear(),mx[i]=0,ans[i]=0,f[i]=ff[i]=1e9;
		for(int i=1; i<n; ++i)
		{
			int x=read(),y=read();
			e[x].push_back(y),e[y].push_back(x);
		}
		dfs(1,0);
		pre[0]=0,suf[n+1]=0;
		pre[1]=val[1],suf[n]=val[n];
		for(int i=2; i<=n; ++i) pre[i]=max(pre[i-1],val[i]);
		for(int i=n-1; i>=1; --i) suf[i]=max(suf[i+1],val[i]);
		dfs2(1,0);
		for(int i=n-1; i>=1; --i) ff[i]=min(ff[i],ff[i+1]);
		for(int i=2; i<=n; ++i) f[i]=min(f[i],f[i-1]);
		for(int i=1; i<=n; ++i) printf("%d ",min(min(f[i]+i,ff[i]),pre[n]));
		puts("");
	}
	return 0;
}