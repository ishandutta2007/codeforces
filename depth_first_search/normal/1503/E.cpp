#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 2021
#define X 998244353
#define F(x,y) (C[(x)+(y)-1][y])
using namespace std;
int n,m,C[2*N+5][2*N+5];I void GC(CI S)
{
	for(RI i=C[0][0]=1;i<=S;++i) for(RI j=C[i][0]=1;j<=i;++j) C[i][j]=(C[i-1][j-1]+C[i-1][j])%X;
}
int t,f[N+5],g[N+5];I void Calc(CI n,CI m)
{
	RI i,k,s;for(k=2;k<=m;++k) for(s=0,i=1;i<=n;++i) t=(t+1LL*F(m-k+1,i-1)*F(m-k+2,n-i)%X*s)%X,s=(s+1LL*F(k,i-1)*F(k-1,n-i))%X;
}
I void Sub()
{
	RI i,j;for(i=1;i^n;++i) for(j=2;j<=m;++j) t=(t-1LL*F(j,i-1)*F(j-1,n-i)%X*F(m-j+1,i)%X*F(m-j+2,n-i-1)%X+X)%X;
}
int main()
{
	return scanf("%d%d",&n,&m),GC(n+m),Calc(n,m),Calc(m,n),Sub(),printf("%d\n",(t<<1)%X),0;
}