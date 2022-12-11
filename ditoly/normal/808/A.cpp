#include<cstdio>
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;n/(i*10);i*=10);
	printf("%d",n/i*i+i-n);
}