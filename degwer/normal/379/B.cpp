#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	scanf("%d",&num);
	vector<int>vec;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
	}
	int pt=0;
	for(;;)
	{
		if(vec[pt]==0)
		{
			if(pt==num-1)
			{
				printf("\n");
				break;
			}
			printf("R");
			pt++;
		}
		else
		{
			if(pt==num-1)
			{
				printf("LRP");
				vec[pt]--;
			}
			else
			{
				printf("RLP");
				vec[pt]--;
			}
		}
	}
}