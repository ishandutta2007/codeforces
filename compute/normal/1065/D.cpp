#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,num,change,type;
};
int n;
int maze[12][12];
int vis[12][12][120][100][3];
int dx[]={1,1,2,2,-1,-1,-2,-2},dy[]={2,-2,1,-1,2,-2,1,-1};
int ddx[]={1,-1,1,-1},ddy[]={1,1,-1,-1};
pair<int,int> bfs(pair<int,int> st)
{
	memset(vis,-1,sizeof(vis));
	queue<node> q;
	for(int i=0;i<3;i++)
	{
		node temp={st.first,st.second,1,0,i};
		vis[temp.x][temp.y][temp.num][temp.change][temp.type]=0;
		q.push(temp);
	}
	while(!q.empty())
	{
		int change=100000;
		node u=q.front();q.pop();
		if(u.num==n*n)
		{
			change=u.change;
			int step=vis[u.x][u.y][u.num][u.change][u.type];
			while(!q.empty())
			{
				node temp=q.front();
				q.pop();
				if(temp.num==n*n&&vis[temp.x][temp.y][temp.num][temp.change][temp.type]==step) change=min(change,temp.change);
			}
			return make_pair(step,change);
		}
		if(u.type==0)
		{
			for(int i=0;i<8;i++)
			{
				int nx=u.x+dx[i],ny=u.y+dy[i];
				int nnum=u.num;
				if(nx>n||nx<=0||ny>n||ny<=0) continue;
				if(maze[nx][ny]==u.num+1)
					nnum++;
				if(vis[nx][ny][nnum][u.change][u.type]==-1)
				{
					q.push(node {nx,ny,nnum,u.change,u.type});
					vis[nx][ny][nnum][u.change][u.type]=vis[u.x][u.y][u.num][u.change][u.type]+1;
				}
			}
		}
		else if(u.type==1)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<4;j++)
				{
					int nx=u.x+ddx[j]*i,ny=u.y+ddy[j]*i;
					int nnum=u.num;
					if(nx>n||ny>n||ny<=0||nx<=0) continue;
					if(maze[nx][ny]==u.num+1)
						nnum++;
					if(vis[nx][ny][nnum][u.change][u.type]==-1)
					{
						q.push(node {nx,ny,nnum,u.change,u.type});
						vis[nx][ny][nnum][u.change][u.type]=vis[u.x][u.y][u.num][u.change][u.type]+1;
					}
				}
			}
		}
		else{
			for(int i=-n;i<=n;i++)
			{
				int nx=u.x+i,ny=u.y;
				int nnum=u.num;
				if(nx>n||nx<=0) continue;
				if(maze[nx][ny]==u.num+1)
					nnum++;
				if(vis[nx][ny][nnum][u.change][u.type]==-1)
				{
					q.push(node {nx,ny,nnum,u.change,u.type});
					vis[nx][ny][nnum][u.change][u.type]=vis[u.x][u.y][u.num][u.change][u.type]+1;
				}
			}
			for(int i=-n;i<=n;i++)
			{
				int nx=u.x,ny=u.y+i;
				int nnum=u.num;
				if(ny>n||ny<=0) continue;
				if(maze[nx][ny]==u.num+1)
					nnum++;
				if(vis[nx][ny][nnum][u.change][u.type]==-1)
				{
					q.push(node {nx,ny,nnum,u.change,u.type});
					vis[nx][ny][nnum][u.change][u.type]=vis[u.x][u.y][u.num][u.change][u.type]+1;
				}
			}
		}
		for(int i=0;i<3;i++)
		{
			if(i==u.type) continue;
			if(vis[u.x][u.y][u.num][u.change+1][i]==-1)
			{
				q.push(node {u.x,u.y,u.num,u.change+1,i});
				vis[u.x][u.y][u.num][u.change+1][i]=vis[u.x][u.y][u.num][u.change][u.type]+1;
			}
		}
	}
}
int main()
{
	while(~scanf("%d",&n))
	{
		pair<int,int> st;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&maze[i][j]);
				if(maze[i][j]==1)
					st.first=i,st.second=j;
			}
		}
		pair<int,int> ans=bfs(st);
		printf("%d %d\n",ans.first,ans.second);
	}
	return 0;
	
}