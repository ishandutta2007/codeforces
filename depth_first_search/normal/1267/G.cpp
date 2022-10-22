#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 100
#define V 10000
#define DB double
using namespace std;
int n,x,c[N+5];DB g[N+5][V+5],C[N+5][N+5];
int main()
{
	RI i,j,k;for(scanf("%d%d",&n,&x),i=1;i<=n;++i) scanf("%d",c+i);
	for(C[0][0]=i=1;i<=n;++i) for(C[i][0]=j=1;j<=i;++j) C[i][j]=C[i-1][j-1]+C[i-1][j];
	DB t=0;for(g[0][0]=i=1;i<=n;t+=c[i++]) for(j=i-1;~j;--j) for(k=t;~k;--k) g[j+1][k+c[i]]+=g[j][k];
	DB ans=0;for(j=0;j^n;++j) for(k=0;k<=t;++k) ans+=min((1.0*n/(n-j)+1)*x/2,(t-k)/(n-j))*g[j][k]/C[n][j];
	return printf("%.12lf\n",ans),0;
}