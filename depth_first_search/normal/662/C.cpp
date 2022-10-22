#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 20
#define M 100000
#define LL long long
using namespace std;
int n,m,P,g[1<<N];LL s[1<<N],f[1<<N];char a[N+5][M+5];
namespace Poly
{
	I void FWT(LL* s,CI op)
	{
		RI i,j,k;LL x,y;for(i=1;i^P;i<<=1) for(j=0;j^P;j+=i<<1) for(k=0;k^i;++k)
			s[j+k]=(x=s[j+k])+(y=s[i+j+k]),s[i+j+k]=x-y,!~op&&(s[j+k]>>=1,s[i+j+k]>>=1);
	}
	I void Mul(LL* A,LL* B) {RI i;for(FWT(A,1),FWT(B,1),i=0;i^P;++i) A[i]*=B[i];FWT(A,-1);}
}
int main()
{
	RI i,j,x;for(scanf("%d%d",&n,&m),i=1;i<=n;++i) scanf("%s",a[i]+1);
	for(j=1;j<=m;++j) {for(x=0,i=1;i<=n;++i) (x<<=1)|=a[i][j]&1;++s[x];}
	for(P=1<<n,i=1;i^P;++i) g[i]=g[i>>1]+(i&1),f[i]=min(g[i],n-g[i]);
	LL t=1e18;for(Poly::Mul(s,f),i=0;i^P;++i) t=min(t,s[i]);return printf("%lld\n",t),0;
}