#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 3000
using namespace std;
int n,a[N+5],f[N+5][N+5];
int main()
{
	RI Tt,i,j,k,t=0;scanf("%d",&Tt);W(Tt--)
	{
		for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",a+i);
		for(i=2;i<=n;++i) for(j=1;j<=n;++j) f[i][j]=1e9;
		for(i=2;i<=n;++i)
		{
			for(t=0,j=i-1;j;--j) a[j]+j>=i&&(f[i][a[j]+j]=min(f[i][a[j]+j],f[j][i-1]+t),++t);
			for(j=i;j<=n;++j) f[i][j]=min(f[i][j],f[i][j-1]);
		}printf("%d\n",f[n][n]);
	}return 0;
}