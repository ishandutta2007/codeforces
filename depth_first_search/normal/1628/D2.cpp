#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 1000000
#define X 1000000007
#define C(x,y) (1LL*Fc[x]*Ic[y]%X*Ic[(x)-(y)]%X)
using namespace std;
int n,m,k,Fc[N+5],Ic[N+5];
I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
int main()
{
	RI i;for(Fc[0]=i=1;i<=N;++i) Fc[i]=1LL*Fc[i-1]*i%X;for(Ic[i=N]=QP(Fc[N],X-2);i;--i) Ic[i-1]=1LL*Ic[i]*i%X;
	RI Tt,p,t;scanf("%d",&Tt);W(Tt--)
	{
		if(scanf("%d%d%d",&n,&m,&k),n==m) {printf("%d\n",(int)(1LL*n*k%X));continue;}
		for(p=1,t=i=0;i<=min(i,m);p=2*p%X,++i) t=(t+1LL*i*p%X*k%X*C(n-i-1,m-i))%X;
		printf("%d\n",(int)(1LL*t*QP(2,X-1-n)%X));
	}return 0;
}