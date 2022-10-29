#include<stdio.h>
int main()
{
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	for(int i=0;i<b;i++)
	{
		for(int j=0;j<b;j++)
		{
			if(c-i*e+d-j*f==a)
			{
				printf("YES\n");
				return 0;
			}
		}
		if(c-i*e==a||d-i*f==a||a==0)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
}