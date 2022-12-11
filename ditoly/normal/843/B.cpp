#include<cstdio>
#include<cstdlib>
#include<ctime>
inline int read()
{
	int x,f=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=0;
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return f?x:-x;
}
int main()
{
	srand(time(0));
	int n,i,a,b,c,d,x;
	n=read();a=-1;b=read();x=read();
	for(i=1;i<=1000;++i)
	{
		printf("? %d\n",((rand()<<15)|rand())%n+1);
		fflush(stdout); 
		c=read();d=read();
		if(c<x&&c>=a)a=c,b=d;
	}
	while(a<x)
	{
		if(b<0)return 0*puts("! -1");
		printf("? %d\n",b);
		fflush(stdout);
		a=read();b=read();
	}
	printf("! %d\n",a);
}