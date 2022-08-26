#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<queue>
#define sqr(x) (x)*(x)
using namespace std;
int dx[5]={0,-1,1,0,0},dy[5]={0,0,0,-1,1};
int n,m,d,i,j,vis[1005][1005],dis[1005][1005],cntd;
char mp[1005][1005];
vector<pair<int,int>/**/> rats;
void bfs5(int x,int y)
{
	queue<int> qx,qy;
	int i;
	qx.push(x);
	qy.push(y);
	dis[x][y]=0x16161616;
	while (!qx.empty())
	{
		int nx=qx.front(),ny=qy.front();
		qx.pop();qy.pop();
		for (i=1;i<=4;i++)
		{
			int xx=nx+dx[i],yy=ny+dy[i];
			if (dis[xx][yy]!=0x16161616)
			{
				dis[xx][yy]=0x16161616;
				qx.push(xx);
				qy.push(yy);
			}
		}
	}
}
void bfs2(int x,int y,int ad)
{
	queue<int> qx,qy;
	int i;
	qx.push(x);
	qy.push(y);
	dis[x][y]=0;
	while (!qx.empty())
	{
		int nx=qx.front(),ny=qy.front();
		qx.pop();qy.pop();
		vis[nx][ny]+=ad;
		if (ad==-1&&vis[nx][ny]==0&&mp[nx][ny]=='R') cntd--;
		if (ad==1&&vis[nx][ny]==1&&mp[nx][ny]=='R') cntd++;
		if (dis[nx][ny]>=d) continue;
		for (i=1;i<=4;i++)
		{
			int xx=nx+dx[i],yy=ny+dy[i];
			if (dis[xx][yy]==0x16161616&&mp[xx][yy]!='X')
			{
				dis[xx][yy]=dis[nx][ny]+1;
				qx.push(xx);
				qy.push(yy);
			}
		}
	}
}
bool bfs3(int x,int y,int nox,int noy)
{
	queue<int> qx,qy;
	int i;
	qx.push(x);
	qy.push(y);
	dis[x][y]=0;
	vector<pair<int,int>/**/> can;
	while (!qx.empty())
	{
		int nx=qx.front(),ny=qy.front();
		qx.pop();qy.pop();
		if (nx!=nox||ny!=noy) can.push_back(make_pair(nx,ny));
		if (dis[nx][ny]>=d) continue;
		for (i=1;i<=4;i++)
		{
			int xx=nx+dx[i],yy=ny+dy[i];
			if (dis[xx][yy]==0x16161616&&mp[xx][yy]!='X')
			{
				dis[xx][yy]=dis[nx][ny]+1;
				qx.push(xx);
				qy.push(yy);
			}
		}
	}
	bfs5(x,y);
	for (i=0;i<can.size();i++)
	{
		bfs2(can[i].first,can[i].second,1);
		bfs5(can[i].first,can[i].second);
		if (cntd==rats.size())
		{
			cout<<can[i].first<<' '<<can[i].second<<' ';
			return 1;
		}
		bfs2(can[i].first,can[i].second,-1);
		bfs5(can[i].first,can[i].second);
	}
	return 0;
}
void bfs(int x,int y)
{
	queue<int> qx,qy;
	memset(dis,22,sizeof(dis));
	int i;
	qx.push(x);
	qy.push(y);
	dis[x][y]=0;
	vector<pair<int,int>/**/> can;
	while (!qx.empty())
	{
		int nx=qx.front(),ny=qy.front();
		qx.pop();qy.pop();
		can.push_back(make_pair(nx,ny));
		if (dis[nx][ny]>=d) continue;
		for (i=1;i<=4;i++)
		{
			int xx=nx+dx[i],yy=ny+dy[i];
			if (dis[xx][yy]==0x16161616&&mp[xx][yy]!='X')
			{
				dis[xx][yy]=dis[nx][ny]+1;
				qx.push(xx);
				qy.push(yy);
			}
		}
	}
	bfs5(x,y);
	for (i=0;i<can.size();i++)
	{
		bfs2(can[i].first,can[i].second,1);
		bfs5(can[i].first,can[i].second);
		for (j=0;j<rats.size();j++)
		{
			if (!vis[rats[j].first][rats[j].second])
			{
				if (bfs3(rats[j].first,rats[j].second,x,y))
				{
					cout<<can[i].first<<' '<<can[i].second;
					exit(0);
				}
				else break;
			}
		}
		if (j>=rats.size())
		{
			int cnt=0;
			cout<<can[i].first<<' '<<can[i].second<<' ';
			int xxx=can[i].first,yyy=can[i].second;
			for (i=1;i<=n;i++)
			{
				for (j=1;j<=m;j++)
				{
					if (cnt>=1) break;
					if ((i!=xxx||j!=yyy)&&mp[i][j]!='X')
					{
						cout<<i<<' '<<j<<' ';
						cnt++;
					}
				}
			}
			exit(0);
		}
		bfs2(can[i].first,can[i].second,-1);
		bfs5(can[i].first,can[i].second);
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>d;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			cin>>mp[i][j];
			if (mp[i][j]=='R')
			{
				rats.push_back(make_pair(i,j));
			}
		}
	}
	if (rats.empty())
	{
		int cnt=0;
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=m;j++)
			{
				if (cnt>=2) break;
				if (mp[i][j]!='X')
				{
					cout<<i<<' '<<j<<' ';
					cnt++;
				}
			}
		}
		return 0;
	}
	if (rats.size()==1)
	{
		int cnt=0;
		cout<<rats[0].first<<' '<<rats[0].second<<' ';
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=m;j++)
			{
				if (cnt>=1) break;
				if (mp[i][j]!='X'&&(rats[0].first!=i||rats[0].second!=j))
				{
					cout<<i<<' '<<j<<' ';
					cnt++;
				}
			}
		}
		return 0;
	}
	if (rats.size()>500)
	{
		cout<<-1;
		return 0;
	}
	bfs(rats[0].first,rats[0].second);
	cout<<-1;
	return 0;
}