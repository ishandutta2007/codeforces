#include<cstdio>
inline int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x;
}
#define MN 200000
int p[MN+5],d[MN+5];
void dfs(int x){d[x]=1;if(!d[p[x]])dfs(p[x]);}
int main()
{
	int n=read(),b=1,i,u=2;
	for(i=1;i<=n;++i)p[i]=read();
	for(i=1;i<=n;++i)b^=read();
	for(i=1;i<=n;++i)if(!d[i])++b,--u,dfs(i);
	printf("%d",b-(u>0));
}