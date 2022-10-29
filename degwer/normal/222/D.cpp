#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
	int num,poi;
	scanf("%d%d",&num,&poi);
	vector<int>vec;
	multiset<int>se;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
	}
	sort(vec.begin(),vec.end());
	for(int j=0;j<num;j++)
	{
		int zan;
		scanf("%d",&zan);
		se.insert(zan);
	}
	int ret=0;
	for(int i=0;i<num;i++)
	{
		multiset<int>::iterator it=se.lower_bound(poi-vec[i]);
		if(it!=se.end())
		{
			ret++;
			int zan=*it;
			se.erase(it);
		}
	}
	printf("1 %d\n",ret);
}