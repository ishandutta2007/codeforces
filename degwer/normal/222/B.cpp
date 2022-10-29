#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int map[1000][1000];
int dx[1000];
int dy[1000];
int main()
{
	int mx,my,query;
	scanf("%d%d%d",&mx,&my,&query);
	for(int i=0;i<mx;i++)
	{
		for(int j=0;j<my;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	for(int i=0;i<mx;i++)
	{
		dx[i]=i;
	}
	for(int i=0;i<my;i++)
	{
		dy[i]=i;
	}
	for(int i=0;i<query;i++)
	{
		char zan;
		int za,zb;
		scanf(" %c%d%d",&zan,&za,&zb);
		za--;
		zb--;
		if(zan=='r')
		{
			swap(dx[za],dx[zb]);
		}
		if(zan=='c')
		{
			swap(dy[za],dy[zb]);
		}
		if(zan=='g')
		{
			printf("%d\n",map[dx[za]][dy[zb]]);
		}
	}
}