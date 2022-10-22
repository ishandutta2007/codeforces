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
#define X 1000000007
using namespace std;
int n,m,f1[N+5][N+5],f2[N+5][N+5];char s[N+5][N+5];
int main()
{
	RI i,j;for(scanf("%d%d",&n,&m),i=1;i<=n;++i) scanf("%s",s[i]+1);
	for(i=1;i<=n;++i) for(j=1;j<=m;++j) s[i][j]^'#'&&
		(f1[i][j]=i==1&&j==2?1:(f1[i-1][j]+f1[i][j-1])%X,f2[i][j]=i==2&&j==1?1:(f2[i-1][j]+f2[i][j-1])%X);
	return printf("%d\n",(1LL*f1[n-1][m]*f2[n][m-1]-1LL*f1[n][m-1]*f2[n-1][m]%X+X)%X),0;
}