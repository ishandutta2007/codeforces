#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pii;
vector<pii>pat[1000];
vector<pii>spat[1000];
ll flag[1000][1000];
bool flag2[1000];
int main()
{
	int cit,way,stp,gop;
	scanf("%d%d%d%d",&cit,&way,&stp,&gop);
	stp--;
	gop--;
	for(int i=0;i<way;i++)
	{
		ll za,zb,zc;
		scanf("%I64d%I64d%I64d",&za,&zb,&zc);
		za--;
		zb--;
		pat[za].push_back(make_pair(zb,zc));
		pat[zb].push_back(make_pair(za,zc));
	}
	for(int p=0;p<cit;p++)
	{
		priority_queue<pii>que;
		for(int i=0;i<cit;i++)
		{
			flag[p][i]=-1;
		}
		que.push(make_pair(0,p));
		for(;;)
		{
			if(que.empty())
			{
				break;
			}
			pii zan=que.top();
			que.pop();
			if(flag[p][zan.second]!=-1)
			{
				continue;
			}
			flag[p][zan.second]=-zan.first;
			for(int i=0;i<pat[zan.second].size();i++)
			{
				que.push(make_pair(zan.first-pat[zan.second][i].second,pat[zan.second][i].first));
			}
		}
	}
	for(int i=0;i<cit;i++)
	{
		ll za,zb;
		scanf("%I64d%I64d",&za,&zb);
		for(int j=0;j<cit;j++)
		{
			if(i!=j&&flag[i][j]!=-1&&flag[i][j]<=za)
			{
				spat[i].push_back(make_pair(j,zb));
			}
		}
	}
	priority_queue<pii>que;
	fill(flag2,flag2+cit,false);
	que.push(make_pair(0,stp));
	for(;;)
	{
		if(que.empty())
		{
			printf("-1\n");
			break;
		}
		pii zan=que.top();
		que.pop();
		if(zan.second==gop)
		{
			printf("%I64d\n",-zan.first);
			break;
		}
		if(flag2[zan.second])
		{
			continue;
		}
		flag2[zan.second]=true;
		for(int i=0;i<spat[zan.second].size();i++)
		{
			que.push(make_pair(zan.first-spat[zan.second][i].second,spat[zan.second][i].first));
		}
	}
}