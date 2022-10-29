#include<stdio.h>
int main()
{
	int tux;
	scanf("%d",&tux);
	int foo=0,bar=0,baz=0,quz=0;
	for(;;)
	{
		if(tux==0)
		{
			break;
		}
		tux--;
		int pur;
		scanf("%d",&pur);
		foo=foo+pur;
		bar++;
		if(foo*quz>=bar*baz)
		{
			baz=foo;
			quz=bar;
		}
	}
	printf("%lf\n",double(baz)/double(quz));
}