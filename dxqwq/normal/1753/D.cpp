// Problem: D. The Beach
// Contest: Codeforces Round #829 (Div. 1)
// URL: https://codeforces.com/contest/1753/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
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
vector<pair<int,int> > v[500003];
int dis[500003];
bool vis[500003];
void add(int x,int y,int z)
{
	v[x].push_back(make_pair(y,z));
}
void sssp(int s)
{
    memset(dis,0x3f,sizeof(dis));
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
	return ;
}
int n=read(),m=read(),A=read(),B=read();
vector<char> s[300003];
char str[1000003];
int F(int x,int y){assert(1<=x&&x<=n); assert(1<=y&&y<=m);
return (x-1)*m+y;}
void qwq(int i,int j)
{
	if(s[i][j-1]!='#'&&s[i-1][j]!='#')
	{
		if(s[i-1][j]=='.') add(F(i,j-1),F(i-1,j),A);
		if(s[i][j-1]=='.') add(F(i-1,j),F(i,j-1),A);
	}
	if(s[i][j+1]!='#'&&s[i+1][j]!='#')
	{
		if(s[i+1][j]=='.') add(F(i,j+1),F(i+1,j),A);
		if(s[i][j+1]=='.') add(F(i+1,j),F(i,j+1),A);
	}
	if(s[i][j+1]!='#'&&s[i-1][j]!='#')
	{
		if(s[i-1][j]=='.') add(F(i,j+1),F(i-1,j),A);
		if(s[i][j+1]=='.') add(F(i-1,j),F(i,j+1),A);
	}
	if(s[i][j-1]!='#'&&s[i+1][j]!='#')
	{
		if(s[i+1][j]=='.') add(F(i,j-1),F(i+1,j),A);
		if(s[i][j-1]=='.') add(F(i+1,j),F(i,j-1),A);
	}
	return ;
}
signed main()
{
	for(int i=0; i<=n+1; ++i) s[i].resize(m+2,'#');
	for(int i=1; i<=n; ++i)
	{
		scanf("%s",str+1);
		for(int j=1; j<=m; ++j)
			s[i][j]=str[j];
	}
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			if(s[i][j]=='.') add(0,F(i,j),0);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<m; ++j)
			if(s[i][j]=='L'&&s[i][j+1]=='R')
			{
				if(s[i][j-1]!='#') add(F(i,j-1),F(i,j+1),B);
				if(s[i][j+2]!='#') add(F(i,j+2),F(i,j),B);
				s[i][j+1]='.',
				qwq(i,j),
				s[i][j+1]='R',s[i][j]='.',
				qwq(i,j+1),
				s[i][j]='L';
			}
	for(int i=1; i<n; ++i)
		for(int j=1; j<=m; ++j)
			if(s[i][j]=='U'&&s[i+1][j]=='D')
			{
				if(s[i-1][j]!='#') add(F(i-1,j),F(i+1,j),B);
				if(s[i+2][j]!='#') add(F(i+2,j),F(i,j),B);
				s[i+1][j]='.',
				qwq(i,j),s[i+1][j]='D',s[i][j]='.',
				qwq(i+1,j),s[i][j]='U';
			}
	sssp(0);
	int ans=1e18;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<m; ++j)
			if(s[i][j]!='#'&&s[i][j+1]!='#')
			{
				ans=min(ans,dis[F(i,j)]+dis[F(i,j+1)]);
			}
	for(int i=1; i<n; ++i)
		for(int j=1; j<=m; ++j)
			if(s[i][j]!='#'&&s[i+1][j]!='#')
			{
				ans=min(ans,dis[F(i,j)]+dis[F(i+1,j)]);
			}
	if(ans>5e17) puts("-1");
	else printf("%lld\n",ans);
	return 0;
}