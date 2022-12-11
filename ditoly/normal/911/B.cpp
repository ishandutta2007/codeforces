#include<cstdio>
int main()
{
	int n,a,b,i;
	scanf("%d%d%d",&n,&a,&b);
	for(i=100;;--i)if(a>=i&&b>=i&&a/i+b/i>=n)break;
	printf("%d",i);
}