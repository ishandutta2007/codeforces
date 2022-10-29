#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll solve(ll hen,ll sx,ll sy,ll tim)
{
	ll ret=(tim+1)*(tim+1)+tim*tim;
	ll sx2=hen-sx;
	ll sy2=hen-sy;
	sx--;
	sy--;
	if(tim>sx)
	{
		ret-=(tim-sx)*(tim-sx);
	}
	if(tim>sy)
	{
		ret-=(tim-sy)*(tim-sy);
	}
	if(tim>sx2)
	{
		ret-=(tim-sx2)*(tim-sx2);
	}
	if(tim>sy2)
	{
		ret-=(tim-sy2)*(tim-sy2);
	}
	if(tim>=sx+sy+2)
	{
		ret+=(tim-sx-sy)*(tim-sx-sy-1)/2;
	}
	if(tim>=sx+sy2+2)
	{
		ret+=(tim-sx-sy2)*(tim-sx-sy2-1)/2;
	}
	if(tim>=sx2+sy+2)
	{
		ret+=(tim-sx2-sy)*(tim-sx2-sy-1)/2;
	}
	if(tim>=sx2+sy2+2)
	{
		ret+=(tim-sx2-sy2)*(tim-sx2-sy2-1)/2;
	}
	return ret;
}
int main()
{
	ll hen,sx,sy,gen;
	scanf("%I64d%I64d%I64d%I64d",&hen,&sx,&sy,&gen);
	ll beg=0,end=2000000000;
	for(;;)
	{
		ll med=(beg+end)/2;
		if(solve(hen,sx,sy,med)<gen)
		{
			beg=med+1;
		}
		else
		{
			end=med;
		}
		if(beg==end)
		{
			printf("%I64d\n",beg);
			return 0;
		}
	}
}