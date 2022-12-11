#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 400
int g[MN+5][MN+5];
int main()
{
	int n,m,x,y,i,j,k;
	n=read();m=read();
	while(m--)x=read(),y=read(),g[x][y]=g[y][x]=1;
	if(g[1][n])for(i=1;i<=n;++i)for(j=1;j<=n;++j)g[i][j]^=1;
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)if(!g[i][j])g[i][j]=n;
	for(k=1;k<=n;++k)for(i=1;i<=n;++i)for(j=1;j<=n;++j)
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	printf("%d",g[1][n]<n?g[1][n]:-1);
}