#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 500
#define LG 61
using namespace std;
int n,m,f[LG+1][2][N+5][N+5],g[N+5],h[N+5];bitset<N+5> A[N+5],B[N+5];
int main()
{
	RI i,j,x,y,z;for(scanf("%d%d",&n,&m),i=1;i<=m;++i) scanf("%d%d%d",&x,&y,&z),f[0][z][x][y]=1;
	for(i=1;i<=LG;++i) for(j=0;j<=1;++j)
	{
		for(x=1;x<=n;++x) for(A[x].reset(),y=1;y<=n;++y) f[i-1][j][x][y]&&(A[x].set(y),0);
		for(x=1;x<=n;++x) for(B[x].reset(),y=1;y<=n;++y) f[i-1][j^1][y][x]&&(B[x].set(y),0);
		for(x=1;x<=n;++x) for(y=1;y<=n;++y) (A[x]&B[y]).any()&&(f[i][j][x][y]=1);
	}
	long long t=0;for(i=1;i<=n;++i) g[i]=1;for(i=LG,j=0;~i;--i)
	{
		for(x=1;x<=n;++x) if(g[x]) for(y=1;y<=n;++y) if(f[i][j][x][y]) goto OK;continue;OK:
		for(x=1;x<=n;++x) if(g[x]) for(y=1;y<=n;++y) f[i][j][x][y]&&(h[y]=1);
		for(x=1;x<=n;++x) g[x]=h[x],h[x]=0;j^=1,t|=1LL<<i;
	}
	return t<=1e18?printf("%lld\n",t):puts("-1"),0;
}