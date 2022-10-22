#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 64
#define M 256
using namespace std;
int n,m,e[N+5][N+5];
namespace G
{
	int ct,a[M*40][M+5],v[M*40];
	I void A1(CI x,CI y) {++ct;for(RI i=1;i<=m;++i) a[ct][i]=0;a[ct][x]=1,v[ct]=y;}
	I void A2(CI x,CI y,CI z) {++ct;for(RI i=1;i<=m;++i) a[ct][i]=0;a[ct][e[x][y]]=a[ct][e[y][z]]=a[ct][e[z][x]]=1,v[ct]=0;}
	int p[M+5],c[M+5];I void Gauss()
	{
		RI i,j,k,t,d=0;for(i=1;i<=m;++i)
		{
			for(j=d+1;j<=ct&&!a[j][i];++j);if(j>ct) {c[i]=0;continue;}
			for(p[++d]=i,swap(v[d],v[j]),k=1;k<=m;++k) swap(a[d][k],a[j][k]);
			for(j=d+1;j<=ct;++j) if(a[j][i]) for(t=3-a[j][i]*a[d][i]%3,v[j]=(v[j]+v[d]*t)%3,k=i;k<=m;++k) a[j][k]=(a[j][k]+a[d][k]*t)%3;
		}
		for(i=d+1;i<=ct;++i) if(v[i]) return (void)puts("-1");
		for(i=d;i;--i) for(c[p[i]]=v[i]=v[i]*a[i][p[i]]%3,j=i-1;j;--j) v[j]=(v[j]-a[j][p[i]]*v[i]%3+3)%3;
		for(i=1;i<=m;++i) printf("%d%c",c[i]?c[i]:3," \n"[i==m]);
	}
}
int main()
{
	RI Tt,i,j,k,x,y,z;scanf("%d",&Tt);W(Tt--)
	{
		for(scanf("%d%d",&n,&m),i=1;i<=n;++i) for(j=1;j<=n;++j) e[i][j]=0;
		for(G::ct=0,i=1;i<=m;++i) scanf("%d%d%d",&x,&y,&z),e[x][y]=e[y][x]=i,~z&&(G::A1(i,z%3),0);
		for(i=1;i<=n;++i) for(j=i+1;j<=n;++j) if(e[i][j]) for(k=j+1;k<=n;++k) if(e[j][k]&&e[k][i]) G::A2(i,j,k);G::Gauss();
	}return 0;
}