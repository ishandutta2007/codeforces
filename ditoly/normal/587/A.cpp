#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 1000000
int u[MN+50],ans;
void push(int x)
{
	if(u[x])u[x]=0,push(x+1),--ans;
	else u[x]=1,++ans;
}
int main()
{
	int n=read();
	while(n--)push(read());
	printf("%d",ans);
}