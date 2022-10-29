#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num,plu,mod;
	scanf("%d%d%d",&num,&plu,&mod);
	vector<int>hai;
	vector<int>add;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		hai.push_back(zan);
	}
	for(int j=0;j<plu;j++)
	{
		int zan;
		scanf("%d",&zan);
		add.push_back(zan);
	}
	int now=0;
	for(int k=0;k<num;k++)
	{
		if(k<plu)
		{
			now=(now+add[k])%mod;
		}
		if(k>num-plu)
		{
			now=(mod+now-add[plu-(num-k)-1])%mod;
		}
		if(k!=0)
		{
			printf(" %d",(hai[k]+now)%mod);
		}
		else
		{
			printf("%d",(hai[k]+now)%mod);
		}
	}
	printf("\n");
}