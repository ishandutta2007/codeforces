#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,vector<int> >piv;
int kai[100001];
int main()
{
	int num,query;
	scanf("%d%d",&num,&query);
	vector<int>vec;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
		if(zan<=num)
		{
			kai[zan]++;
		}
	}
	vector<piv>rui;
	for(int i=1;i<=num;i++)
	{
		if(kai[i]>=i)
		{
			vector<int>damy;
			rui.push_back(make_pair(i,damy));
			rui[rui.size()-1].second.push_back(0);
		}
	}
	for(int i=0;i<rui.size();i++)
	{
		//printf("%d   ",rui[i].first);
		for(int j=0;j<num;j++)
		{
			rui[i].second.push_back(rui[i].second[j]+(vec[j]==rui[i].first));
		//	printf("%d ",rui[i].second[rui[i].second.size()-1]);
		}
		//printf("\n");
	}
	for(int i=0;i<query;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		int ret=0;
		for(int i=0;i<rui.size();i++)
		{
			if(rui[i].first==rui[i].second[zb]-rui[i].second[za-1])
			{
				ret++;
			}
		}
		printf("%d\n",ret);
	}
}