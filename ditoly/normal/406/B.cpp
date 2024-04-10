#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MX 1000000
int u[MX+5];
int main()
{
	int n=read(),i,s=0;
	printf("%d\n",n);
	while(n--)u[read()]=1;
	for(i=1;i<=MX;++i)if(u[i])if(u[MX+1-i])++s;else printf("%d ",MX+1-i);
	for(i=1;i<=MX;++i)if(s&&!u[i]&&!u[MX+1-i])printf("%d %d ",i,MX+1-i),s-=2;
}