#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	scanf("%d",&num);
	int ko=10000000;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		ko=min(ko,zan);
	}
	int q;
	scanf("%d",&q);
	vector<int>vec;
	for(int i=0;i<q;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
	}
	sort(vec.begin(),vec.end());
	reverse(vec.begin(),vec.end());
	int ans=0;
	int now=ko;
	for(int i=0;i<q;i++)
	{
		if(now>0)
		{
			ans+=vec[i];
		}
		if(now==-1)
		{
			now=ko+1;
		}
		now--;
	}
	printf("%d\n",ans);
}