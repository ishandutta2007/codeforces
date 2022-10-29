#include<stdio.h>
#include<vector>
#include<algorithm>
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int map[502][502];
using namespace std;
int ret=0;
void dfs(int x,int y,int num)
{
	if(ret==num)
	{
		return;
	}
	map[x][y]=2;
	ret++;
	for(int i=0;i<4;i++)
	{
		if(map[x+dx[i]][y+dy[i]]==0)
		{
			dfs(x+dx[i],y+dy[i],num);
		}
	}
}
int main()
{
	int mx,my,num;
	scanf("%d%d%d",&mx,&my,&num);
	num=mx*my-num;
	for(int i=0;i<502;i++)
	{
		for(int j=0;j<502;j++)
		{
			map[i][j]=1;
		}
	}
	int sx,sy;
	for(int i=0;i<mx;i++)
	{
		for(int j=0;j<my;j++)
		{
			char zan;
			scanf(" %c",&zan);
			if(zan=='.')
			{
				map[i+1][j+1]=0;
				sx=i+1;
				sy=j+1;
			}
			else
			{
				num--;
			}
		}
	}
	dfs(sx,sy,num);
	for(int i=1;i<=mx;i++)
	{
		for(int j=1;j<=my;j++)
		{
			if(map[i][j]==2)
			{
				printf(".");
			}
			if(map[i][j]==1)
			{
				printf("#");
			}
			if(map[i][j]==0)
			{
				printf("X");
			}
		}
		printf("\n");
	}
}