#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int ans=0,u=0;
	for(;;)
	{
		ans+=a;
		u+=a;
		a=u/b;
		u%=b;
		if(a==0)
		{
			break;
		}
	}
	printf("%d\n",ans);
}