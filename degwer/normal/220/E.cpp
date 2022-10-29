#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
class BIT
{
public:
	ll bit[131073];
	void add(int a,ll b)
	{
		for(;;)
		{
			if(a>=131072)
			{
				break;
			}
			bit[a]+=b;
			a+=a&-a;
		}
	}
	ll sum(int a)
	{
		ll ret=0;
		for(;;)
		{
			if(a==0)
			{
				break;
			}
			ret+=bit[a];
			a-=a&-a;
		}
		return ret;
	}
};
BIT fro,bac;
ll rui1[100001];
ll rui2[100001];
int main()
{
	int num;
	ll gen;
	scanf("%d%I64d",&num,&gen);
	vector<int>vec,zv,uni;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
		zv.push_back(zan);
	}
	sort(zv.begin(),zv.end());
	int now=-1;
	for(int i=0;i<num;i++)
	{
		if(now!=zv[i])
		{
			now=zv[i];
			uni.push_back(now);
		}
	}
	for(int i=0;i<num;i++)
	{
		int low=lower_bound(uni.begin(),uni.end(),vec[i])-uni.begin()+1;
		vec[i]=low;
	}
	for(int i=0;i<num;i++)
	{
		fro.add(vec[i],1);
		rui1[i+1]=rui1[i]+fro.sum(130000)-fro.sum(vec[i]);
	}
	ll ret=0;
	int pt=num-1;
	ll ans=rui1[num];
	if(rui1[num]<=gen)
	{
		ret=num;
		ret*=num-1;
		ret/=2;
		printf("%I64d\n",ret);
		return 0;
	}
	for(int i=num-1;i>=0;i--)
	{
		for(;;)
		{
			if(i>=pt)
			{
				break;
			}
			if(gen>=ans+bac.sum(vec[pt]-1)+fro.sum(130000)-fro.sum(vec[pt]))
			{
				ans+=bac.sum(vec[pt]-1)+fro.sum(130000)-fro.sum(vec[pt]);
				bac.add(vec[pt],1);
				pt--;
			}
			else
			{
				break;
			}
		}
		if(gen>=ans)
		{
			ret+=num-1-pt;
		}
		ans-=rui1[i+1]-rui1[i];
		ans-=bac.sum(vec[i]-1);
		fro.add(vec[i],-1);
	}
	printf("%I64d\n",ret);
}