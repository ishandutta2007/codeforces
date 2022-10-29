#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
	int num,query;
	scanf("%d%d",&num,&query);
	vector<int>cost;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		cost.push_back(zan);
	}
	vector<int>vec;
	vector<int>now;
	set<int>se;
	for(int i=0;i<query;i++)
	{
		int zan;
		scanf("%d",&zan);
		zan--;
		vec.push_back(zan);
		if(se.find(zan)==se.end())
		{
			now.push_back(zan);
			se.insert(zan);
		}
	}
	int ret=0;
	for(int i=0;i<vec.size();i++)
	{
		for(int j=0;j<now.size();j++)
		{
			if(now[j]==vec[i])
			{
				for(int k=0;k<j;k++)ret+=cost[now[k]];
				for(int k=j;k>=1;k--)
				{
					now[k]=now[k-1];
				}
				now[0]=vec[i];
				break;
			}
		}
	}
	printf("%d\n",ret);
}