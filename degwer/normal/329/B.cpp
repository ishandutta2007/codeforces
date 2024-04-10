#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int map[1002][1002];
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
typedef pair<int,int>pii;
typedef pair<int,pii>pi3;
bool flag[1002][1002];
int dist[1002][1002];
int main()
{
	for(int i=0;i<1002;i++)
	{
		for(int j=0;j<1002;j++)
		{
			map[i][j]=-1;
			flag[i][j]=false;
			dist[i][j]=1000000000;
		}
	}
	int mx,my;
	scanf("%d%d",&mx,&my);
	int sx,sy;
	int gx,gy;
	for(int i=0;i<mx;i++)
	{
		for(int j=0;j<my;j++)
		{
			char zan;
			scanf(" %c",&zan);
			if(zan=='E')
			{
				sx=i+1;
				sy=j+1;
				map[i+1][j+1]=0;
			}
			if(zan=='S')
			{
				gx=i+1;
				gy=j+1;
				map[i+1][j+1]=0;
			}
			if('0'<=zan&&zan<='9')
			{
				map[i+1][j+1]=zan-'0';
			}
		}
	}
	queue<pi3>que;
	que.push(make_pair(0,make_pair(sx,sy)));
	int ans=0;
	for(;;)
	{
		if(que.empty())
		{
			break;
		}
		pi3 zan=que.front();
		que.pop();
		if(flag[zan.second.first][zan.second.second])
		{
			continue;
		}
		flag[zan.second.first][zan.second.second]=true;
		dist[zan.second.first][zan.second.second]=zan.first;
		for(int i=0;i<4;i++)
		{
			if(map[zan.second.first+dx[i]][zan.second.second+dy[i]]!=-1)
			{
				que.push(make_pair(zan.first+1,make_pair(zan.second.first+dx[i],zan.second.second+dy[i])));
			}
		}
	}
	for(int i=0;i<1002;i++)
	{
		for(int j=0;j<1002;j++)
		{
			if(dist[i][j]<=dist[gx][gy])
			{
				ans+=map[i][j];
			}
		}
	}
	printf("%d\n",ans);
}