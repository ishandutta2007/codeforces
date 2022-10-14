// Problem: CF815C Karen and Supermarket
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF815C
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int c[5003],d[5003];
vector<int> e[5003];
int f[5003][5003];
int g[5003][5003];
//not choose root,choose root
int sz[5003];
int n=read(),m=read();
void dfs(int x,int fa)
{
	sz[x]=1,f[x][0]=0,f[x][1]=c[x];//more
	g[x][1]=d[x];//less
	for(int i:e[x])
	{
		dfs(i,x);
		int N=sz[x],M=sz[i];
		for(int j=N; j>=1; --j)
			for(int k=1; k<=M; ++k)
				g[x][j+k]=min(g[x][j+k],g[x][j]+min(g[i][k],f[i][k]));
		for(int j=N; j>=0; --j)
			for(int k=1; k<=M; ++k)
				f[x][j+k]=min(f[x][j+k],f[x][j]+f[i][k]);	
		sz[x]+=sz[i]; 
	} 
	// printf("POINT %d\n",x);
	// for(int i=0; i<=sz[x]; ++i) printf("%d ",f[x][i]);puts("");
	// for(int i=0; i<=sz[x]; ++i) printf("%d ",g[x][i]);puts("");
	return ;
}
signed main()
{
	c[1]=read(),d[1]=c[1]-read();
	for(int i=2; i<=n; ++i) 
	{
		c[i]=read(),d[i]=c[i]-read();
		e[read()].push_back(i);
	}
	memset(f,0x3f,sizeof(f));
	memset(g,0x3f,sizeof(g));
	dfs(1,1);
	for(int i=n; i>=0; --i) if(min(f[1][i],g[1][i])<=m) printf("%d\n",i),exit(0);
	assert(0);
	return 0;
}