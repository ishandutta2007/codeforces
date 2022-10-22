#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 5000
#define X 1000000007
using namespace std;
int n,k,a[N+5],f[N+5];
I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
int main()
{
	RI i,j;for(scanf("%d%d",&n,&k),f[0]=i=1;i<=n;++i) for(scanf("%d",a+i),j=i;~j;--j) f[j]=(1LL*a[i]*f[j]+(j?X-f[j-1]:0))%X;
	RI t=0,Iv=QP(n,X-2),g=1,p=1;for(i=0;i<=min(n,k);++i) t=(t+1LL*f[i]*g%X*p)%X,g=1LL*g*(k-i)%X,p=1LL*p*Iv%X;
	RI s=1;for(i=1;i<=n;++i) s=1LL*s*a[i]%X;return printf("%d\n",(s-t+X)%X),0;
}