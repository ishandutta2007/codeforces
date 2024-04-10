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
#define X 998244353
#define C(x,y) (0<=(y)&&(y)<=(x)?1LL*Fac[x]*IFac[y]%X*IFac[(x)-(y)]%X:0)
using namespace std;
int n;char s[N+5];I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
int Fac[N+5],IFac[N+5];I void InitFac()
{
	RI i;for(Fac[0]=i=1;i<=n;++i) Fac[i]=1LL*Fac[i-1]*i%X;
	for(IFac[i=n]=QP(Fac[n],X-2);i;--i) IFac[i-1]=1LL*IFac[i]*i%X;
}
I int Calc(RI cl,RI cr,RI tl,RI tr)
{
	cl<cr&&(swap(cl,cr),swap(tl,tr),0);
	return (1LL*cl*C(tl+tr,tr+cr-cl)+1LL*tl*C(tl+tr-1,tr-cl+cr-1))%X;
}
int main()
{
	RI i;scanf("%s",s+1),n=strlen(s+1),InitFac();
	RI cl=0,cr=0,tl=0,tr=0;for(i=1;i<=n;++i) s[i]==')'&&++cr,s[i]=='?'&&++tr;
	RI t=0;for(i=1;i^n;++i) s[i]=='('&&++cl,s[i]==')'&&--cr,s[i]=='?'&&(++tl,--tr),t=(t+Calc(cl,cr,tl,tr))%X;
	return printf("%d\n",t),0;
}