#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<pii,pii>pi4;
vector<pi4>pat[200000];
int costsum[200000];
int nowcost[200000];
int ans[200000];
int main()
{
	int cit,way;
	scanf("%d%d",&cit,&way);
	for(int i=0;i<way;i++)
	{
		int za,zb,zc;
		scanf("%d%d%d",&za,&zb,&zc);
		za--;
		zb--;
		pat[za].push_back(make_pair(make_pair(zb,zc),make_pair(0,i)));
		pat[zb].push_back(make_pair(make_pair(za,zc),make_pair(1,i)));
		costsum[za]+=zc;
		costsum[zb]+=zc;
	}
	queue<int>que;
	costsum[cit-1]=-1;
	fill(ans,ans+200000,-1);
	for(int i=0;i<pat[0].size();i++)
	{
		nowcost[pat[0][i].first.first]+=pat[0][i].first.second;
		ans[pat[0][i].second.second]=pat[0][i].second.first;
		if(nowcost[pat[0][i].first.first]*2==costsum[pat[0][i].first.first])
		{
			que.push(pat[0][i].first.first);
		}
	}
	for(;;)
	{
		if(que.empty())
		{
			break;
		}
		int zan=que.front();
		que.pop();
		for(int i=0;i<pat[zan].size();i++)
		{
			if(ans[pat[zan][i].second.second]==-1)
			{
				ans[pat[zan][i].second.second]=pat[zan][i].second.first;
				nowcost[pat[zan][i].first.first]+=pat[zan][i].first.second;
				if(nowcost[pat[zan][i].first.first]*2==costsum[pat[zan][i].first.first])
				{
					que.push(pat[zan][i].first.first);
				}
			}
		}
	}
	for(int i=0;i<way;i++)
	{
		printf("%d\n",ans[i]);
	}
}