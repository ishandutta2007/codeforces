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
#define M 500000
using namespace std;
int n,m,s[3*N+5],ans[M+5];
class FastIO
{
	private:
		#define FS 100000
		#define tc() (A==B&&(B=(A=FI)+fread(FI,1,FS,stdin),A==B)?EOF:*A++)
		#define pc(c) (C==E&&(clear(),0),*C++=c)
		#define tn (x<<3)+(x<<1)
		#define D isdigit(c=tc())
		int T;char c,*A,*B,*C,*E,FI[FS],FO[FS],S[FS];
	public:
		I FastIO() {A=B=FI,C=FO,E=FO+FS;}
		Tp I void read(Ty& x) {x=0;W(!D);W(x=tn+(c&15),D);}
		Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
		Tp I void write(Ty x) {W(S[++T]=x%10+48,x/=10);W(T) pc(S[T--]);}
		Tp I void write(Con Ty& x,Con char& y) {write(x),pc(y);}
		I void writes(Con string& s) {for(RI i=0,l=s.length();i^l;++i) pc(s[i]);}
		I void clear() {fwrite(FO,1,C-FO,stdout),C=FO;}
}F;
int main()
{
	RI Tt,i,t,x,y;F.read(Tt);W(Tt--)
	{
		for(F.read(n,m),i=1;i<=3*n;++i) s[i]=0;
		for(t=0,i=1;i<=m;++i) F.read(x,y),!s[x]&&!s[y]&&(s[x]=s[y]=1,ans[++t]=i);
		if(t>=n) for(F.writes("Matching\n"),i=1;i<=n;++i) F.write(ans[i]," \n"[i==n]);
		else for(F.writes("IndSet\n"),t=0,i=1;i<=3*n&&t^n;++i) !s[i]&&(F.write(i," \n"[++t==n]),0);
	}return F.clear(),0;
}