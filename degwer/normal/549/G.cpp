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
		vec.push_back(zan+i);
	}
	sort(vec.begin(),vec.end());
	bool f=true;
	for(int i=0;i<num;i++)
	{
		vec[i]-=i;
		if(vec[i]<0)f=false;
	}
	for(int i=0;i<num-1;i++)
	{
		if(vec[i]>vec[i+1])f=false;
	}
	if(!f)printf(":(\n");
	else 
	{
		for(int i=0;i<num;i++)
		{
			if(i!=0)printf(" ");
			printf("%d",vec[i]);
		}
		printf("\n");
	}
}