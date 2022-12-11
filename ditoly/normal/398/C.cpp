#include<cstdio>
int main()
{
	int n,i;
	scanf("%d",&n);
	if(n==5)return 0*puts("1 2 2\n1 4 1\n2 3 1\n4 5 1\n3 4\n3 5");
	for(i=1;i<=n/2;++i)printf("%d %d 1\n",i,i+n/2);
	for(;i<n;++i)printf("%d %d %d\n",i,i+1,2*(i-n/2)-1);
	puts("1 3");
	for(i=1;i<n/2;++i)printf("%d %d\n",i,i+1);
}