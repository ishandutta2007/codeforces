#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 300000
struct edge{int nx,t;}e[MN*2+5];
int h[MN+5],en=1,q[MN+5],qn,u[MN+5],f[MN+5],cnt,ans[MN+5];
inline void ins(int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){h[y],x};h[y]=en;
}
int main()
{
	int n,k,d,i,j;
	n=read();k=read();d=read();
	for(i=1;i<=k;++i)u[j=read()]?0:u[q[++qn]=j]=1;
	for(i=1;i<n;++i)ins(read(),read());
	for(i=1;i<=qn;++i)for(j=h[q[i]];j;j=e[j].nx)if(e[j].t!=f[q[i]])
		if(u[e[j].t])ans[j>>1]?0:(++cnt,ans[j>>1]=1);
		else u[q[++qn]=e[j].t]=1,f[e[j].t]=q[i];
	printf("%d\n",cnt);
	for(i=1;i<n;++i)if(ans[i])printf("%d ",i);
}