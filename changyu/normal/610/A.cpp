#include<cstdio>
int main()
{
	long long c;
	scanf("%I64d",&c);
	if(c%2==1)printf("0");
	else printf("%I64d",(c/2+1)/2-1);
	return 0;
}