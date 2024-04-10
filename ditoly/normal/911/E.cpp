#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 200000
int a[MN+5],u[MN+5],z[MN+5],zn;
int main()
{
	int n,k,i,j,t=1;
	n=read();k=read();
	for(i=1;i<=k;++i)
	{
		u[z[++zn]=a[i]=read()]=1;
		if(zn>1&&z[zn]>z[zn-1])return 0*puts("-1");
		while(z[zn]==t)--zn,++t;
	}
	for(i=1;i<=k;++i)printf("%d ",a[i]);
	z[zn+1]=0;z[0]=n;
	for(i=zn;i>=0;--i)for(j=z[i];j>z[i+1];--j)if(!u[j])printf("%d ",j);
}