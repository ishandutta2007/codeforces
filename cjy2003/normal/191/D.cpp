#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct bian
{
	int to,nxt;
}bi[600060];
int n,m,d[100010],cnt,num,head[100010],tot,t[200020];
bool vis[100010];
void add(int from,int to)
{
	bi[++num].nxt=head[from];
	head[from]=num;
	bi[num].to=to;
}
void dfs(int v)
{
	if(d[v]!=2)
	{
		t[++tot]=v;
		return ;
	}
	vis[v]=1;
	int u;
	for(int i=head[v];i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(!vis[u])dfs(u);
	}
}
int main()
{
	int x,y;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d",&x,&y);
		add(x,y),add(y,x);
		++d[x],++d[y];
	}
	for(int i=1;i<=n;++i)
		if(d[i]&1)++cnt;
	cnt/=2;
	for(int i=1;i<=n;++i)
		if(!vis[i]&&d[i]==2)
		{
			tot=0,dfs(i);
			if(!tot)++cnt;
			if(tot==2&&t[1]==t[2])++cnt;
		//	printf("%d %d\n",i,tot);
		//	cnt+=tot<=1;
		//	if(!tot)printf("%d ",i);
		}
	printf("%d %d",cnt,m);
	return 0;
}