#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int map[1002][1002];
int main()
{
	int num,query;
	scanf("%d%d",&num,&query);
	for(int i=0;i<query;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				map[za+j][zb+k]++;
				if(map[za+j][zb+k]==9)
				{
					printf("%d\n",i+1);
					return 0;
				}
			}
		}
	}
	printf("-1\n");
}