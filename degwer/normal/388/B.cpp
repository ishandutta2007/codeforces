#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int map[1000][1000];
void add(int a,int b)
{
	map[a][b]=1;
	map[b][a]=1;
}
int main()
{
	int num;
	scanf("%d",&num);
	int pt=2;
	for(int i=0;i<=10;i++)
	{
		if(num%10!=0)
		{
			int a=pt+num%10;
			for(int j=0;j<num%10;j++)
			{
				add(0,pt);
				add(pt,a);
				pt++;
			}
			pt++;
			for(int j=0;j<i;j++)
			{
				for(int k=0;k<10;k++)
				{
					add(a,pt);
					add(pt,a+11);
					pt++;
				}
				pt++;
				a+=11;
			}
			for(int j=i;j<=9;j++)
			{
				//printf("%d %d\n",pt,a);
				add(a,a+1);
				add(a+1,a+2);
				pt+=2;
				a+=2;
			}
			add(a,1);
		}
		num/=10;
	}
	printf("%d\n",pt);
	for(int i=0;i<pt;i++)
	{
		for(int j=0;j<pt;j++)
		{
			if(map[i][j])
			{
				printf("Y");
			}
			else
			{
				printf("N");
			}
		}
		printf("\n");
	}
}