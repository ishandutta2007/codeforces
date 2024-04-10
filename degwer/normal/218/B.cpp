#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
	int nin,num;
	scanf("%d%d",&nin,&num);
	priority_queue<int>que1;
	priority_queue<int>que2;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		que1.push(-zan);
		que2.push(zan);
	}
	int ans1=0,ans2=0;
	for(int i=0;i<nin;i++)
	{
		int zan=que1.top();
		que1.pop();
		ans1-=zan;
		zan++;
		if(zan!=0)
		{
			que1.push(zan);
		}
		zan=que2.top();
		que2.pop();
		ans2+=zan;
		zan--;
		if(zan!=0)
		{
			que2.push(zan);
		}
	}
	printf("%d %d\n",ans2,ans1);
}