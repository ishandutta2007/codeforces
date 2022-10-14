#include<cstdio>
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) printf("%d ",j&1?(j-1)*n+i:j*n-i+1);
		printf("\n");
	}
	return 0;
}