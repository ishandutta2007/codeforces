// Problem: D. Limak and Shooting Points
// Contest: Codeforces - Codeforces Round #363 (Div. 1)
// URL: https://codeforces.com/problemset/problem/698/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
struct node{int x,y;}a[13],b[1003];
int p[13],q[13],ans;
bool vis[1003],flg[1003];
vector<int> e[13][1003];
signed main()
{
	int m=read(),n=read();
	for(int i=1; i<=m; ++i) p[i]=i;
	for(int i=1; i<=m; ++i) a[i].x=read(),a[i].y=read();
	for(int i=1; i<=n; ++i) b[i].x=read(),b[i].y=read();
	for(int i=1; i<=m; ++i)
		for(int j=1; j<=n; ++j)
			for(int k=1; k<=n; ++k)
				if((b[k].x-a[i].x)*(b[j].x-a[i].x)>=0
				 &&(b[k].y-a[i].y)*(b[j].y-a[i].y)>=0
				 &&(b[k].x-a[i].x)*(b[j].y-a[i].y)
				 ==(b[j].x-a[i].x)*(b[k].y-a[i].y)
				 &&abs(b[k].x-a[i].x)+abs(b[k].y-a[i].y)
				  <abs(b[j].x-a[i].x)+abs(b[j].y-a[i].y))
					e[i][j].push_back(k);
	do
	{
		for(int i=1,cnt=1; i<=n; ++i,cnt=1) if(!flg[i])
		{
			q[1]=i,vis[i]=1;
			for(int j=1; cnt<=m&&j<=cnt; ++j)
				for(int k:e[p[j]][q[j]])
					(cnt<=m&&!vis[k])
					&&(vis[k]=1,q[++cnt]=k,0);
			for(int j=1; j<=cnt; ++j) vis[q[j]]=0;
			if(cnt<=m) ans+=(flg[i]=1);
		}
	}
	while(next_permutation(p+1,p+m+1));
	printf("%lld\n",ans);
	return 0;
}