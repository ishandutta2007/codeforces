#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,i,j,head[N],Next[N*2],adj[N*2],t[N*2],k,ans[N][2],vis[N],u,v,w;
void Push(int u,int v,int w)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
	t[k]=w;
}
struct str{
	int d,x;
};
bool operator <(str a,str b)
{
	return a.d>b.d;
}
priority_queue<str> q;
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d %d %d",&u,&v,&w);
		Push(v,u,w);
	}
	memset(ans,0x7f,sizeof(ans));
	ans[n][0]=ans[n][1]=0;
	q.push((str){0,n});
	while(!q.empty())
	{
		str x=q.top();
		q.pop();
		if(vis[x.x])
			continue;
		vis[x.x]=1;
		for(i=head[x.x];i;i=Next[i])
			if(ans[adj[i]][t[i]]>x.d+1)
			{
				ans[adj[i]][t[i]]=x.d+1;
				q.push((str){max(ans[adj[i]][0],ans[adj[i]][1]),adj[i]});
			}
	}
	if(max(ans[1][0],ans[1][1])>n)
		puts("-1");
	else
		printf("%d\n",max(ans[1][0],ans[1][1]));
	for(i=1;i<=n;++i)
		putchar(ans[i][0]>ans[i][1]?'0':'1');
}