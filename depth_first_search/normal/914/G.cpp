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
#define P 131072
#define L 17
#define X 1000000007
#define I2 500000004
using namespace std;
int n,a[N+5],f[P],f1[P],f2[P],f3[P],Fib[P];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
namespace Or
{
	int c[P],f[L+1][P],g[L+1][P];
	I void FWT_Or(int* s,CI op)
	{
		RI i,j,k;for(i=1;i^P;i<<=1) for(j=0;j^P;j+=i<<1) for(k=0;k^i;++k) s[i+j+k]=(s[i+j+k]+1LL*op*s[j+k])%X;
	}
	I void Solve()
	{
		RI i,j,k;for(i=1;i^P;++i) c[i]=c[i>>1]+(i&1);for(i=1;i<=n;++i) ++f[c[a[i]]][a[i]];
		for(i=0;i<=L;++i) FWT_Or(f[i],1);
		for(i=0;i^P;++i) for(j=L;~j;--j) for(k=L-j;~k;--k) g[j+k][i]=(g[j+k][i]+1LL*f[j][i]*f[k][i])%X;
		for(i=0;i<=L;++i) FWT_Or(g[i],X-1);for(i=0;i^P;++i) f1[i]=g[c[i]][i];
	}
}
namespace None
{
	I void Solve()
	{
		for(RI i=1;i<=n;++i) ++f2[a[i]];
	}
}
namespace Xor
{
	I void FWT_Xor(int* s,CI op)
	{
		RI i,j,k,x,y;for(i=1;i^P;i<<=1) for(j=0;j^P;j+=i<<1) for(k=0;k^i;++k)
			s[j+k]=((x=s[j+k])+(y=s[i+j+k]))%X,s[i+j+k]=(x-y+X)%X,!~op&&(s[j+k]=1LL*s[j+k]*I2%X,s[i+j+k]=1LL*s[i+j+k]*I2%X);
	}
	I void Solve()
	{
		RI i;for(i=1;i<=n;++i) ++f3[a[i]];for(FWT_Xor(f3,1),i=0;i^P;++i) f3[i]=1LL*f3[i]*f3[i]%X;FWT_Xor(f3,-1);
	}
}
namespace And
{
	I void FWT_And(int* s,CI op)
	{
		RI i,j,k;for(i=1;i^P;i<<=1) for(j=0;j^P;j+=i<<1) for(k=0;k^i;++k) s[j+k]=(s[j+k]+1LL*op*s[i+j+k])%X;
	}
	I void Solve()
	{
		RI i;for(i=0;i^P;++i) f1[i]=1LL*f1[i]*Fib[i]%X,f2[i]=1LL*f2[i]*Fib[i]%X,f3[i]=1LL*f3[i]*Fib[i]%X;
		for(FWT_And(f1,1),FWT_And(f2,1),FWT_And(f3,1),i=0;i^P;++i) f[i]=1LL*f1[i]*f2[i]%X*f3[i]%X;FWT_And(f,X-1);
	}
}
int main()
{
	RI i;for(Fib[1]=1,i=2;i^P;++i) Fib[i]=(Fib[i-1]+Fib[i-2])%X;for(read(n),i=1;i<=n;++i) read(a[i]);
	RI t=0;for(Or::Solve(),None::Solve(),Xor::Solve(),And::Solve(),i=1;i^P;i<<=1) t=(t+f[i])%X;return printf("%d\n",t),0;
}