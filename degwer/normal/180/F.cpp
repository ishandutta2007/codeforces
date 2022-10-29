#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
	int num;
	scanf("%d",&num);
	vector<int>from;
	vector<int>to;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		from.push_back(zan);
	}
	for(int j=0;j<num;j++)
	{
		int zan;
		scanf("%d",&zan);
		to.push_back(zan);
	}
	vector<int>vec;
	vector<int>ans;
	for(int k=0;k<num;k++)
	{
		vec.push_back(0);
		ans.push_back(0);
	}
	for(int l=0;l<num;l++)
	{
		vec[to[l]-1]=from[l]-1;
	}
	for(int m=0;m<num;m++)
	{
		if(m!=0)
		{
			printf(" ");
		}
		printf("%d",vec[from[m]-1]+1);
	}
	printf("\n");
}