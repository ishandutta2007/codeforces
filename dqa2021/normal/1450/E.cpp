#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#include<cstdlib>
#include<assert.h>
#define pb push_back
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
const int INF=1e9;

int n,m;
int dis[210][210];
vector<int> e[210];
int c[210];
void dfs(int x,int col){
	c[x]=col;
	for (int y: e[x]){
		if (!c[y]) dfs(y,3-col);
		else if (c[y]+c[x]!=3) puts("NO"),exit(0);
	}
}
int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (i^j) dis[i][j]=INF;
	for (int i=1;i<=m;i++){
		int u=read(),v=read(),c=read();
		e[u].pb(v),e[v].pb(u);
		if (c) dis[u][v]=min(dis[u][v],1),dis[v][u]=min(dis[v][u],-1);
		else dis[u][v]=min(dis[u][v],1),dis[v][u]=min(dis[v][u],1);
	}
	dfs(1,1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=n;k++)
				if (dis[j][i]+dis[i][k]<dis[j][k]){
					dis[j][k]=dis[j][i]+dis[i][k];
				}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=n;k++)
				if (dis[j][i]+dis[i][k]<dis[j][k])
					puts("NO"),exit(0);
	puts("YES");
	int ans=-1e9,A=-1,B=-1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (dis[i][j]>ans) ans=dis[i][j],A=i,B=j;
	assert(ans>=0);
	printf("%d\n",ans);
	for (int i=1;i<=n;i++) printf("%d ",10000+dis[A][i]);
	puts("");
	return 0;
}