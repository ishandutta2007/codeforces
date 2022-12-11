

#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

int n,m;
struct Edge{
	int to,nxt;
}edge[200010];
int cnt,last[100010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
bool vis[100010];
priority_queue<int> que;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	que.push(-1); vis[1]=true;
	while (!que.empty())
	{
		int u=-que.top(); que.pop();
		printf("%d ",u);
		for (int i=last[u];i;i=edge[i].nxt)
			if (!vis[edge[i].to])
				vis[edge[i].to]=true,que.push(-edge[i].to);
	}
	putchar('\n');
	return 0;
}