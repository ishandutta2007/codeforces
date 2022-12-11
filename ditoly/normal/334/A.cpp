#include<cstdio>
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;++i,puts(""))for(j=1;j<=n;++j)printf("%d ",(j-1)*n+(i+j)%n+1);
}