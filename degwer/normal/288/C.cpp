#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int ans[1000001];
int main()
{
	int num;
	scanf("%d",&num);
	int zn=num;
	ll sum=0;
	for(;;)
	{
		if(num<=0)
		{
			break;
		}
		int nb;
		for(int i=0;;i++)
		{
			if((1<<i)>num)
			{
				nb=(1<<(i-1));
				break;
			}
		}
		for(int i=nb-(num-nb)-1;i<=num;i++)
		{
			ans[i]=(nb*2)-1-i;
			sum+=(nb*2)-1;
		}
		num=nb-(num-nb)-1-1;
	}
	printf("%I64d\n",sum);
	for(int i=0;i<=zn;i++)
	{
		if(i!=0)
		{
			printf(" ");
		}
		printf("%d",ans[i]);
	}
	printf("\n");
}