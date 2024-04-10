#include<stdio.h>
int main()
{
	int hen;
	scanf("%d",&hen);
	int map[101][101];
	for(int i=0;i<hen;i++)
	{
		for(int j=0;j<hen;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	int sum=0;
	for(int k=0;k<hen;k++)
	{
		sum+=map[k][k]+map[k][hen-1-k]+map[hen/2][k]+map[k][hen/2];
	}
	sum-=3*map[hen/2][hen/2];
	printf("%d\n",sum);
}