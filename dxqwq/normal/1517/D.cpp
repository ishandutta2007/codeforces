// Problem: D. Explorer Space
// Contest: Codeforces - Contest 2050 and Codeforces Round #718 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1517/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    return s*w;
}
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
vector<pair<int,int> > v[1000003];
int dis[1000003];
bool vis[1000003];
signed dijkstra(int s)
{
    // int n=read(),m=read(),s=read();
    memset(dis,0x3f,sizeof(dis));
    // for(int i=1,x,y,z; i<=m; i++) 
    	// x=read(),y=read(),z=read(),
    	// v[x].push_back(make_pair(y,z));
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
    // for(int i=1; i<=n; ++i) 
    	// if(dis[i]>1e12) printf("%d ",0x7fffffff);
    	// else printf("%lld ",dis[i]);
	return 0;
}
int a[503][503],b[503][503];
int dp[11][503][503];
signed main()
{
    int n=read(),m=read(),k=read();
    if(k&1)
    {
    	for(int i=1; i<=n; ++i,puts(""))
    	for(int j=1; j<=m; ++j) printf("-1 ");
    	return 0;
    }
    k>>=1;
    for(int i=1; i<=n; ++i)
    for(int j=1; j<m; ++j) a[i][j]=read();
    for(int i=1; i<n; ++i)
    for(int j=1; j<=m; ++j) b[i][j]=read(); 
    for(int I=1; I<=k; ++I)
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j)
    {
    dp[I][i][j]=0x3f3f3f3f3f3f3f3f;
    if(j>1)
    dp[I][i][j]=min(dp[I][i][j],dp[I-1][i][j-1]+a[i][j-1]);
    if(j<m)
    dp[I][i][j]=min(dp[I][i][j],dp[I-1][i][j+1]+a[i][j]);
    if(i>1)
    dp[I][i][j]=min(dp[I][i][j],dp[I-1][i-1][j]+b[i-1][j]);
    if(i<n)
    dp[I][i][j]=min(dp[I][i][j],dp[I-1][i+1][j]+b[i][j]);
    }
    for(int i=1; i<=n; ++i,puts(""))
    for(int j=1; j<=m; ++j)
    printf("%lld ",dp[k][i][j]*2);
	return 0;
}