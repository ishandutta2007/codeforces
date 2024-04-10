#include<cstdio>
int main()
{
	int a,b,c,d,mx,i,j;long long ans=-1LL<<60,x;
	scanf("%d%d",&a,&b);
	if(!a)
	{
		printf("%I64d\n",-1LL*b*b);
		while(b--)putchar('x');
		return 0;
	}
	for(i=1;i<=a;++i)
	{
		c=b/(a-i+2);d=b%(a-i+2);
		x=1LL*i*i+a-i-1LL*d*(c+1)*(c+1)-1LL*(a-i+2-d)*c*c;
		if(x>ans)ans=x,mx=i;
	}
	printf("%I64d\n",ans);
	c=b/(a-mx+2);d=b%(a-mx+2);
	for(i=0;i<c;++i)putchar('x');
	for(i=1;i<mx;++i)putchar('o');
	for(i=0;i<d;++i)for(putchar('o'),j=0;j<=c;++j)putchar('x');
	for(i=0;i<a-mx+1-d;++i)for(putchar('o'),j=0;j<c;++j)putchar('x');
}