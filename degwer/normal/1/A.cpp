#include<stdio.h>
int main()
{
	long long a,b,c;
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	printf("%I64d\n",((a+c-1)/c)*((b+c-1)/c));
}