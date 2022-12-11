#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 200000
struct edge{int nx,t;}e[MN*2+5];
int h[MN+5],en=1,u[MN+5],d[MN+5],z[MN+5];
int a[MN+5],b[MN+5],c[MN+5],cnt;
inline void ins(int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){h[y],x};h[y]=en;
}
void push(int x,int y)
{
	if(z[x])a[++cnt]=z[x],b[cnt]=x,c[cnt]=y,z[x]=0;
	else z[x]=y;
}
void dfs(int x,int fa)
{
	d[x]=1;
	for(int i=h[x];i;i=e[i].nx)if(!u[i>>1])
	{
		u[i>>1]=1;
		if(d[e[i].t])push(x,e[i].t);
		else dfs(e[i].t,x);
	}
	if(fa)if(z[x])push(x,fa);else push(fa,x);
}
int main()
{
	int n,m,i;
	n=read();m=read();
	while(m--)ins(read(),read());
	for(i=1;i<=n;++i)if(!d[i])dfs(i,0);
	printf("%d\n",cnt);
	for(i=1;i<=cnt;++i)printf("%d %d %d\n",a[i],b[i],c[i]);
}