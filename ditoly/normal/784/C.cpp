#include<cstdio>
int main()
{
	int n,i,mx=0,x;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&x),x>mx?mx=x:0;
	printf("%d",mx^x);
}