#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	scanf("%d",&num);
	vector<int>vec;
	int a1=0,a2=0;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vector<int>v;
		for(int i=0;i<zan;i++)
		{
			int z;
			scanf("%d",&z);
			v.push_back(z);
		}
		if(zan%2==0)
		{
			for(int i=0;i<zan/2;i++)
			{
				a1+=v[i];
			}
			for(int i=zan/2;i<zan;i++)
			{
				a2+=v[i];
			}
		}
		else
		{
			for(int i=0;i<zan/2;i++)
			{
				a1+=v[i];
			}
			for(int i=zan/2+1;i<zan;i++)
			{
				a2+=v[i];
			}
			vec.push_back(v[zan/2]);
		}
	}
	sort(vec.begin(),vec.end());
	reverse(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++)
	{
		if(i%2==0)
		{
			a1+=vec[i];
		}
		else
		{
			a2+=vec[i];
		}
	}
	printf("%d %d\n",a1,a2);
}