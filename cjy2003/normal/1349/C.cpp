#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,qnum;
char mp[1010][1010];
bool vis[1010][1010];
int dis[1010][1010],fx[4]={1,0,-1,0},fy[4]={0,1,0,-1};
int q[1000010][2],h,t;
void bfs(int x,int y)
{
	int xx,yy;
	h=0,t=1,q[t][0]=x,q[t][1]=y,vis[x][y]=1;
	while(h<t)
	{
		x=q[++h][0],y=q[h][1];
		for(int i=0;i<4;++i)
		{
			xx=x+fx[i],yy=y+fy[i];
			if(xx&&yy&&xx<=n&&yy<=m&&!vis[xx][yy]&&mp[x][y]==mp[xx][yy])
			{
				vis[xx][yy]=1;
				q[++t][0]=xx,q[t][1]=yy;
			}
		}
	}
	if(t>1)for(int i=1;i<=t;++i)dis[q[i][0]][q[i][1]]=0;
	else dis[x][y]=0x3f3f3f3f;
}
void bfs1()
{
	int x,y,xx,yy;
	h=0,t=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			vis[i][j]=0;
			if(!dis[i][j])q[++t][0]=i,q[t][1]=j;
		}
	while(h<t)
	{
		x=q[++h][0],y=q[h][1];
		for(int i=0;i<4;++i)
		{
			xx=x+fx[i],yy=y+fy[i];
			if(xx&&yy&&xx<=n&&yy<=m&&dis[xx][yy]==0x3f3f3f3f)
			{
				dis[xx][yy]=dis[x][y]+1;
				q[++t][0]=xx,q[t][1]=yy;
			}
		}
	}
}
int main()
{
	scanf("%d %d %d",&n,&m,&qnum);
	for(int i=1;i<=n;++i)scanf("%s",mp[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(!vis[i][j])bfs(i,j);
	bfs1();
	int x,y;
	long long t;
	while(qnum--)
	{
		scanf("%d %d %lld",&x,&y,&t);
		if(dis[x][y]==0x3f3f3f3f||t<dis[x][y])putchar(mp[x][y]);
		else putchar(mp[x][y]^((t-dis[x][y])&1));
		putchar('\n');
	}
	return 0;
}