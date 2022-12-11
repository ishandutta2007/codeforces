#include<cstdio>
int main()
{
	int n,k,i;
	scanf("%d%d",&n,&k);
	k=240-k;
	for(i=1;k>=5*i&&i<=n;++i)k-=5*i;
	printf("%d",i-1);
}