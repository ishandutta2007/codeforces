#include<cstdio>
#define ll long long
inline ll read()
{
	ll x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
#define K 17
int x[MN+5],z[MN+5],zn,fa[K][MN+5],d[MN+5];ll y[MN+5];
inline double cal(int a,int b){return (double)(y[a]-y[b])/(x[a]-x[b]);}
int lca(int x,int y)
{
	int k=d[x]-d[y],i;
	if(k<0)k=-k,x^=y^=x^=y;
	for(i=0;k;k>>=1,++i)if(k&1)x=fa[i][x];
	if(x==y)return x;
	for(i=K;i--;)if(fa[i][x]!=fa[i][y])x=fa[i][x],y=fa[i][y];
	return fa[0][x];
}
int main()
{
	int n=read(),i,j;
	for(i=1;i<=n;++i)x[i]=read(),y[i]=read();
	for(z[0]=i=n;--i;)
	{
		while(zn&&cal(i,z[zn])<cal(z[zn],z[zn-1]))--zn;
		d[i]=d[fa[0][i]=z[zn]]+1;z[++zn]=i;
	}
	for(i=1;i<K;++i)for(j=1;j<=n;++j)fa[i][j]=fa[i-1][fa[i-1][j]];
	for(n=read();n--;)printf("%d ",lca(read(),read()));
}