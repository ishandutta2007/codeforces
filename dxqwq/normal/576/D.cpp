// Problem: D. Flights for Regular Customers
// Contest: Codeforces - Codeforces Round #319 (Div. 1)
// URL: https://codeforces.com/problemset/problem/576/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
struct node
{
	int x,y,t;
	bool operator<(const node&o)const{return t<o.t;}
}e[153];
bitset<153> F[153],A[153],B[153],T[153],S,tS;
int dis[153];
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=m; ++i) e[i].x=read(),e[i].y=read(),e[i].t=read();
	sort(e+1,e+m+1),S[1]=1;
	if(e[1].t) puts("Impossible"),exit(0);
	int ans=0x3f3f3f3f;
	for(int i=1; i<=m; ++i)
	{
		for(int j=1; j<=n; ++j) A[j]=F[j];
		for(int j=1; j<=n; ++j) B[j].reset(),B[j][j]=1;
		for(int j=e[i].t-e[i-1].t; j;)
		{
			if(j&1)
			{
				for(int x=1; x<=n; ++x)
					T[x].reset();
				for(int x=1; x<=n; ++x)
					for(int y=1; y<=n; ++y) if(B[x][y])
						T[x]|=A[y];
				for(int x=1; x<=n; ++x) B[x]=T[x];
			}
			j>>=1;
			for(int x=1; x<=n; ++x)
				T[x].reset();
			for(int x=1; x<=n; ++x)
				for(int y=1; y<=n; ++y) if(A[x][y])
					T[x]|=A[y];
			for(int x=1; x<=n; ++x) A[x]=T[x];
		} 
		tS.reset();
		for(int j=1; j<=n; ++j) if(S[j]) tS|=B[j];
		S=tS,F[e[i].x][e[i].y]=1;
		// for(int j=1; j<=n; ++j) printf("%d",(int)S[j]);
		// puts("");
		queue<int> q;
		memset(dis,0x3f,sizeof(dis));
		for(int j=1; j<=n; ++j) if(S[j]) dis[j]=0,q.push(j);
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			for(int j=1; j<=n; ++j) if(F[x][j]&&dis[j]==0x3f3f3f3f)
				dis[j]=dis[x]+1,q.push(j);
		}
		ans=min(ans,e[i].t+dis[n]);
	}
	if(ans==0x3f3f3f3f) puts("Impossible");
	else printf("%d\n",ans);
	return 0;
}