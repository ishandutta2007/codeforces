#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
bool flag[100000];
int main()
{
	int num;
	scanf("%d",&num);
	vector<int>vec;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		zan--;
		vec.push_back(zan);
	}
	vector<vector<int> >dat;
	fill(flag,flag+100000,false);
	int t1=-1,t21=-1,t22=-1;
	for(int i=0;i<num;i++)
	{
		if(flag[i])continue;
		int now=i;
		vector<int>v;
		for(;;)
		{
			v.push_back(now);
			flag[now]=true;
			now=vec[now];
			if(now==i)break;
		}
		if(v.size()==1)t1=i;
		else if(v.size()==2)
		{
			t21=i;
			t22=vec[i];
		}
		dat.push_back(v);
	}
	if(t1!=-1)
	{
		printf("YES\n");
		for(int i=0;i<num;i++)
		{
			if(i!=t1)printf("%d %d\n",i+1,t1+1);
		}
		return 0;
	}
	else if(t21!=-1)
	{
		bool fl=true;
		for(int i=0;i<dat.size();i++)
		{
			if(dat[i].size()%2!=0)fl=false;
		}
		if(fl)
		{
			printf("YES\n");
			printf("%d %d\n",t21+1,t22+1);
			for(int i=0;i<dat.size();i++)
			{
				if(dat[i][0]!=t21&&dat[i][0]!=t22)
				{
					for(int j=0;j<dat[i].size();j++)
					{
						if(j%2==0)printf("%d %d\n",t21+1,dat[i][j]+1);
						else printf("%d %d\n",t22+1,dat[i][j]+1);
					}
				}
			}
			return 0;
		}
	}
	printf("NO\n");
}