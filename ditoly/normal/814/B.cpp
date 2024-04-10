#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 1000
int a[MN+5],b[MN+5],c[MN+5],cn,d[MN+5],dn,u[MN+5];
int main()
{
	int n=read(),i;
	for(i=1;i<=n;++i)a[i]=read();
	for(i=1;i<=n;++i)b[i]=read();
	for(i=1;i<=n;++i)if(a[i]==b[i])u[a[i]]=1;else c[++cn]=i;
	for(i=1;i<=n;++i)if(!u[i])d[++dn]=i;
	if(dn==1)a[c[1]]=d[1];
	else if((d[1]==a[c[1]]&&d[2]==b[c[2]])||(d[1]==b[c[1]]&&d[2]==a[c[2]]))a[c[1]]=d[1],a[c[2]]=d[2];
	else a[c[2]]=d[1],a[c[1]]=d[2];
	for(i=1;i<=n;++i)printf("%d ",a[i]);
}