#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define K 32767
#define LG 30
#define X 998244353
#define Cl(f) memset(f,0,sizeof(f))
using namespace std;
int n,k;struct Data {int f[K+5],g[K+5],h[K+5];I void Clear() {Cl(f),Cl(g),Cl(h);}}ans,res,s[LG+1];
I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
namespace FastIO
{
	#define FS 100000
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char FO[FS],OS[FS],*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void write(Ty x,char y) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc(y);}
}using namespace FastIO;
namespace Poly
{
	#define PR 3
	#define IPR 332748118
	int P,Inv,L,R[K<<2],F[K<<2],Af[K<<2],Ag[K<<2],Ah[K<<2],Bf[K<<2],Bg[K<<2],Bh[K<<2];
	I void Init()
	{
		P=1,L=0;W(P<=(k<<1)) P<<=1,++L;for(RI i=0;i^P;++i) R[i]=((R[i>>1]>>1)|((i&1)<<L-1));Inv=QP(P,X-2);
	}
	I void NTT(int* s,CI op)
	{
		RI i,j,k,x,y,U,S;for(i=0;i^P;++i) i<R[i]&&(swap(s[i],s[R[i]]),0);
		for(i=1;i^P;i<<=1) for(U=QP(op,(X-1)/(i<<1)),j=0;j^P;j+=i<<1) for(S=1,
			k=0;k^i;++k,S=1LL*S*U%X) s[j+k]=((x=s[j+k])+(y=1LL*S*s[i+j+k]%X))%X,s[i+j+k]=(x-y+X)%X;
		if(op==IPR) for(i=0;i^P;++i) s[i]=1LL*s[i]*Inv%X;
	}
	I void Merge(Data& S,Con Data& A,Con Data& B)
	{
		RI i;for(i=0;i<=k;++i) Af[i]=A.f[i],Ag[i]=A.g[i],Ah[i]=A.h[i],Bf[i]=B.f[i],Bg[i]=B.g[i],Bh[i]=B.h[i];
		for(;i^P;++i) Af[i]=Ag[i]=Ah[i]=Bf[i]=Bg[i]=Bh[i]=0;
		NTT(Af,PR),NTT(Ag,PR),NTT(Ah,PR),NTT(Bf,PR),NTT(Bg,PR),NTT(Bh,PR);
		for(i=0;i^P;++i) F[i]=1LL*Af[i]*Bf[i]%X;for(NTT(F,IPR),i=0;i<=k;++i) S.f[i]=F[i];
		for(i=0;i^P;++i) F[i]=1LL*Af[i]*Bg[i]%X;for(NTT(F,IPR),i=0;i<=k;++i) S.g[i]=F[i];
		for(i=0;i^P;++i) F[i]=1LL*Ag[i]*Bg[i]%X;for(NTT(F,IPR),i=0;i<=k;++i) S.h[i]=F[i],S.f[i]=(S.f[i]+F[i-1])%X;
		for(i=0;i^P;++i) F[i]=1LL*Ag[i]*Bh[i]%X;for(NTT(F,IPR),i=1;i<=k;++i) S.g[i]=(S.g[i]+F[i-1])%X;
		for(i=0;i^P;++i) F[i]=1LL*Ah[i]*Bh[i]%X;for(NTT(F,IPR),i=1;i<=k;++i) S.h[i]=(S.h[i]+F[i-1])%X;
	}
}
int main()
{
	RI i;if(scanf("%d%d",&n,&k),Poly::Init(),!n) goto End;if(n==1) {ans.f[1]=1;goto End;}
	for(s[1].h[0]=s[1].g[0]=s[1].g[1]=s[1].f[0]=s[1].f[2]=1,s[1].f[1]=3,i=2;i<=LG;++i) Poly::Merge(s[i],s[i-1],s[i-1]);
	for(ans=s[1],n-=2,i=LG;i;--i) n>>i&1&&(res=ans,ans.Clear(),Poly::Merge(ans,res,s[i]),0);
	if(n&1) for(i=k;i;--i) ans.f[i]=(0LL+ans.f[i]+ans.f[i-1]+ans.g[i-1])%X;
	End:for(i=1;i<=k;++i) write(ans.f[i]," \n"[i==k]);return clear(),0;
}