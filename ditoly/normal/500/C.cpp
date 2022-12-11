#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 500
int w[MN+5],u[MN+5],z[MN+5],zn;
int main()
{
	int n,m,i,x,ans=0;
	n=read();m=read();
	for(i=1;i<=n;++i)w[i]=read();
	while(m--)
	{
		if(!u[x=read()])u[z[++zn]=x]=1;
		for(i=1;z[i]!=x;++i);
		while(--i)ans+=w[z[i+1]=z[i]];
		z[1]=x;
	}
	printf("%d",ans);
}