#include<cstdio>
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i*i<=n;++i);
	for(;--i;)if(n%i==0)return 0*printf("%d %d",i,n/i);
}