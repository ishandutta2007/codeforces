#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int query;
	scanf("%d",&query);
	vector<ll>vec;
	for(int i=0;i<query;i++)
	{
		ll zan;
		scanf("%I64d",&zan);
		vec.push_back(zan);
	}
	vector<ll>sho;
	for(int i=0;i<5;i++)
	{
		ll zan;
		scanf("%I64d",&zan);
		sho.push_back(zan);
	}
	reverse(sho.begin(),sho.end());
	ll ret[5];
	fill(ret,ret+5,0);
	ll now=0;
	for(int i=0;i<query;i++)
	{
		now+=vec[i];
		for(int i=0;i<5;i++)
		{
			ret[i]+=now/sho[i];
			now%=sho[i];
		}
	}
	for(int i=4;i>=0;i--)
	{
		if(i!=4)
		{
			printf(" ");
		}
		printf("%I64d",ret[i]);
	}
	printf("\n%I64d\n",now);
}