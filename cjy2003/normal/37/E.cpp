#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct bian
{
	int to,nxt;
}bi[10010];
int n,m,id[51][51],idnum,fx[4]={1,0,-1,0},fy[4]={0,1,0,-1},head[2520],num,ans=0x7fffffff,dis[2520],kd[2520];
bool mp[2520][2520];
char a[51][51];
queue<pair<int,int> >q;
queue<int>q1;
void add(int from,int to)
{
	bi[++num].nxt=head[from];
	head[from]=num;
	bi[num].to=to;
}
void bfs(int x,int y)
{
	q.push(make_pair(x,y));++idnum,id[x][y]=idnum;kd[idnum]=a[x][y]=='B';
	int xx,yy;
	while(!q.empty())
	{
		x=q.front().first,y=q.front().second,q.pop();
		for(int i=0;i<=3;++i)
		{
			xx=x+fx[i],yy=y+fy[i];
			if(!xx||!yy||xx>n||yy>m||id[xx][yy]||a[x][y]!=a[xx][yy])continue;
			id[xx][yy]=idnum;
			q.push(make_pair(xx,yy));
		}
	}
}
int bfs1(int v)
{
	int x,y,sum=1+kd[v];
	q1.push(v);
	memset(dis,0,sizeof(dis));
	dis[v]=1;
	while(!q1.empty())
	{
		x=q1.front();
		q1.pop();
		for(int i=head[x];i;i=bi[i].nxt)
		{
			y=bi[i].to;
			if(dis[y])continue;
			dis[y]=dis[x]+1;sum=max(sum,dis[y]+kd[y]);
			q1.push(y);
		}
	}
	return sum;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%s",a[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(!id[i][j])bfs(i,j);
/*	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			printf("%2d ",id[i][j]);
		printf("\n");
	}*/
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(j<m&&id[i][j]!=id[i][j+1]&&!mp[id[i][j]][id[i][j+1]])add(id[i][j],id[i][j+1]),add(id[i][j+1],id[i][j]),mp[id[i][j]][id[i][j+1]]=mp[id[i][j+1]][id[i][j]]=1;
			if(i<n&&id[i][j]!=id[i+1][j]&&!mp[id[i][j]][id[i+1][j]])add(id[i][j],id[i+1][j]),add(id[i+1][j],id[i][j]),mp[id[i][j]][id[i+1][j]]=mp[id[i+1][j]][id[i][j]]=1;
		}
	int p;
	for(int i=1;i<=idnum;++i)
	{
		int s=bfs1(i);
		if(s<ans)
		{
			ans=s;
			p=i; 
		}
	}
//	printf("%d ",p);
	printf("%d",ans-1);
	return 0;
}