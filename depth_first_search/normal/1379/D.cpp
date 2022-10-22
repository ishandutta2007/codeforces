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
int n,h,m,k;struct Data
{
	int p,v;I bool operator < (Con Data& o) Con {return v<o.v;}
}s[2*N+5];
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
		Tp I void write(Ty x) {W(S[++T]=x%10+48,x/=10);W(T) pc(S[T--]);}
		Tp I void write(Con Ty& x,Con char& y) {write(x),pc(y);}
		I void clear() {fwrite(FO,1,C-FO,stdout),C=FO;}
}F;
int main()
{
	RI i,x;F.read(n),F.read(h),F.read(m),m>>=1,F.read(k);
	for(i=1;i<=n;++i) F.read(x),F.read(s[i].v),s[i].v%=m,s[i].p=s[n+i].p=i,s[n+i].v=s[i].v+m;
	RI j=1,l=0,r=n+1;for(sort(s+1,s+2*n+1),i=n+1;i<=2*n;++i) {W(s[j].v<s[i].v-k+1) ++j;i-j<r-l&&(l=j,r=i);}
	for(F.write(r-l,' '),F.write(s[r].v-m,'\n'),i=l;i^r;++i) F.write(s[i].p," \n"[i==r-1]);return F.clear(),0;
}