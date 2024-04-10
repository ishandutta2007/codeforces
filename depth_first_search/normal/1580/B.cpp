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
using namespace std;
int n,m,k,X,C[N+5][N+5],f[N+5][N+5][N+5];
I bool NA() {if(m<=30&&(1<<m-1)<k) return 1;RI c=k,t=0;for(RI i=m;i;--i) t+=c,c=c+1>>1;return t>n;}
int main()
{
	RI i,j,l,p,q;if(scanf("%d%d%d%d",&n,&m,&k,&X),NA()) return puts("0"),0;
	for(C[0][0]=i=1;i<=n;++i) for(C[i][0]=j=1;j<=i;++j) C[i][j]=(C[i-1][j-1]+C[i-1][j])%X;
	for(i=1;i<=n+1;++i) f[i][0][0]=1;
	for(i=n;i;--i) for(j=1;j+i-1<=n;++j) for(l=i==m;l<=k;++l) for(p=0;p^j;++p)
		for(q=0;q<=l-(i==m);++q) f[i][j][l]=(f[i][j][l]+1LL*C[j-1][p]*f[i+1][p][q]%X*f[i+1][j-1-p][l-(i==m)-q])%X;
	return printf("%d\n",f[1][n][k]),0;
}