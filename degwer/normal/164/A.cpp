#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int>pat[100000];
vector<int>rpat[100000];
int pos[100000];
bool flag[100000];
bool rflag[100000];
int main()
{
	int cit,way;
	scanf("%d%d",&cit,&way);
	queue<int>que;
	queue<int>rque;
	for(int i=0;i<cit;i++)
	{
		scanf("%d",&pos[i]);
		if(pos[i]==1)
		{
			que.push(i);
		}
		if(pos[i]==2)
		{
			rque.push(i);
		}
	}
	for(int i=0;i<way;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;
		if(pos[zb]==1)
		{
			continue;
		}
		pat[za].push_back(zb);
		rpat[zb].push_back(za);
	}
	fill(flag,flag+cit,false);
	fill(rflag,rflag+cit,false);
	for(;;)
	{
		if(que.empty())
		{
			break;
		}
		int zan=que.front();
		que.pop();
		if(flag[zan])
		{
			continue;
		}
		flag[zan]=true;
		for(int i=0;i<pat[zan].size();i++)
		{
			if(pos[pat[zan][i]]!=1)
			{
				que.push(pat[zan][i]);
			}
		}
	}
	for(;;)
	{
		if(rque.empty())
		{
			break;
		}
		int zan=rque.front();
		rque.pop();
		if(rflag[zan])
		{
			continue;
		}
		rflag[zan]=true;
		for(int i=0;i<rpat[zan].size();i++)
		{
			rque.push(rpat[zan][i]);
		}
	}
	for(int i=0;i<cit;i++)
	{
		if(flag[i]&&rflag[i])
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}
	}
}