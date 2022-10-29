#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
queue<int>que;
vector<int>kin;
vector<int>now;
vector<int>pat[100000];
vector<bool>flip;
int main()
{
	int cit,way;
	scanf("%d%d",&cit,&way);
	for(int i=0;i<way;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	for(int i=0;i<cit;i++)
	{
		pat[i].push_back(i);
		int zan;
		scanf("%d",&zan);
		kin.push_back(zan);
		now.push_back(0);
		flip.push_back(false);
		if(!zan)
		{
			que.push(i);
		}
	}
	for(int p=0;;p++)
	{
		if(p>500000)
		{
			printf("-1\n");
		}
		if(que.empty())
		{
			break;
		}
		int zan=que.front();
		que.pop();
		if(now[zan]!=kin[zan])
		{
			continue;
		}
		int r=pat[zan][rand()%pat[zan].size()];
		for(int i=0;i<pat[r].size();i++)
		{
			if(flip[r])
			{
				now[pat[r][i]]--;
			}
			else
			{
				now[pat[r][i]]++;
			}
			if(now[pat[r][i]]==kin[pat[r][i]])
			{
				que.push(pat[r][i]);
			}
		}
		if(flip[r])
		{
			flip[r]=false;
		}
		else
		{
			flip[r]=true;
		}
	}
	vector<int>ans;
	for(int i=0;i<cit;i++)
	{
		if(flip[i])
		{
			ans.push_back(i);
		}
	}
	printf("%d\n",int(ans.size()));
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0)
		{
			printf(" ");
		}
		printf("%d",ans[i]+1);
	}
	printf("\n");
}