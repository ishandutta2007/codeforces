// Problem: A. The Two Routes
// Contest: Codeforces Round #333 (Div. 1)
// URL: https://codeforces.com/contest/601/problem/A
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int f[403][403];
int d0[403],d1[403];
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=m; ++i)
	{
		int x=read(),y=read();
		f[x][y]=f[y][x]=1;
	}
	queue<int> q;
	memset(d0,0x3f,sizeof(d0));
	memset(d1,0x3f,sizeof(d1));
	q.push(1),d0[1]=d1[1]=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=1; i<=n; ++i) if(f[x][i]&&d0[i]>n)
			d0[i]=d0[x]+1,q.push(i);
	}
	q.push(1);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=1; i<=n; ++i) if(!f[x][i]&&d1[i]>n)
			d1[i]=d1[x]+1,q.push(i);
	}
	if(d0[n]>n||d1[n]>n) puts("-1");
	else printf("%d\n",max(d0[n],d1[n]));
	return 0;
}