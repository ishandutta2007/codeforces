#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char s[1003][1003];
int sz[1003][1003],id[1003][1003];
bool vis[1003][1003];
int C=0,D;
void dfs(int x,int y)
{
	vis[x][y]=1,++C;
	if(s[x-1][y]=='.'&&!vis[x-1][y]) dfs(x-1,y);
	if(s[x+1][y]=='.'&&!vis[x+1][y]) dfs(x+1,y);
	if(s[x][y-1]=='.'&&!vis[x][y-1]) dfs(x,y-1);
	if(s[x][y+1]=='.'&&!vis[x][y+1]) dfs(x,y+1);
	return ;
}
void dfs2(int x,int y)
{
	id[x][y]=D;
	vis[x][y]=0,sz[x][y]=C;
	if(s[x-1][y]=='.'&&vis[x-1][y]) dfs2(x-1,y);
	if(s[x+1][y]=='.'&&vis[x+1][y]) dfs2(x+1,y);
	if(s[x][y-1]=='.'&&vis[x][y-1]) dfs2(x,y-1);
	if(s[x][y+1]=='.'&&vis[x][y+1]) dfs2(x,y+1);
	return ;
}
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; i++) scanf("%s",s[i]+1);
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) if(s[i][j]=='.'&&sz[i][j]==0) 
    {
    	C=0;D++;
    	dfs(i,j);
    	dfs2(i,j);
	}
	for(int i=1; i<=n; i++,puts("")) for(int j=1; j<=m; j++) if(s[i][j]=='.') printf("."); else 
	{
		int T=1;
		if(sz[i-1][j]) T+=sz[i-1][j];
		if(sz[i+1][j]) if(id[i+1][j]!=id[i-1][j]) T+=sz[i+1][j];
		if(sz[i][j-1]) if(id[i-1][j]!=id[i][j-1]) if(id[i+1][j]!=id[i][j-1])T+=sz[i][j-1];
		if(sz[i][j+1]) if(id[i-1][j]!=id[i][j+1]) if(id[i+1][j]!=id[i][j+1])
		if(id[i][j-1]!=id[i][j+1])T+=sz[i][j+1];
		printf("%d",T%10);
	}
	return 0;
}