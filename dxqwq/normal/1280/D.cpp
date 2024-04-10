// Problem: D. Miss Punyverse
// Contest: Codeforces - Codeforces Round #607 (Div. 1)
// URL: https://codeforces.com/contest/1280/problem/D
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[3003];
int sz[3003];
int f[3003][3003],tf[3003];
ll g[3003][3003],tg[3003];
int n,m;
vector<int> e[3003];
void dfs(int x,int fa)
{
	sz[x]=1;
	for(int i=1; i<=n; ++i) f[x][i]=-1;
	for(int i=1; i<=n; ++i) g[x][i]=-1;
	f[x][0]=0,g[x][0]=a[x];
	for(int i:e[x]) if(i!=fa)
	{	
		dfs(i,x);
		for(int j=0; j<sz[x]+sz[i]&&j<m; ++j) tf[j]=-1;
		for(int j=0; j<sz[x]+sz[i]&&j<m; ++j) tg[j]=-1;
		for(int j=0; j<sz[x]; ++j)
		for(int k=0; k<=sz[i]&&j+k<m; ++k)
		if(f[x][j]+f[i][k]>tf[j+k]) 
			tf[j+k]=f[x][j]+f[i][k],
			tg[j+k]=g[x][j]+g[i][k]; 
		else if(f[x][j]+f[i][k]==tf[j+k])
			tg[j+k]=max(tg[j+k],g[x][j]+g[i][k]);
		sz[x]+=sz[i];
		for(int j=0; j<sz[x]&&j<m; ++j) f[x][j]=tf[j];
		for(int j=0; j<sz[x]&&j<m; ++j) g[x][j]=tg[j];
	}
	if(x==1) printf("%d\n",f[x][m-1]+(g[x][m-1]>0));
	for(int i=min(sz[x],m-1)-1; i>=0; --i) 
	if(f[x][i]+(g[x][i]>0)>f[x][i+1]) 
		f[x][i+1]=f[x][i]+(g[x][i]>0),g[x][i+1]=0; 
	else if(f[x][i]+(g[x][i]>0)==f[x][i+1]&&g[x][i+1]<0)
		g[x][i+1]=0;
	// printf("Debug %d\n",x);
	// for(int i=0; i<=sz[x]; ++i) printf("%d ",f[x][i]);
	// puts("");
	// for(int i=0; i<=sz[x]; ++i) printf("%lld ",g[x][i]);
	// puts("");
	// puts("");
	return ;
}
signed main()
{
	for(int T=read();T--;)
	{
		n=read(),m=read();
		for(int i=1; i<=n; ++i) a[i]=-read();
		for(int i=1; i<=n; ++i) a[i]+=read();
		for(int i=1; i<=n; ++i) e[i].clear();
		for(int i=1; i<n; ++i)
		{
			int u=read(),v=read();
			e[u].push_back(v),e[v].push_back(u);
		}
		dfs(1,1);
	}
	return 0;
}