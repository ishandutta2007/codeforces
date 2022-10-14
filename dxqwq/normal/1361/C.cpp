// Problem: C. Johnny and Megan's Necklace
// Contest: Codeforces Round #647 (Div. 1) - Thanks, Algo Muse!
// URL: https://codeforces.com/contest/1361/problem/C
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
#define fi first
#define se second
#define mp make_pair
int a_[1100003],b_[1100003];
int a[1100003],b[1100003];
int ans[1100003];
int cur[1100003],head[1100003],nxt[2200003],to[2200003];
bool vis[1100003];
int ansi[1100003],ansu[1100003],ansv[1100003];
int idx,cnt;
int deg[1100003];
void dfs(int x)
{
	for(int&I=cur[x]; I; I=nxt[I])
	{
		int i=I;
		if(vis[i>>1]) continue;
		--deg[x],--deg[to[i]],
		vis[i>>1]=1,dfs(to[i]);
		++idx,ansi[idx]=i,ansu[idx]=to[i],ansv[idx]=x;
	}
	return ;
}
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i) a_[i]=read(),b_[i]=read();
	for(int i=1; i<=n*2; ++i) ans[i]=i;
	for(int T=1,B=1; T<=20; ++T,B=(B<<1)|1)
	{
		for(int i=1; i<=n; ++i) a[i]=a_[i]&B,b[i]=b_[i]&B;
		for(int i=0; i<=B; ++i) head[i]=deg[i]=0;
		cnt=1,idx=0;
		int qwq=0;
		for(int i=1; i<=n; ++i) 
			vis[i]=0,
			++deg[a[i]],++deg[b[i]],
			to[++cnt]=b[i],nxt[cnt]=head[a[i]],head[a[i]]=cnt,
			to[++cnt]=a[i],nxt[cnt]=head[b[i]],head[b[i]]=cnt;
		for(int i=0; i<=B; ++i) cur[i]=head[i];
		bool flg=1;
		for(int i=0; i<=B; ++i) if(deg[i]&1) flg=0;
		if(flg) for(int i=0; i<=B; ++i) if(deg[i])
			dfs(i),++qwq;
		if(qwq!=1) flg=0;
		if(!flg)
		{
			printf("%d\n",T-1);
			for(int i=1; i<=n*2; ++i)
			 printf("%d ",ans[i]);
			return 0; 
		}
		int OVO=0;
		for(int ii=1,i=ansi[1]>>1; ii<=n; ++ii,i=ansi[ii]>>1) 
		if(ansu[ii]==a[i])
			ans[++OVO]=(i-1)*2+1,ans[++OVO]=(i-1)*2+2;
		else ans[++OVO]=(i-1)*2+2,ans[++OVO]=(i-1)*2+1;
		for(int i=0; i<=B; ++i) deg[i]=0;
	}
			puts("20");
			for(int i=1; i<=n*2; ++i)
			 printf("%d ",ans[i]);
			return 0; 
	return 0;
}