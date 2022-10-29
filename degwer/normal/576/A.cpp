#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	scanf("%d",&num);
	vector<int>ans;
	for(int i=2;i<=num;i++)
	{
		bool f=true;
		for(int j=2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				f=false;
				break;
			}
		}
		if(f)
		{
			int now=i;
			for(;;)
			{
				if(now>num)break;
				ans.push_back(now);
				now*=i;
			}
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0)printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
}