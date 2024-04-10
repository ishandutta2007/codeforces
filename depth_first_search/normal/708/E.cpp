#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 1500
#define K 100000
#define X 1000000007
#define C(x,y) (1LL*Fac[x]*IFac[y]%X*IFac[(x)-(y)]%X)
using namespace std;
int n,m,k,p,q[K+5],f[2][N+5][N+5],g[N+5][N+5],s[N+5][N+5];
I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
int Fac[N+K],IFac[K+5];I void InitFac()
{
	RI i;for(Fac[0]=i=1;i<=k;++i) Fac[i]=1LL*Fac[i-1]*i%X;
	for(IFac[i=k]=QP(Fac[k],X-2);i;--i) IFac[i-1]=1LL*IFac[i]*i%X;
}
int main()
{
	RI i,j,x,y;scanf("%d%d%d%d%d",&n,&m,&x,&y,&k),p=1LL*x*QP(y,X-2)%X,InitFac();
	for(i=0;i<=k;++i) q[i]=1LL*C(k,i)*QP(p,i)%X*QP((1-p+X)%X,k-i)%X;
	for(g[0][m]=s[0][m]=i=1;i<=n;++i)
	{
		for(x=y=j=0;j<=m;x=(x+q[j])%X,y=(1LL*q[j]*s[i-1][j]+y)%X,++j)
			g[i][j]=1LL*q[m-j]*(1LL*x*(s[i-1][m]-s[i-1][m-j]+X)%X-y+X)%X;
		for(s[i][0]=g[i][0],j=1;j<=m;++j) s[i][j]=(s[i][j-1]+g[i][j])%X;
	}return printf("%d\n",s[n][m]),0;
}