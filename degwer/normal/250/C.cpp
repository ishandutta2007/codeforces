#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int ans[100000];
int main()
{
	int num,gen;
	scanf("%d%d",&num,&gen);
	vector<int>vec;
	vec.push_back(0);
	int now=0;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		if(now!=zan)
		{
			now=zan;
			vec.push_back(now);
		}
	}
	vec.push_back(0);
	for(int i=1;i<vec.size()-1;i++)
	{
		if(vec[i-1]==vec[i+1])
		{
			ans[vec[i]-1]+=2;
		}
		else
		{
			ans[vec[i]-1]+=1;
		}
	}
	int maxi=0;
	int rr;
	for(int i=0;i<gen;i++)
	{
		if(maxi<ans[i])
		{
			maxi=ans[i];
			rr=i+1;
		}
	}
	printf("%d\n",rr);
}