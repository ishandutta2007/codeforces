#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 1000000
#define X 1000000007
#define Qinv(x) Qpow(x,X-2)
#define Inc(x,y) ((x+=(y))>=X&&(x-=X))
using namespace std;
int n,m;
I int Qpow(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
int main()
{
	RI i,ans,p1,p2,b1,b2;
	scanf("%d%d",&n,&m),ans=p1=Qpow(m,n),p2=1,b1=Qinv(m),b2=(1LL*2*m-1)%X;
	for(i=0;i^n;++i) Inc(ans,1LL*p1*p2%X),p1=1LL*p1*b1%X,p2=1LL*p2*b2%X;
	return printf("%d",ans),0;
}