#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
	int num;
	scanf("%d",&num);
	vector<int>con;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		zan--;
		con.push_back(zan);
	}
	vector<int>pat[200];
	vector<int>frm[200];
	for(int i=0;i<num;i++)
	{
		int kaz;
		scanf("%d",&kaz);
		for(int j=0;j<kaz;j++)
		{
			int zan;
			scanf("%d",&zan);
			zan--;
			frm[i].push_back(zan);
			pat[zan].push_back(i);
		}
	}
	int mini=100000000;
	for(int p=0;p<3;p++)
	{
		int ans=0;
		int now=p;
		int han=0;
		bool flag[200];
		fill(flag,flag+200,false);
		queue<int>que[3];
		for(int i=0;i<num;i++)
		{
			if(frm[i].empty())
			{
				que[con[i]].push(i);
			}
		}
		for(;;)
		{
			if(han==num)
			{
				break;
			}
			for(;;)
			{
				if(que[now].empty())
				{
					now=(now+1)%3;
					ans++;
					break;
				}
				int zan=que[now].front();
				que[now].pop();
				if(flag[zan])
				{
					continue;
				}
				flag[zan]=true;
				han++;
				for(int i=0;i<pat[zan].size();i++)
				{
					bool jud=true;
					for(int j=0;j<frm[pat[zan][i]].size();j++)
					{
						if(!flag[frm[pat[zan][i]][j]])
						{
							jud=false;
							break;
						}
					}
					if(jud)
					{
						que[con[pat[zan][i]]].push(pat[zan][i]);
					}
				}
			}
		}
		mini=min(mini,ans);
	}
	printf("%d\n",mini-1+num);
}