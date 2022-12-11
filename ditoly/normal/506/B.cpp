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
int h[MN+5],r[MN+5],en,u[MN+5],o,s,q[MN+5],qn;
inline void ins(int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){r[y],x};r[y]=en;
}
void dfs(int x)
{
	++s;u[x]=2;
	for(int i=h[x];i;i=e[i].nx)
		if(u[e[i].t]>1)o=1;
		else if(!u[e[i].t])dfs(e[i].t);
	for(int i=r[x];i;i=e[i].nx)q[++qn]=e[i].t;
	u[x]=1;
}
int main()
{
	int n,m,i,j,ans=0;
	n=read();m=read();
	while(m--)i=read(),ins(i,read());
	for(i=1;i<=n;++i)if(!u[i])
	{
		o=s=qn=0;
		dfs(i);
		for(j=1;j<=qn;++j)if(!u[q[j]])dfs(q[j]); 
		ans+=s-1+o;
	}
	printf("%d",ans);
}