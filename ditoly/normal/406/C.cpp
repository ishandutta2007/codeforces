#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
struct edge{int nx,t;}e[MN*2+5];
int h[MN+5],en,d[MN+5];
inline void ins(int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){h[y],x};h[y]=en;
}
bool dfs(int x,int fa)
{
	int i,u=0;
	for(i=h[x];i;i=e[i].nx)if(e[i].t!=fa)
		if(d[e[i].t]?d[e[i].t]<d[x]:(d[e[i].t]=d[x]+1,dfs(e[i].t,x)))
			u?printf("%d %d %d\n",u,x,e[i].t),u=0:u=e[i].t;
	return u?printf("%d %d %d\n",u,x,fa),false:true;
}
int main()
{
	int n=read(),m=read();
	if(m&1)return 0*puts("No solution");
	while(m--)ins(read(),read());
	dfs(d[1]=1,0);
}