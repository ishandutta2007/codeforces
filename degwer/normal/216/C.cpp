#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int wo,re,nin;
	scanf("%d%d%d",&wo,&re,&nin);
	int hai[4000];
	bool key[4001];
	fill(hai,hai+4000,0);
	fill(key,key+4001,false);
	vector<int>ans;
	for(int i=0;i<wo+re;i++)
	{
		if(hai[i]<nin)
		{
			for(int j=0;j<nin-hai[i];j++)
			{
				ans.push_back(i+1);
			}
			int p=nin-hai[i];
			for(int j=0;j<wo;j++)
			{
				hai[i+j]+=p;
				key[i+j]=true;
			}
		}
		if(!key[i+1])
		{
			ans.push_back(i+1);
			for(int j=0;j<wo;j++)
			{
				hai[i+j]++;
				key[i+j]=true;
			}
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0)
		{
			printf(" ");
		}
		printf("%d",ans[i]);
	}
	printf("\n");
}