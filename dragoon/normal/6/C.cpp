#include<stdio.h>

int t[100004],i,n,j;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&t[i]);

	if(n==1)
	{
		printf("1 0\n");
		return 0;
	}

	i=1;
	j=n;

	int a,b,last;

	a=b=0;

	last=1;

	while(i!=j)
	{
		if(a+t[i] < b+t[j])
		{
			a+=t[i];
			i++;
			last=1;
		}
		else if(a+t[i] > b+t[j])
		{
			b+=t[j];
			j--;
			last=2;
		}
		else
		{
			if(i==j-1)
			{
				printf("%d %d\n",i,n-i);
				return 0;
			}
			else if(i==j-2)
			{
				i++;
				printf("%d %d\n",i,n-i);
				return 0;
			}
			else
			{
				a+=t[i];
				b+=t[j];
				i++;
				j--;
			}
		}
	}

	if(last!=2)
		i--;

	printf("%d %d\n",i,n-i);

	return 0;
}