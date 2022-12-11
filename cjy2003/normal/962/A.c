#include<stdio.h>
#include<string.h>
int a[200001];
long long sum,sum1;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum1+=a[i];
		if(sum1*2>=sum)
		{
			printf("%d",i);
			break;	
		}	
	}
	
	return 0;
}