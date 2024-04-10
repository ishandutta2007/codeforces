#include<cstdio>
int main()
{
	int n,k,i;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;++i)putchar('a'+i%k);
}