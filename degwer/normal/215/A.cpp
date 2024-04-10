#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int numa,numb;
	vector<int>va,vb;
	scanf("%d",&numa);
	for(int i=0;i<numa;i++)
	{
		int zan;
		scanf("%d",&zan);
		va.push_back(zan);
	}
	scanf("%d",&numb);
	for(int i=0;i<numb;i++)
	{
		int zan;
		scanf("%d",&zan);
		vb.push_back(zan);
	}
	int maxi=0,num=1;
	for(int i=0;i<numa;i++)
	{
		for(int j=0;j<numb;j++)
		{
			if(vb[j]%va[i]==0)
			{
				if(maxi==vb[j]/va[i])
				{
					num++;
				}
				if(maxi<vb[j]/va[i])
				{
					maxi=vb[j]/va[i];
					num=1;
				}
			}
		}
	}
	printf("%d\n",num);
}