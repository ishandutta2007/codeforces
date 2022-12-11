#include<cstdio>
int main()
{
	int a,b,c,d,p1,p2;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	p1=a;if(c<p1)p1=c;if(d<p1)p1=d;
	p2=a-p1;if(b<p2)p2=b;
	printf("%d",p1*256+p2*32);
}