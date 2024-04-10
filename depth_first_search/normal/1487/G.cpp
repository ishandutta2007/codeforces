#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 400
#define X 998244353
using namespace std;
int n,c[30];I int DP0()
{
	RI f=26*26;for(RI i=3;i<=n;++i) f=25LL*f%X;return f;
}
int g[N+5][N+5][2][2],G[N+5];I int DP1()
{
	RI i,j,x,y;for(x=0;x<=1;++x) for(y=0;y<=1;++y) g[2][(!x)+(!y)][x][y]=(x^1?1:25)*(y^1?1:25);
	for(i=3;i<=n;++i) for(j=0;j<=i/2+1;++j) for(y=0;y<=1;++y)
		g[i][j+1][y][0]=g[i-1][j][1][y],g[i][j][y][1]=(25LL*g[i-1][j][0][y]+24LL*g[i-1][j][1][y])%X;
	for(i=n/2+1;~i;--i) for(G[i]=G[i+1],x=0;x<=1;++x) for(y=0;y<=1;++y) G[i]=(G[i]+g[n][i][x][y])%X;
	RI t=0;for(i=1;i<=26;++i) t=(t+G[c[i]+1])%X;return t;
}
int h[2][N+5][N+5][3][3],H[N+5][N+5];I int DP2()
{
	RI i,j,k,x,y;for(x=0;x<=2;++x) for(y=0;y<=2;++y) h[0][(!x)+(!y)][(x==1)+(y==1)][x][y]=(x^2?1:24)*(y^2?1:24);
	for(i=3;i<=n;++i) for(j=0;j<=i/2+1;++j) for(k=0;k<=i/2+1;++k) for(y=0;y<=2;++y)
		h[i&1][j+1][k][y][0]=(h[i&1^1][j][k][1][y]+h[i&1^1][j][k][2][y])%X,
		h[i&1][j][k+1][y][1]=(h[i&1^1][j][k][0][y]+h[i&1^1][j][k][2][y])%X,
		h[i&1][j][k][y][2]=(24LL*h[i&1^1][j][k][0][y]+24LL*h[i&1^1][j][k][1][y]+23LL*h[i&1^1][j][k][2][y])%X;
	for(i=n/2+1;~i;--i) for(j=n/2+1;~j;--j)
	{
		H[i][j]=(0LL+H[i+1][j]+H[i][j+1]-H[i+1][j+1]+X)%X;
		for(x=0;x<=2;++x) for(y=0;y<=2;++y) H[i][j]=(H[i][j]+h[n&1][i][j][x][y])%X;
	}
	RI t=0;for(i=1;i<=26;++i) for(j=i+1;j<=26;++j) t=(t+H[c[i]+1][c[j]+1])%X;return t;
}
int main()
{
	scanf("%d",&n);for(RI i=1;i<=26;++i) scanf("%d",c+i);return printf("%d\n",(0LL+DP0()-DP1()+DP2()+X)%X),0;
}