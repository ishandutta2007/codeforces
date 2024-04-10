#include<cstdio>
#define MN 100000
int a[MN+5],an;
int main()
{
	int n,k,i;
	scanf("%d%d",&n,&k);
	for(i=2;k>1&&n>1;++i)for(;k>1&&n%i==0;--k,n/=i)a[++an]=i;
	if(n==1)return 0*puts("-1");
	for(i=1;i<=an;++i)printf("%d ",a[i]);printf("%d",n);
}