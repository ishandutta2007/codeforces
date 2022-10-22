#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define K 1000000
#define X 1000000007
using namespace std;
int n,k,f[K+5],g1[K+1],g2[K+5],Fc[K+5],Ic[K+5];I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
int main()
{
	RI i;for(scanf("%d%d",&n,&k),Fc[0]=i=1;i<=k+1;++i) Fc[i]=1LL*Fc[i-1]*i%X;for(Ic[i=k+1]=QP(Fc[k+1],X-2);i;--i) Ic[i-1]=1LL*Ic[i]*i%X;
	RI g=1;for(i=1;i<=k+1;++i) f[i]=(f[i-1]+QP(i,k))%X;if(n<=k+1) return printf("%d\n",f[n]),0;
	for(i=0;i<=k+1;++i) g1[i]=1LL*(i?g1[i-1]:1)*(n-i)%X;for(i=k+1;~i;--i) g2[i]=1LL*(i!=k+1?g2[i+1]:1)*(n-i)%X; 
	RI t=0;for(i=0;i<=k+1;++i) t=(t+((k+1-i)&1?X-1LL:1LL)*f[i]%X*(i?g1[i-1]:1)%X*(i!=k+1?g2[i+1]:1)%X*Ic[i]%X*Ic[k+1-i])%X;return printf("%d\n",t),0;
}