#include <stdio.h>
#include <math.h>
int main()
{
	long long int r,x,y,a,b;
	scanf("%I64d %I64d %I64d %I64d %I64d",&r,&x,&y,&a,&b);
	long long int d2=(x-a)*(x-a)+(y-b)*(y-b),d=sqrt(d2);
	if(d*d!=d2)d++;
	r*=2;
	x=d/r+(d%r!=0);
	printf("%I64d",x);
}