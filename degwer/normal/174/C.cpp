#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int num;
	scanf("%d",&num);
	vector<int>vecb;
	vector<int>vece;
	int bef=0;
	int aft;
	for(int i=0;i<num;i++)
	{
		scanf("%d",&aft);
		if(aft>bef)
		{
			for(int j=0;j<aft-bef;j++)
			{
				vecb.push_back(i+1);
			}
		}
		else
		{
			for(int k=0;k<bef-aft;k++)
			{
				vece.push_back(i);
			}
		}
		bef=aft;
	}
	for(int l=0;l<bef;l++)
	{
		vece.push_back(num);
	}
	sort(vecb.begin(),vecb.end());
	sort(vece.begin(),vece.end());
	printf("%d\n",vecb.size());
	for(int m=0;m<vecb.size();m++)
	{
		printf("%d %d\n",vecb[m],vece[m]);
	}
}