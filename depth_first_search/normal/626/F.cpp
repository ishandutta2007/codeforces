#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 200
#define M 1000
#define X 1000000007
#define Inc(x,y) ((x+=(y))>=X&&(x-=X))
using namespace std;
int n,m,a[N+5],d[N+5],f[2][N+5][M+5];
int main()
{
	int i,j,k,o;for(scanf("%d%d",&n,&m),i=1;i<=n;++i) scanf("%d",a+i);
    for(sort(a+1,a+n+1),i=1;i^n;++i) d[i]=a[i+1]-a[i];
	for(f[0][0][0]=i=1;i<=n;++i)
	{
		for(j=0;j<=i;++j) for(k=0;k<=m;++k) f[i&1][j][k]=0;
		for(j=0;j<=i;++j) for(k=0;k<=m;++k) if(o=f[i&1^1][j][k])
		j&&k+(j-1)*d[i]<=m&&(f[i&1][j-1][k+(j-1)*d[i]]=(f[i&1][j-1][k+(j-1)*d[i]]+1LL*j*o)%X),
		k+(j+1)*d[i]<=m&&Inc(f[i&1][j+1][k+(j+1)*d[i]],o),k+j*d[i]<=m&&(f[i&1][j][k+j*d[i]]=(f[i&1][j][k+j*d[i]]+1LL*o*(j+1))%X);
	}
	int t=0;for(k=0;k<=m;++k) Inc(t,f[n&1][0][k]);return printf("%d\n",t),0;
}