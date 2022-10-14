// Problem: A. Johnny and Contribution
// Contest: Codeforces Round #647 (Div. 1) - Thanks, Algo Muse!
// URL: https://codeforces.com/contest/1361/problem/A
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
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
pair<int,int> t[1000003];
vector<int> e[1000003];
bool vis[1000003];
int a[1000003];
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=m; ++i)
	{
		int u=read(),v=read();
		e[u].push_back(v),
		e[v].push_back(u);
	}
	for(int i=1; i<=n; ++i) t[i]=make_pair(read(),i);
	sort(t+1,t+n+1);
	for(int i=1; i<=n; ++i) a[i]=1000000;
	for(int ii=1; ii<=n; ++ii)
	{
		int i=t[ii].second;
		for(int j:e[i])
			vis[a[j]]=1;
		int X=1;
		while(vis[X]) ++X;
		if(X!=t[ii].first) puts("-1"),exit(0);
		a[i]=X;
		for(int j:e[i])
			vis[a[j]]=0;	
	}
	for(int i=1; i<=n; ++i) printf("%d ",t[i].second);
	return 0;
}