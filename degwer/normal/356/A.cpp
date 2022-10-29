#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int,int>pii;
typedef pair<pii,int>pi3;
int ans[300000];
int main()
{
	int num,mat;
	scanf("%d%d",&num,&mat);
	vector<pi3>vec;
	for(int i=0;i<mat;i++)
	{
		int za,zb,zc;
		scanf("%d%d%d",&za,&zb,&zc);
		za--;
		zb--;
		zc--;
		vec.push_back(make_pair(make_pair(za,zb),zc));
	}
	vector<pi3>dat;
	for(int i=0;i<mat;i++)
	{
		dat.push_back(make_pair(make_pair(vec[i].first.first,0),i));
		dat.push_back(make_pair(make_pair(vec[i].first.second,2),i));
	}
	for(int i=0;i<num;i++)
	{
		dat.push_back(make_pair(make_pair(i,1),i));
	}
	sort(dat.begin(),dat.end());
	set<int>se;
	for(int i=0;i<dat.size();i++)
	{
		if(dat[i].first.second==0)
		{
			se.insert(dat[i].second);
		}
		if(dat[i].first.second==2)
		{
			se.erase(dat[i].second);
		}
		if(dat[i].first.second==1)
		{
			set<int>::iterator it=se.begin();
			for(;;)
			{
				if(it==se.end())
				{
					ans[dat[i].first.first]=0;
					break;
				}
				if(vec[*it].second!=dat[i].first.first)
				{
					ans[dat[i].first.first]=vec[*it].second+1;
					break;
				}
				it++;
			}
		}
	}
	for(int i=0;i<num;i++)
	{
		if(i!=0)
		{
			printf(" ");
		}
		printf("%d",ans[i]);
	}
	printf("\n");
}