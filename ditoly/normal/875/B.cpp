#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 300000
int f[MN+5];
int gf(int k){return f[k]!=k?f[k]=gf(f[k]):k;}
int main()
{
	int n=read(),i,x;
	for(i=1;i<=n;++i)f[i]=i;
	printf("1 ");
	for(i=1;i<=n;++i)
	{
		x=read();f[x]=x-1;
		printf("%d ",i+gf(n)-n+1);
	}
}