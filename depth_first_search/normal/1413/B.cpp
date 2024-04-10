#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 500
using namespace std;
int n,m,a[N+5][N+5],p[N*N+5],q[N*N+5];
int main()
{
	RI Tt,i,j,x;scanf("%d",&Tt);W(Tt--)
	{
		for(scanf("%d%d",&n,&m),i=1;i<=n;++i) for(j=1;j<=m;++j) scanf("%d",&x),q[x]=j;
		for(i=1;i<=m;++i) for(j=1;j<=n;++j) scanf("%d",&x),p[x]=j;
		for(i=1;i<=n*m;++i) a[p[i]][q[i]]=i;for(i=1;i<=n;++i) for(j=1;j<=m;++j) printf("%d%c",a[i][j]," \n"[j==m]);
	}return 0;
}