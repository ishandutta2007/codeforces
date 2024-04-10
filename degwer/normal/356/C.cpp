#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
using namespace std;
typedef pair<int,int>pii;
int dat[5];
int main()
{
	int num;
	scanf("%d",&num);
	int sum=0;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		dat[zan]++;
		sum+=zan;
	}
	for(int i=1;i<=4;i++)
	{
		dat[i]+=dat[i-1];
	}
	int mini=1000000000;
	for(int i=0;i<=num;i++)
	{
		if((sum-i*4)<0)
		{
			continue;
		}
		if((sum-i*4)%3!=0)
		{
			continue;
		}
		int z0,z3,z4;
		z4=i;
		z3=(sum-i*4)/3;
		z0=num-z4-z3;
		if(z0<0)
		{
			continue;
		}
		vector<pii>vec;
		vec.push_back(make_pair(0,0));
		for(int j=0;j<4;j++)
		{
			vec.push_back(make_pair(dat[j],j+1));
		}
		vec.push_back(make_pair(0,5));
		vec.push_back(make_pair(z0,8));
		vec.push_back(make_pair(z0+z3,9));
		sort(vec.begin(),vec.end());
		int ret=0;
		int now=0;
		int n1=0,n2=0;
		for(int j=0;j<vec.size();j++)
		{
			ret+=abs(n1-n2)*(vec[j].first-now);
			now=vec[j].first;
			if(vec[j].second<5)
			{
				n1=vec[j].second;
			}
			else
			{
				n2=vec[j].second-5;
			}
		}
		mini=min(mini,ret/2);
	}
	if(mini==1000000000)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n",mini);
	}
}