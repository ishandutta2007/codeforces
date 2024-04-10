#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 1500
int a[MN+5];
int main()
{
	int n=read(),i,j,s=0;
	for(i=1;i<=n;++i)a[i]=read();
	for(i=1;i<=n;++i)for(j=1;j<i;++j)if(a[j]>a[i])s^=1;
	for(n=read();n--;)i=read(),j=read(),
		puts((s^=(1LL*(j-i+1)*(j-i)/2)&1)?"odd":"even");
}