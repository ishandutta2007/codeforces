// Problem: D. Tavas in Kansas
// Contest: Codeforces - Codeforces Round #299 (Div. 1)
// URL: https://codeforces.com/problemset/problem/536/D
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
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
vector<pair<int,int> > v[2003];
int dis[2003],lsh[2003],val[2003],ds[2003],dt[2003];
int a[2003][2003],b[2003][2003],f[2003][2003],g[2003][2003];
bool vis[2003];
int n=read(),m=read();
void sssp(int *f,int s)
{
	memset(dis,0x3f,sizeof(dis)),memset(vis,0,sizeof(vis)),
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
    for(int i=1; i<=n; ++i) lsh[i]=dis[i];
    sort(lsh+1,lsh+n+1);
    for(int i=1; i<=n; ++i) f[i]=lower_bound(lsh+1,lsh+n+1,dis[i])-lsh;
	return ;
}
int qa(int l1,int r1,int l2,int r2){return a[r1][r2]-a[r1][l2-1]-a[l1-1][r2]+a[l1-1][l2-1];}
int qb(int l1,int r1,int l2,int r2){return b[r1][r2]-b[r1][l2-1]-b[l1-1][r2]+b[l1-1][l2-1];}
signed main()
{
    int s=read(),t=read();
    for(int i=1; i<=n; ++i) val[i]=read();
    memset(dis,0x3f,sizeof(dis));
    for(int i=1,x,y,z; i<=m; i++) 
    	x=read(),y=read(),z=read(),
    	v[x].push_back(make_pair(y,z)),
    	v[y].push_back(make_pair(x,z));
	sssp(ds,s),sssp(dt,t);
	for(int i=1; i<=n; ++i)
		// printf("%lld %lld\n",ds[i],dt[i]),
		a[ds[i]][dt[i]]+=val[i],++b[ds[i]][dt[i]];
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			a[i][j]+=a[i-1][j];
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			a[i][j]+=a[i][j-1];
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			b[i][j]+=b[i-1][j];
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			b[i][j]+=b[i][j-1];
	for(int i=n-1; i>=0; --i)
		for(int j=n-1; j>=0; --j)
			if(!qb(i+1,n,j+1,n)) f[i][j]=g[i][j]=0;
			else 
				f[i][j]=qb(i+1,i+1,j+1,n)?(max(f[i+1][j],-g[i+1][j])+qa(i+1,i+1,j+1,n)):f[i+1][j],
				g[i][j]=qb(i+1,n,j+1,j+1)?(max(g[i][j+1],-f[i][j+1])+qa(i+1,n,j+1,j+1)):g[i][j+1];
	// printf("%lld\n",f[0][0]);
	// for(int i=0; i<=n; ++i,puts(""))
		// for(int j=0; j<=n; ++j)
			// printf("%lld ",a[i][j]);
	if(f[0][0]>0) puts("Break a heart");
	else if(f[0][0]==0) puts("Flowers");
	else puts("Cry");
	return 0;
}