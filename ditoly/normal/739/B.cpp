#include<cstdio>
inline int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x;
}
#define MN 200000
#define K 20
struct edge{int nx,t,w;}e[MN+5];
int h[MN+5],en,a[MN+5],f[MN+5][K],r[MN+5],ans[MN+5];
long long d[MN+5];
inline void ins(int x,int y,int w){e[++en]=(edge){h[x],y,w};h[x]=en;}
void pre(int x)
{
	for(int i=h[x];i;i=e[i].nx)
	{
		f[e[i].t][0]=x;
		d[e[i].t]=d[x]+e[i].w;
		pre(e[i].t);
	}
}
void work(int x)
{
	for(int i=h[x];i;i=e[i].nx)
	{
		work(e[i].t);
		ans[x]+=ans[e[i].t]-r[e[i].t]+1;
	}
}
int main()
{
	int n=read(),i,j,x;
	for(i=1;i<=n;++i)a[i]=read();
	for(i=2;i<=n;++i)x=read(),ins(x,i,read());
	pre(1);
	for(i=1;i<K;++i)for(j=1;j<=n;++j)f[j][i]=f[f[j][i-1]][i-1];
	for(i=1;i<=n;++i)
	{
		x=i;
		for(j=K;j--;)if(d[i]-d[f[x][j]]<=a[i])x=f[x][j];
		++r[x];
	}
	work(1);
	for(i=1;i<=n;++i)printf("%d ",ans[i]);
}