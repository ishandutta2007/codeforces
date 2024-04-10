#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int>pii;
int main()
{
	int num;
	scanf("%d",&num);
	vector<pii>vec;
	for(int i=0;i<num;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		vec.push_back(make_pair(za,zb));
	}
	sort(vec.begin(),vec.end());
	int now=0;
	for(int i=0;i<num;i++)
	{
		if(vec[i].second>=now)
		{
			now=vec[i].second;
		}
		else
		{
			now=vec[i].first;
		}
	}
	printf("%d\n",now);
}