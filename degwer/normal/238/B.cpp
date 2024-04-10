#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int main()
{
	int num,add;
	scanf("%d%d",&num,&add);
	vector<int>vec,zv;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
	}
	zv=vec;
	if(vec.size()==1)
	{
		printf("0\n1\n");
		return 0;
	}
	if(vec.size()==2)
	{
		printf("0\n1 1\n");
		return 0;
	}
	sort(vec.begin(),vec.end());
	int sma=min(vec[0]+vec[1]+add,vec[1]+vec[2]);
	int big=max(vec[0]+vec[num-1]+add,vec[num-1]+vec[num-2]);
	if(big-sma<vec[num-1]+vec[num-2]-vec[0]-vec[1])
	{
		int nn=-1;
		for(int i=0;i<num;i++)
		{
			if(zv[i]==vec[0])
			{
				nn=i;
				break;
			}
		}
		printf("%d\n",big-sma);
		for(int i=0;i<num;i++)
		{
			if(i!=0)
			{
				printf(" ");
			}
			if(i==nn)
			{
				printf("2");
			}
			else
			{
				printf("1");
			}
		}
	}
	else
	{
		printf("%d\n",vec[num-1]+vec[num-2]-vec[0]-vec[1]);
		for(int i=0;i<num;i++)
		{
			if(i!=0)
			{
				printf(" ");
			}
			printf("1");
		}
	}
	printf("\n");
}