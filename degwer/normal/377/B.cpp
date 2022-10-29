#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;
typedef pair<int,int>pii;
typedef pair<pii,int>pi3;
vector<pii>ans;
bool calc(vector<pi3>stu,vector<pii>vec,int med,int gen)
{
	//printf("query::%d\n",med);
	ans.clear();
	priority_queue<pii>que;
	int ret=0;
	int now=0;
	int pt=0;
	for(;;)
	{
		if(pt==stu.size())
		{
			goto l01;
		}
		if(stu[pt].first.first<vec[now].first)
		{
			l01:;
			if(que.empty())
			{
				return false;
			}
			pii zan=que.top();
			que.pop();
			zan.first=-zan.first;
			ret+=zan.first;
			//printf("   %d %d\n",zan.first,zan.second);
			for(int j=0;j<med;j++)
			{
				if(now+j<vec.size())
				{
					ans.push_back(make_pair(vec[now+j].second,zan.second));
					//printf("%d %d\n",vec[now+j].second,zan.second);
				}
			}
			if(ret>gen)
			{
				return false;
			}
			now+=med;
			if(now>=vec.size())
			{
				break;
			}
		}
		else
		{
			que.push(make_pair(-stu[pt].first.second,stu[pt].second));
			//printf("add::%d %d\n",stu[pt].first.second,stu[pt].second);
			pt++;
		}
	}
	if(ret<=gen)
	{
		return true;
	}
	return false;
}
int ou[100000];
int main()
{
	int num,wor,gen;
	scanf("%d%d%d",&num,&wor,&gen);
	vector<pii>vec;
	for(int i=0;i<wor;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(make_pair(zan,i));
	}
	sort(vec.begin(),vec.end());
	reverse(vec.begin(),vec.end());
	vector<pi3>stu;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		stu.push_back(make_pair(make_pair(zan,0),i));
	}
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		stu[i].first.second=zan;
	}
	sort(stu.begin(),stu.end());
	reverse(stu.begin(),stu.end());
	if(!calc(stu,vec,wor,gen))
	{
		printf("NO\n");
		return 0;
	}
	else
	{
		printf("YES\n");
	}
	int beg=1,end=wor;
	for(;;)
	{
		int med=(beg+end)/2;
		if(calc(stu,vec,med,gen))
		{
			end=med;
		}
		else
		{
			beg=med+1;
		}
		if(beg==end)
		{
			//printf("%d\n",beg);
			calc(stu,vec,beg,gen);
			break;
		}
	}
	for(int i=0;i<ans.size();i++)
	{
		ou[ans[i].first]=ans[i].second+1;
	}
	for(int i=0;i<wor;i++)
	{
		if(i!=0)
		{
			printf(" ");
		}
		printf("%d",ou[i]);
	}
	printf("\n");
}