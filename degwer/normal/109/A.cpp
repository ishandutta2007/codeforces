#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	scanf("%d",&num);
	vector<int>v;
	for(;;)
	{
		if(num%7==0)
		{
			v.push_back(7);
			num-=7;
		}
		else
		{
			v.push_back(4);
			num-=4;
		}
		if(num<0)
		{
			printf("-1\n");
			return 0;
		}
		if(num==0)
		{
			break;
		}
	}
	for(int i=0;i<v.size();i++)
	{
		printf("%d",v[i]);
	}
	printf("\n");
}