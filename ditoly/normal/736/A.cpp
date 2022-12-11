#include<cstdio>
int main()
{
	long long n,i,a=2,b=1;
	scanf("%I64d",&n);
	for(i=1;a+b<=n;i++){a+=b;b=a-b;}
	printf("%d",i);
}