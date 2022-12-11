#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 30000
int a[MN+5]; 
int main()
{
	int n=read(),t=read(),i;
	for(i=1;i<n;++i)a[i]=read();
	for(i=1;i<t;i+=a[i]);
	puts(i>t?"NO":"YES");
}