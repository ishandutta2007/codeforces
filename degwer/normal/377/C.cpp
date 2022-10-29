#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int>pii;
int dp[1048576];
int main()
{
	int num;
	scanf("%d",&num);
	vector<int>vec;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
	}
	sort(vec.begin(),vec.end());
	reverse(vec.begin(),vec.end());
	int query;
	scanf("%d",&query);
	vector<pii>que;
	for(int i=0;i<query;i++)
	{
		char zan;
		int z;
		scanf(" %c%d",&zan,&z);
		if(zan=='p')
		{
			que.push_back(make_pair(z,0));
		}
		else
		{
			que.push_back(make_pair(z,1));
		}
	}
	for(int p=0;p<(1<<query);p++)
	{
		int now=0;
		for(int i=0;i<query;i++)
		{
			if(p&(1<<i))
			{
				now++;
			}
		}
		if(now==0)
		{
			dp[p]=0;
		}
		else
		{
			if(que[query-now].first==1)
			{
				dp[p]=-1000000000;
			}
			else
			{
				dp[p]=1000000000;
			}
		}
	}
	for(int p=1;p<(1<<query);p++)
	{
		int now=0;
		for(int i=0;i<query;i++)
		{
			if(p&(1<<i))
			{
				now++;
			}
		}
		for(int i=0;i<query;i++)
		{
			if(p&(1<<i))
			{
				if(que[query-now].first==1)
				{
					if(que[query-now].second==0)
					{
						dp[p]=max(dp[p],dp[p-(p&(1<<i))]+vec[i]);
					}
					else
					{
						dp[p]=max(dp[p],dp[p-(p&(1<<i))]);
					}
				}
				else
				{
					if(que[query-now].second==0)
					{
						dp[p]=min(dp[p],dp[p-(p&(1<<i))]-vec[i]);
					}
					else
					{
						dp[p]=min(dp[p],dp[p-(p&(1<<i))]);
					}
				}
			}
		}
	}
	printf("%d\n",dp[(1<<query)-1]);
}