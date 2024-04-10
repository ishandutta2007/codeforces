#include<stdio.h>
typedef long long ll;
ll hai[1000000];
int main()
{
	ll num,gen;
	scanf("%I64d%I64d",&num,&gen);
	for(int i=0;i<gen;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--;
		zb--;
		hai[za]++;
		hai[zb]++;
	}
	ll ret=num*(num-1)*(num-2)/6;
	ret-=(num-2)*gen;
	for(int i=0;i<num;i++)
	{
		ret+=(hai[i]*(hai[i]-1))/2;
	}
	printf("%I64d\n",ret);
}