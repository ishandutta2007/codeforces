#include<stdio.h>

__int64 n,x,y,s,i;

int main()
{
	scanf("%I64d%I64d%I64d",&n,&x,&y);

	s = n-1 + (y-n+1)*(y-n+1);
	if(n>y || x>s) {printf("-1\n"); return 0;}
	for(i=1;i<n;i++) printf("1\n");
	printf("%I64d\n",y-n+1);

	return 0;
}