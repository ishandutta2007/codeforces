#include<stdio.h>
#include<math.h>
int main()
{
	int num;
	scanf("%d",&num);
	int sum=num;
	for(int i=2;;i++)
	{
		if(i>sqrt(double(num))+1)
		{
			break;
		}
		for(;;)
		{
			if(num%i!=0)
			{
				break;
			}
			num/=i;
			sum+=num;
		}
	}
	if(num!=1)
	{
		sum++;
	}
	printf("%d\n",sum);
}