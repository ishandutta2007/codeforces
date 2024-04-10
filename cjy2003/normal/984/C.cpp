#include<stdio.h>
#include<string.h>
long long n,p,q,b,gc;
long long gcd(long long a,long long b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d %I64d %I64d",&p,&q,&b);
		if(p==0)
		{
			printf("Finite\n");
			continue;	
		}
		gc=gcd(p,q);
		q/=gc;
		while(1)
		{
			b=gcd(b,q);
			if(b==1)break;
			while(q%b==0)q/=b;	
		}
		if(q==1)printf("Finite\n");
		else printf("Infinite\n");
	}
	return 0;
}