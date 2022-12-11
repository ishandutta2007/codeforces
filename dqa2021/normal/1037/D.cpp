#include<cstdio>
#include<algorithm>
using namespace std;

int n;
struct Edge{
	int to,nxt;
}edge[400010];
int cnt,last[200010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
int que[200010],hd,tl=1;
bool vis[200010];

int main()
{
	scanf("%d",&n);
	if (n==1){puts("yes");return 0;}
	for (int i=2,x,y;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	for (int i=1;i<=n;i++) scanf("%d",que+i);
	if (que[1]!=1){puts("no");return 0;}
	vis[que[1]]=true;
	while (hd<tl)
	{
		int u=que[++hd],tot=0;
		for (int i=last[u];i;i=edge[i].nxt)
			if (!vis[edge[i].to])
				tot++,vis[edge[i].to]=true;
		for (int i=1;i<=tot;i++)
			if (!vis[que[++tl]])
			{
				puts("no");
				return 0;
			}
	}
	puts("yes");
	return 0;
}