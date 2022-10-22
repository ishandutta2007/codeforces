#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 150000
#define X 998244353
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int n,m,pw[N+5];class Trie
{
	private:
		int Nt;struct node {int Sz,S[2];}O[N*30];
	public:
		I void Ins(int& o,CI x,RI d=30) {!o&&(o=++Nt),++O[o].Sz;if(!~d) return;Ins(O[o].S[x>>d&1],x,d-1);}
		I int F(CI o,RI d=30)
		{
			if(!o||!~d) return pw[O[o].Sz];
			return m>>d&1?G(O[o].S[0],O[o].S[1],d-1):(F(O[o].S[0],d-1)+F(O[o].S[1],d-1)-1LL+X)%X;
		}
		I int G(CI x,CI y,RI d)
		{
			if(!x||!y||!~d) return pw[O[x].Sz+O[y].Sz];
			RI A=O[x].S[0],B=O[x].S[1],C=O[y].S[0],D=O[y].S[1];
			if(m>>d&1) return 1LL*G(A,D,d-1)*G(B,C,d-1)%X;
			RI t=(0LL+G(A,C,d-1)+G(B,D,d-1)+pw[O[A].Sz+O[B].Sz]+pw[O[C].Sz+O[D].Sz])%X;
			return t=(4LL*X+t-pw[O[A].Sz]-pw[O[B].Sz]-pw[O[C].Sz]-pw[O[D].Sz])%X,(t+1)%X;
		}
}T;
int main()
{
	RI i,x,rt=0;for(read(n,m),i=1;i<=n;++i) read(x),T.Ins(rt,x);
	for(pw[0]=i=1;i<=n;++i) pw[i]=(pw[i-1]<<1)%X;return printf("%d\n",(T.F(rt)-1+X)%X),0;
}