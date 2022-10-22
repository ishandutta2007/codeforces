#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typenaem Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
using namespace std;
int n,a[2*N+5];
class FastIO
{
	private:
		#define FS 100000
		#define pc(c) (C==E&&(clear(),0),*C++=c)
		int T;char c,*C,*E,FO[FS],S[FS];
	public:
		I FastIO() {C=FO,E=FO+FS;}
		Tp I void write(Ty x) {W(S[++T]=x%10+48,x/=10);W(T) pc(S[T--]);}
		Tp I void write(Con Ty& x,Con char& y) {write(x),pc(y);}
		I void clear() {fwrite(FO,1,C-FO,stdout),C=FO;}
}F;
int main()
{
	RI i;if(scanf("%d",&n),!(n&1)) return puts("NO"),0;puts("YES");
	for(i=1;i<=n;++i) i&1?(a[i]=2*i-1,a[n+i]=2*i):(a[i]=2*i,a[n+i]=2*i-1);
	for(i=1;i<=2*n;++i) F.write(a[i]," \n"[i==2*n]);return F.clear(),0;
}