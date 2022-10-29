#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
typedef pair<int,int>pii;
int main()
{
	int num;
	scanf("%d",&num);
	if(num==1)
	{
		printf("0\n");
		return 0;
	}
	vector<pii>vec;
	for(int i=0;i<num;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		vec.push_back(make_pair(za,1));
		if(za!=zb)
		{
			vec.push_back(make_pair(zb,0));
		}
	}
	sort(vec.begin(),vec.end());
	int now=-1;
	int kaz=0;
	int po=0;
	int mini=100000000;
	for(int i=0;i<vec.size();i++)
	{
		if(now==vec[i].first)
		{
			if(vec[i].second==1)
			{
				po++;
			}
			kaz++;
		}
		else
		{
			now=vec[i].first;
			if(kaz>=(num+1)/2)
			{
				mini=min(mini,max((num+1)/2-po,0));
			}
			kaz=1;
			po=vec[i].second;
		}
		//printf("%d %d\n",now,kaz);
	}
	if(kaz>=(num+1)/2)
	{
		mini=min(mini,max((num+1)/2-po,0));
	}
	if(mini==100000000)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n",mini);
	}
}