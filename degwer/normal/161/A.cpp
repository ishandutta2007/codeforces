#include<stdio.h>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;
int main()
{
	int sold,vest,minus,plus;
	scanf("%d%d%d%d",&sold,&vest,&minus,&plus);
	vector<pair<int,int> >vecsol;
	deque<pair<int,int> >vecves;
	for(int i=1;i<=sold;i++)
	{
		int zan;
		scanf("%d",&zan);
		vecsol.push_back(make_pair(zan,i));
	}
	for(int j=1;j<=vest;j++)
	{
		int zan;
		scanf("%d",&zan);
		vecves.push_back(make_pair(zan,j));
	}
	sort(vecsol.begin(),vecsol.end());
	sort(vecves.begin(),vecves.end());
	vector<pair<int,int> >ret;
	for(int k=1;k<=vecsol.size();k++)
	{
		if(vecves.empty()==false)
		{
			int low=lower_bound(vecves.begin(),vecves.end(),make_pair(vecsol[k-1].first-minus,0))-vecves.begin();
			if(low==vecves.size())
			{
				continue;
			}
			if(vecves[low].first<=vecsol[k-1].first+plus)
			{
				ret.push_back(make_pair(vecsol[k-1].second,vecves[low].second));
				for(int l=0;l<=low;l++)
				{
					vecves.pop_front();
				}
			}
		}
	}
	printf("%d\n",ret.size());
	for(int m=1;m<=ret.size();m++)
	{
		printf("%d %d\n",ret[m-1].first,ret[m-1].second);
	}
}