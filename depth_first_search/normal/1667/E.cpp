#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 200000
#define X 998244353
#define C(x,y) (1LL*Fc[x]*Ic[y]%X*Ic[(x)-(y)]%X)
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp I void write(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc(' ');}
}using namespace FastIO;
int n,h[N+5],s[N+5],A[N+5],Fc[N+5],Ic[N+5],Iv[N+5];
I int QP(RI x,RI y=X-2) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
namespace Poly
{
	#define PR 3
	#define IPR 332748118
	int P,L,IP,R[N<<2],A[N<<2],B[N<<2];I void NTT(int* s,RI op)
	{
		RI i,j,k,x,y,U,S;for(i=0;i^P;++i) i<R[i]&&(swap(s[i],s[R[i]]),0);
		for(i=1;i^P;i<<=1) for(U=QP(~op?PR:IPR,(X-1)/(i<<1)),j=0;j^P;j+=i<<1)
			for(S=1,k=0;k^i;++k,S=1LL*S*U%X) s[j+k]=((x=s[j+k])+(y=1LL*S*s[i+j+k]%X))%X,s[i+j+k]=(x-y+X)%X;
		if(!~op) for(x=QP(P),i=0;i^P;++i) s[i]=1LL*s[i]*x%X;
	}
	I void Mul(int* a,int* b)
	{
		RI i;P=1,L=0;W(P<=2*n) P<<=1,++L;for(i=0;i^P;++i) R[i]=((R[i>>1]>>1)|((i&1)<<L-1));
		for(i=0;i<=n;++i) A[i]=a[i],B[i]=b[i];for(;i^P;++i) A[i]=B[i]=0;
		for(NTT(A,1),NTT(B,1),i=0;i^P;++i) A[i]=1LL*A[i]*B[i]%X;for(NTT(A,-1),i=0;i<=n;++i) a[i]=A[i];
	}
}
int main()
{
	RI i;for(read(n),s[1]=Iv[1]=1,i=2;i<=n;++i) Iv[i]=1LL*(X-X/i)*Iv[X%i]%X,s[i]=(s[i-1]+Iv[i])%X;
	for(Fc[0]=Ic[0]=i=1;i<=n;++i) Fc[i]=1LL*Fc[i-1]*i%X,Ic[i]=1LL*Ic[i-1]*Iv[i]%X;
	for(i=(n-1)/2;i<=n-2;++i) h[i]=1LL*(1-s[i]+s[(n-1)/2]+X)*Fc[i]%X,A[i]=1LL*h[i]*Fc[n-i-2]%X*Ic[i]%X;
	write(1LL*(1-s[i]+s[(n-1)/2]+X)*Fc[i]%X);
	for(Poly::Mul(A,Ic),i=2;i<=n;++i) write(1LL*A[n-i]*Fc[n-i]%X*(i-1)%X);return clear(),0;
}