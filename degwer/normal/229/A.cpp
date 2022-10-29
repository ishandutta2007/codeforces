#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>vec[100];
int main()
{
	int mx,my;
	scanf("%d%d",&mx,&my);
	for(int i=0;i<mx;i++)
	{
		for(int j=0;j<my;j++)
		{
			char zan;
			scanf(" %c",&zan);
			if(zan=='1')
			{
				vec[i].push_back(j);
				vec[i].push_back(my+j);
				vec[i].push_back(my+my+j);
			}
		}
		if(vec[i].empty())
		{
			printf("-1\n");
			return 0;
		}
		sort(vec[i].begin(),vec[i].end());
	}
	int mini=2000000000;
	for(int i=0;i<my;i++)
	{
		int sum=0;
		for(int j=0;j<mx;j++)
		{
			int low=lower_bound(vec[j].begin(),vec[j].end(),i+my)-vec[j].begin();
			int low2=low-1;
			sum+=min(i+my-vec[j][low2],vec[j][low]-i-my);
		}
		mini=min(mini,sum);
	}
	printf("%d\n",mini);
}