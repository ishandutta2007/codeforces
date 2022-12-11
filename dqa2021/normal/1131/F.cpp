#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int lr[150010][2];
int fat[150010];
int find(int x)
{
	return x==fat[x]?x:fat[x]=find(fat[x]);
}

struct Edge{
	int to,nxt;
}edge[300010];
int cnt,last[150010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
int d[150010];  //d used

void dfs(int cur,int fat)
{
	printf(" %d",cur);
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to!=fat)
			dfs(edge[i].to,cur);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) fat[i]=lr[i][0]=lr[i][1]=i;
	int x,y;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		x=find(x); y=find(y);
		addedge(lr[x][1],lr[y][0]);
		d[lr[x][1]]++,d[lr[y][0]]++;
		lr[x][1]=lr[y][1];
		fat[y]=x;
	}
	int rt;
	for (int i=1;i<=n;i++)
		if (d[i]==1)
		{
			rt=i; break;
		}
	printf("%d",rt);
	dfs(edge[last[rt]].to,rt);
	putchar('\n');
	return 0;
}