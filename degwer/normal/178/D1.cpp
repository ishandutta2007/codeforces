#include<stdio.h>/*
#include "stdafx.h"*/
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int num;
	vector<int>vec;
	scanf("%d",&num);
	int sum=0;
	for(int i=0;i<num*num;i++)
	{
		int zan;
		scanf("%d",&zan);
		sum+=zan;
		vec.push_back(zan);
	}
	sum/=num;
	printf("%d\n",sum);
	sort(vec.begin(),vec.end());
	if(num==1)
	{
		printf("%d\n",vec[0]);
	}
	if(num==2)
	{
		printf("%d %d\n%d %d\n",vec[0],vec[1],vec[2],vec[3]);
	}
	if(num==3)
	{
		for(;;)
		{
			if(vec[0]+vec[1]+vec[2]==sum&&vec[3]+vec[4]+vec[5]==sum&&vec[0]+vec[3]+vec[6]==sum&&vec[1]+vec[4]+vec[7]==sum&&vec[0]+vec[4]+vec[8]==sum&&vec[2]+vec[4]+vec[6]==sum)
			{
				printf("%d %d %d\n%d %d %d\n%d %d %d\n",vec[0],vec[1],vec[2],vec[3],vec[4],vec[5],vec[6],vec[7],vec[8]);
				break;
			}
			next_permutation(vec.begin(),vec.end());
		}
	}
}