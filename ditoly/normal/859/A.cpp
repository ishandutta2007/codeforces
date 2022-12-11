#include<cstdio>
int main()
{
	int n,i,x,mx=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&x),x>mx?mx=x:0;
	printf("%d",mx>25?mx-25:0);
}