#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 300000
#define X 998244353
using namespace std;
int n,a[N+5],Fac[N+5],IFac[N+5];
I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
int main()
{
	RI i;for(scanf("%d",&n),i=1;i<=2*n;++i) scanf("%d",a+i);
	RI t=0;for(sort(a+1,a+2*n+1),i=n+1;i<=2*n;++i) t=(t+a[i])%X;for(i=1;i<=n;++i) t=(t-a[i]+X)%X;
	for(Fac[0]=i=1;i<=2*n;++i) Fac[i]=1LL*Fac[i-1]*i%X;
	for(IFac[2*n]=QP(Fac[2*n],X-2),i=2*n-1;~i;--i) IFac[i]=1LL*IFac[i+1]*(i+1)%X;
	return printf("%d\n",1LL*t*Fac[2*n]%X*IFac[n]%X*IFac[n]%X),0;
}