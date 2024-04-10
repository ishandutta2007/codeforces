#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 1000
#define V 100000
#define X 998244353
using namespace std;
int n,k,a[N+5],f[N+5][N+5],id[V+5];
int main()
{
	RI i,j;for(scanf("%d%d",&n,&k),i=1;i<=n;++i) scanf("%d",a+i);sort(a+1,a+n+1);
	for(i=1;i<=n;++i) id[a[i]]=i;for(i=1;i<=V;++i) !id[i]&&(id[i]=id[i-1]);
	RI p,x,t=0;for(p=1;p<=V/(k-1);t=(t+f[n][k])%X,++p)
		for(f[0][0]=i=1;i<=n;++i) for(x=a[i]>=p?id[a[i]-p]:0,j=0;j<=k;++j) f[i][j]=(f[i-1][j]+(j?f[x][j-1]:0))%X;
	return printf("%d\n",t),0;
}