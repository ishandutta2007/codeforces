#include<cstdio>
int main()
{
	int n,t=1;
	scanf("%d",&n);
	if(n%4==0)return 0*printf("%d %d",n/4*3,n/4*5);
	while(n%2==0)n/=2,t*=2;
	if(n==1)return 0*puts("-1");
	printf("%I64d %I64d",1LL*n*n/2*t,1LL*n*n/2*t+t);
}