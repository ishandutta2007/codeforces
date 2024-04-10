#include<bits/stdc++.h>
using namespace std;
const int N=300005;

int v[N][4];
int n,m,in[N],vis[N],color[N];

void dfs(int u)
{
	int num=0; 
	for(int i=1;i<=in[u];i++)
	{
		int to=v[u][i];
		if(color[to]==color[u]) num++;
	}
	if(num>1)
	{
		color[u]^=1;
		for(int i=1;i<=in[u];i++)
		{
			dfs(v[u][i]);
		}
	}
}

int main()
{
	//memset(color,-1,sizeof(color));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x][++in[x]]=y; v[y][++in[y]]=x;
	}
	for(int i=1;i<=n;i++) dfs(i);
	for(int i=1;i<=n;i++) printf("%d",color[i]);
}