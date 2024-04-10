// Problem: F. Not Splitting
// Contest: Codeforces - Codeforces Round #766 (Div. 2)
// URL: https://codeforces.com/contest/1627/problem/F
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
int f[503][503],g[503][503];
struct qwqwq
{
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
vector<pair<int,int>> v[1000003];
int dis[1000003];
bool vis[1000003];
void add(int x,int y,int z)
{
	v[x].push_back(make_pair(y,z));
}
signed solve(int s,int t)
{
    dis[s]=0,q.push(make_pair(0,s));
    while(!q.empty())
    {
    	int x=q.top().second;
    	q.pop();
    	if(vis[x]) continue;
    	vis[x]=1;
    	for(pair<int,int> y:v[x]) 
    		if((!vis[y.first])&&dis[y.first]>dis[x]+y.second) 
    			dis[y.first]=dis[x]+y.second,
    			q.push(make_pair(dis[y.first],y.first));
    }
	return dis[t];
}
}A;
#define G(i,j) (assert(0<=i&&i<n+1),assert(0<=j&&j<n+1),((i)*(n+1)+(j)))
signed main()
{
	for(int T=read();T--;)
	{
		int sum=read(),ans=sum;
		int n=read(),m=n>>1;
		for(int i=0; i<=n+1; ++i)
			for(int j=0; j<=n+1; ++j)
				f[i][j]=0,g[i][j]=0;
		for(int TT=sum; TT--;)
		{
			int r1=read(),c1=read(),r2=read(),c2=read();
			if(r1==r2) ++f[r1][min(c1,c2)];
			else ++g[min(r1,r2)][c1];
		}
		//L->R
		for(int i=0; i<=(n+1)*(n+1)+2; ++i)	vector<pair<int,int>>().swap(A.v[i]);
		for(int i=1; i<n; ++i)
			for(int j=0; j<n; ++j)
				A.add(G(i-1,j),G(i,j),f[i][j]+f[n+1-i][n-j]),
				A.add(G(i,j),G(i-1,j),f[i][j]+f[n+1-i][n-j]);
		for(int i=0; i<n; ++i)
			for(int j=1; j<n; ++j)
				A.add(G(i,j-1),G(i,j),g[i][j]+g[n-i][n+1-j]),
				A.add(G(i,j),G(i,j-1),g[i][j]+g[n-i][n+1-j]);
		for(int i=0; i<=(n+1)*(n+1)+2; ++i) A.dis[i]=0x3f3f3f3f,A.vis[i]=0;
		printf("%d\n",sum-A.solve(G(0,0),G(m,m)));
	}
	return 0;
}