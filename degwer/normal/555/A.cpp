#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num,way;
	scanf("%d%d",&num,&way);
	int ans=(num-1)*2-(way-1);
	for(int i=0;i<way;i++)
	{
		int z;
		scanf("%d",&z);
		vector<int>v;
		for(int j=0;j<z;j++)
		{
			int zan;
			scanf("%d",&zan);
			v.push_back(zan);
		}
		if(v[0]==1)
		{
			for(int j=1;j<v.size();j++)
			{
				if(v[j]==j+1)ans-=2;
			}
		}
	}
	printf("%d\n",ans);
}