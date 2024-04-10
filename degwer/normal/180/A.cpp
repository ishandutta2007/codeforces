#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int main()
{
	int num,hoge;
	scanf("%d%d",&num,&hoge);
	vector<pair<int,int> >ans;
	vector<int>vec;
	for(int i=0;i<num;i++)
	{
		vec.push_back(-1);
	}
	int now=0;
	for(int j=0;j<hoge;j++)
	{
		int fuga;
		scanf("%d",&fuga);
		for(int k=0;k<fuga;k++)
		{
			int zan;
			scanf("%d",&zan);
			zan--;
			vec[zan]=now;
			now++;
		}
	}
	if(vec[now]!=-1)
	{
		for(int l=0;l<now;l++)
		{
			if(vec[l]==-1)
			{
				vec[l]=vec[now];
				vec[now]=-1;
				ans.push_back(make_pair(now,l));
				break;
			}
		}
	}
	for(int m=0;m<num;m++)
	{
		if(vec[m]!=m&&vec[m]!=-1)
		{
						//printf("iuhkjnk\n");
			int str=m;
			stack<int>sta;
			for(;;)
			{
				sta.push(str);
				str=vec[str];
				if(str==m||str==-1)
				{
					int piyo=now;
					for(;;)
					{
						if(sta.empty())
						{
							break;
						}
						ans.push_back(make_pair(sta.top(),piyo));
						vec[piyo]=vec[sta.top()];
						piyo=sta.top();
						sta.pop();
					}
					ans.push_back(make_pair(now,piyo));
					vec[piyo]=vec[now];
					vec[now]=-1;
					break;
				}
			}
		}
	}
	printf("%d\n",ans.size());
	for(int n=0;n<ans.size();n++)
	{
		printf("%d %d\n",ans[n].first+1,ans[n].second+1);
	}
}