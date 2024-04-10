#include<cstdio>
inline int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 100000
int a[MN+5],c[MN+5],p[MN+5],pn;
int main()
{
	int n=read(),i;
	for(i=1;i<=n;++i)if((a[i]=read())==i)p[c[i]=++pn]=i;
	for(i=1;i<=n;++i)if(!c[a[i]])return 0*puts("-1");
	printf("%d\n",pn);
	for(i=1;i<=n;++i)printf("%d ",c[a[i]]);puts("");
	for(i=1;i<=pn;++i)printf("%d ",p[i]);
}