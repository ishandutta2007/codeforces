#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pii;
typedef pair<pii,ll>pi3;
int ans[200000];
int main()
{
	int num,way;
	scanf("%d%d",&num,&way);
	vector<pii>dat;
	vector<pi3>vec;
	for(int i=0;i<num;i++)
	{
		ll za,zb;
		scanf("%I64d%I64d",&za,&zb);
		dat.push_back(make_pair(za,zb));
	}
	for(int i=0;i<num-1;i++)
	{
		vec.push_back(make_pair(make_pair(dat[i+1].first-dat[i].second,dat[i+1].second-dat[i].first),i));
	}
	for(int i=0;i<way;i++)
	{
		ll zan;
		scanf("%I64d",&zan);
		vec.push_back(make_pair(make_pair(zan,2000000000000000000LL),-i-1));
	}
	sort(vec.begin(),vec.end());
	priority_queue<pii>que;
	int cnt=0;
	for(int i=0;i<vec.size();i++)
	{
		if(vec[i].second>=0)
		{
			que.push(make_pair(-vec[i].first.second,vec[i].second));
		}
		else
		{
			if(que.empty())
			{
				continue;
			}
			pii zan=que.top();
			if(-zan.first>=vec[i].first.first)
			{
				ans[zan.second]=-vec[i].second;
				que.pop();
				cnt++;
			}
		}
	}
	if(cnt!=num-1)printf("No\n");
	else
	{
		printf("Yes\n");
		for(int i=0;i<num-1;i++)
		{
			if(i!=0)printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
	}
}