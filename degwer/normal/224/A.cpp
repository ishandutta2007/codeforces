#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c;
	scanf("%lf%lf%lf",&a,&b,&c);
	double d=sqrt(a*b*c);
	printf("%.0lf\n",4*(d/a+d/b+d/c));
}