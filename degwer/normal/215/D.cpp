#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int num,chi;
	scanf("%d%d",&num,&chi);
	ll ret=0;
	for(int i=0;i<num;i++)
	{
		ll a,b,x,cost;
		scanf("%I64d%I64d%I64d%I64d",&a,&b,&x,&cost);
		ll d=max(0LL,b-a);
		if(d==0)
		{
			ret+=cost+x*chi;
			continue;
		}
		ll k=chi/d+(chi%d!=0);
		ll m=chi%d;
		if(chi<=d)
		{
			ret+=cost;
			continue;
		}
		if(m==0)
		{
			ret+=min(cost*k,cost+x*chi);
		}
		else
		{
			ret+=min(cost*k,min(cost*(k-1)+(d+m)*x,cost+x*chi));
		}
	}
	printf("%I64d\n",ret);
}