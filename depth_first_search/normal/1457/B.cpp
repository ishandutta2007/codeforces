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
using namespace std;
int n,k,a[N+5];
class FastIO
{
	private:
		#define FS 100000
		#define tc() (A==B&&(B=(A=FI)+fread(FI,1,FS,stdin),A==B)?EOF:*A++)
		#define pc(c) (C==E&&(clear(),0),*C++=c)
		#define D isdigit(c=tc())
		int T;char c,*A,*B,*C,*E,FI[FS],FO[FS],S[FS];
	public:
		I FastIO() {A=B=FI,C=FO,E=FO+FS;}
		Tp I void read(Ty& x) {x=0;W(!D);W(x=(x<<3)+(x<<1)+(c&15),D);}
		Tp I void writeln(Ty x) {W(S[++T]=x%10+48,x/=10);W(T) pc(S[T--]);pc('\n');}
		I void clear() {fwrite(FO,1,C-FO,stdout),C=FO;}
}F;
int main()
{
	RI Tt,i,j,t,ans;F.read(Tt);W(Tt--)
	{
		for(F.read(n),F.read(k),ans=n,i=1;i<=n;++i) F.read(a[i]);
		for(i=1;i<=100;++i) {for(t=0,j=1;j<=n;++j) a[j]^i&&(++t,j+=k-1);ans=min(ans,t);}
		printf("%d\n",ans);
	}return 0;
}