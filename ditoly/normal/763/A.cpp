#include<cstdio>
inline int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 100000
int x[MN+5],y[MN+5],c[MN+5],r[MN+5];
int main()
{
	int n=read(),i,cnt=0;
	for(i=1;i<n;++i)x[i]=read(),y[i]=read();
	for(i=1;i<=n;++i)c[i]=read();
	for(i=1;i<n;++i)if(c[x[i]]!=c[y[i]])++r[x[i]],++r[y[i]],++cnt;
	for(i=1;i<=n;++i)if(r[i]==cnt)return 0*printf("YES\n%d",i);
	puts("NO"); 
}