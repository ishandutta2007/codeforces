#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int>pii;
int left[100002];
int right[100002];
int main()
{
	int num;
	scanf("%d",&num);
	vector<int>vec;
	vec.push_back(2000000000);
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
	}
	vec.push_back(2000000000);
	priority_queue<pii>que;
	for(int i=0;i<vec.size();i++)
	{
		que.push(make_pair(-vec[i],i));
		for(;;)
		{
			if(que.empty())
			{
				break;
			}
			pii zan=que.top();
			zan.first=-zan.first;
			if(zan.first>=vec[i])
			{
				break;
			}
			else
			{
				que.pop();
				right[zan.second]=vec[i];
			}
		}
	}
	for(int i=vec.size()-1;i>=0;i--)
	{
		que.push(make_pair(-vec[i],i));
		for(;;)
		{
			if(que.empty())
			{
				break;
			}
			pii zan=que.top();
			zan.first=-zan.first;
			if(zan.first>=vec[i])
			{
				break;
			}
			else
			{
				que.pop();
				left[zan.second]=vec[i];
			}
		}
	}
	int maxi=0;
	for(int i=1;i<=num;i++)
	{
		if(left[i]!=2000000000)
		{
			maxi=max(maxi,vec[i]^left[i]);
		}
		if(right[i]!=2000000000)
		{
			maxi=max(maxi,vec[i]^right[i]);
		}
	}
	printf("%d\n",maxi);
}