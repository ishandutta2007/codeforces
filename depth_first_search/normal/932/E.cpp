#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define K 5000
#define X 1000000007
using namespace std;
int n,k,S2[K+5][K+5],dw[K+5];
I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
int main()
{
	RI i,j,m,t=0;scanf("%d%d",&n,&k),m=min(n,k);
	for(S2[0][0]=i=1;i<=k;++i) for(j=1;j<=i;++j) S2[i][j]=(1LL*S2[i-1][j]*j+S2[i-1][j-1])%X;
	for(dw[0]=i=1;i<=m;++i) dw[i]=1LL*dw[i-1]*(n-i+1)%X;
	RI p=QP(2,n-m);for(i=m;i;p=2LL*p%X,--i) t=(1LL*S2[k][i]*dw[i]%X*p+t)%X;
	return printf("%d\n",t),0;
}