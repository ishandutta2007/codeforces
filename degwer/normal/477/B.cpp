#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n",b*(6*(a-1)+5));
	for(int i=0;i<a;i++)
	{
		if(i%2==0)
		{
			printf("%d %d %d %d\n",b*(6*(i/2)+2),b*(6*i+1),b*(6*i+3),b*(6*i+5));
		}
		else
		{
			printf("%d %d %d %d\n",b*(6*(i/2)+4),b*(6*i+1),b*(6*i+3),b*(6*i+5));
		}
	}
}