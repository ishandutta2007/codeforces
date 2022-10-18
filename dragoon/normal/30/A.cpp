#include<stdio.h>

#define ABS(X) ((X)>0?(X):(-(X)))

int main()
{
	int a,b,n,i,now,x;

	scanf("%d%d%d",&a,&b,&n);

	if(a==0)
	{
		if(b==0) printf("1\n");
		else printf("No solution\n");
		return 0;
	}

	if( ABS(b)%ABS(a) )
	{
		printf("No solution\n");
		return 0;
	}

	b/=a;
	for(x=-1000;x<=1000;x++)
	{
		if(x==3)
			x=3;

		now = 1;
		for(i=1;i<=n;i++)
		{
			now*=x;
			if(ABS(x)>2 && ABS(now)>ABS(b)) break;
		}

		if(i==n+1 && now == b)
		{
			printf("%d\n",x);
			return 0;
		}
	}

	printf("No solution\n");

	return 0;
}