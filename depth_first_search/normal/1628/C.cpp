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
using namespace std;
int n,a[N+5][N+5],c[N+5][N+5];
int main()
{
	RI Tt,i,j,t;scanf("%d",&Tt);W(Tt--)
	{
		for(scanf("%d",&n),i=1;i<=n;++i) for(j=1;j<=n;++j) scanf("%d",&a[i][j]),c[i][j]=0;
		for(t=0,i=2;i<=n;++i) for(j=1;j<=n;++j) !c[i-1][j]&&(t^=a[i][j],c[i][j-1]^=1,c[i][j+1]^=1,c[i+1][j]^=1);
		printf("%d\n",t);
	}return 0;
}