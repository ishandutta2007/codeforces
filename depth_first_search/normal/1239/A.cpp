#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
#define X 1000000007
using namespace std;
int n,m,f[N+5][2];
I int Qpow(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
int main()
{
	RI i;scanf("%d%d",&n,&m);
	for(f[1][0]=2,i=2;i<=max(n,m);++i) f[i][0]=(f[i-1][0]+f[i-1][1])%X,f[i][1]=f[i-1][0];
	return printf("%d",(1LL*f[m][0]+f[m][1]+f[n][0]+f[n][1]-2+X)%X),0;
}