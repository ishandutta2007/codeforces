#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll v[4000],d[4000],p[4000];
bool fl[4000];
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%I64d%I64d%I64d",&v[i],&d[i],&p[i]);
	}
	fill(fl,fl+4000,false);
	vector<ll>ans;
	for(int i=0;i<num;i++)
	{
		if(!fl[i])
		{
			ans.push_back(i+1);
			ll now=v[i];
			for(int j=i+1;j<num;j++)
			{
				if(now==0)break;
				if(!fl[j])
				{
					p[j]-=now;
					now--;
				}
			}
			for(int j=i+1;j<num;j++)
			{
				if((!fl[j])&&p[j]<0)
				{
					fl[j]=true;
					for(int k=j+1;k<num;k++)p[k]-=d[j];
				}
			}
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0)printf(" ");
		printf("%I64d",ans[i]);
	}
	printf("\n");
}