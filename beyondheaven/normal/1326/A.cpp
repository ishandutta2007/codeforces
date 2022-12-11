#include<cstdio>
int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n==1){puts("-1");continue;}
		else
		{
			for(int i=1;i<n;++i)
			putchar('9');
			putchar('8');
			puts("");
		}
	}
	return 0;
}