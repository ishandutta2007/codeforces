#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int map[100][100];
int main()
{
	int mx,my;
	scanf("%d%d",&mx,&my);
	for(int i=0;i<mx;i++)
	{
		for(int j=0;j<my;j++)
		{
			char zan;
			scanf(" %c",&zan);
			if(zan=='W')map[i][j]=1;
			else map[i][j]=-1;
		}
	}
	int cnt=0;
	for(int i=mx-1;i>=0;i--)
	{
		for(int j=my-1;j>=0;j--)
		{
			if(map[i][j]!=0)
			{
				cnt++;
				int t=map[i][j];
				for(int k=0;k<=i;k++)for(int l=0;l<=j;l++)map[k][l]-=t;
			}
		}
	}
	printf("%d\n",cnt);
}