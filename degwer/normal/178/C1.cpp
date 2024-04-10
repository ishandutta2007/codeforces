#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int hash,plu,query;
	scanf("%d%d%d",&hash,&plu,&query);
	int map[5000];
	fill(map,map+5000,0);
	int ret=0;
	for(int i=0;i<query;i++)
	{
		char zc;
		int ha;
		scanf(" %c%d",&zc,&ha);
		if(zc=='+')
		{
			int num;
			scanf("%d",&num);
			for(;;)
			{
				if(map[num]==0)
				{
					map[num]=ha;
					break;
				}
				ret++;
				num=(num+plu)%hash;
			}
		}
		else
		{
			for(int j=0;j<hash;j++)
			{
				if(map[j]==ha)
				{
					map[j]=0;
					break;
				}
			}
		}
	}
	printf("%d\n",ret);
}