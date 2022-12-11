#include<cstdio>
int main()
{
	int n,x,i;
	scanf("%d%d",&n,&x);
	if(n==1)return 0*printf("YES\n%d",x);
	if(n==2)return 0*printf(x?"YES\n0 %d":"NO",x);
	puts("YES");
	for(i=0;i<n-3;++i)printf("%d ",i),x^=i;
	printf("%d %d %d",(1<<18)^x,(1<<19),(1<<18)^(1<<19));
}