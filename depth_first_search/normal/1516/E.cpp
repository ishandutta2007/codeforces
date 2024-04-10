#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define K 200
#define X 1000000007
using namespace std;
int n,k,IFc[K+5],Inv[2*K+5],f[K+5][2*K+5],g[2*K+5][2*K+5],ans[K+5];
I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
int main()
{
	RI i,j,p;for(scanf("%d%d",&n,&k),Inv[1]=1,i=2;i<=2*k;++i) Inv[i]=1LL*(X-X/i)*Inv[X%i]%X;
	for(IFc[0]=i=1;i<=k;++i) IFc[i]=1LL*IFc[i-1]*Inv[i]%X;
	for(i=0;i<=min(n,2*k);++i) for(g[i][0]=j=1;j<=min(n-i,2*k);++j) g[i][j]=1LL*g[i][j-1]*(n-i-j+1)%X;
	for(i=0;i<=min(n,2*k);++i) for(j=1;j<=min(n-i,2*k);++j) g[i][j]=1LL*g[i][j]*Inv[j]%X;
	for(f[0][0]=i=1;i<=k;++i) for(j=0;j<k+i;++j) for(p=2;p<=k+i-j;++p) f[i][j+p]=(f[i][j+p]+1LL*f[i-1][j]*g[j][p])%X;
	for(i=0;i<=k;++i) for(j=i;j<=k+i;++j) ans[j-i]=(ans[j-i]+1LL*f[i][j]*IFc[i])%X;
	for(i=1;i<=k;++i) i^1&&(ans[i]=(ans[i]+ans[i-2])%X),printf("%d ",ans[i]);return 0;
}