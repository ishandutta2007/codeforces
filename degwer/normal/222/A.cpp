#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num,k;
	scanf("%d%d",&num,&k);
	vector<int>vec;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
	}
	int now=vec[num-1];
	int ret=0;
	for(int i=num-1;i>=0;i--)
	{
		if(now==vec[i])
		{
			ret++;
		}
		else
		{
			break;
		}
	}
	if(k+ret>=num+1)
	{
		printf("%d\n",num-ret);
	}
	else
	{
		printf("-1\n");
	}
}