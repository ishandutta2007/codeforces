#include<cstdio>
int main()
{
	int n,i;
	scanf("%d",&n);
	printf("I hate");
	for(i=1;i<n;i++)printf(i&1?" that I love":" that I hate");
	printf(" it");
}