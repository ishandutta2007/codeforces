#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	scanf("%d",&num);
	vector<vector<int> >vec;
	for(int i=0;i<num;i++)
	{
		vector<int>damy;
		vec.push_back(damy);
		int zan;
		scanf("%d",&zan);
		for(int j=0;j<zan;j++)
		{
			int z;
			scanf("%d",&z);
			vec[i].push_back(z);
		}
		sort(vec[i].begin(),vec[i].end());
	}
	int ret=0;
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<vec[i].size()-1;j++)
		{
			int low1=lower_bound(vec[(i+num-1)%num].begin(),vec[(i+num-1)%num].end(),vec[i][j])-vec[(i+num-1)%num].begin();
			int low2=lower_bound(vec[(i+num-1)%num].begin(),vec[(i+num-1)%num].end(),vec[i][j+1])-vec[(i+num-1)%num].begin();
			int low3=lower_bound(vec[(i+num+1)%num].begin(),vec[(i+num+1)%num].end(),vec[i][j])-vec[(i+num+1)%num].begin();
			int low4=lower_bound(vec[(i+num+1)%num].begin(),vec[(i+num+1)%num].end(),vec[i][j+1])-vec[(i+num+1)%num].begin();
			if(low2-low1!=low4-low3)
			{
				ret++;
			}
		}
	}
	printf("%d\n",ret);
}