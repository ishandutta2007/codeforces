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
using namespace std;
int n;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	I void readc(char& x) {W(isspace(x=tc()));}
	Tp I void writeln(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc('\n');}
}using namespace FastIO;
int Tsz;struct TreeArray
{
	int a[2*N+5];I void A(RI x,CI v) {if(!~x) return;W(x<=Tsz) a[x]+=v,x+=x&-x;}
	I int Q(RI x) {RI t=0;W(x) t+=a[x],x-=x&-x;return t;}
}T;
class LinkCutTree
{
	private:
		#define IR(x) (O[O[x].F].S[0]^x&&O[O[x].F].S[1]^x)
		#define Wh(x) (O[O[x].F].S[1]==x)
		#define Co(x,y,d) (O[O[x].F=y].S[d]=x)
		#define PU(x) (O[x].Sz=O[O[x].S[0]].Sz+O[O[x].S[1]].Sz+1)
		#define PD(x) (O[x].P&&(Ts(O[x].S[0],O[x].P),Ts(O[x].S[1],O[x].P),O[x].P=0),O[x].R&&(Re(O[x].S[0]),Re(O[x].S[1]),O[x].R=0))
		#define Ts(x,v) (O[x].G=O[x].P=v)
		#define Re(x) (x)&&(swap(O[x].S[0],O[x].S[1]),O[x].R^=1)
		int St[N+5];struct node {int Sz,G,P,F,R,S[2];}O[N+5];
		I void Ro(RI x) {RI f=O[x].F,p=O[f].F,d=Wh(x);!IR(f)&&(O[p].S[Wh(f)]=x),O[x].F=p,Co(O[x].S[d^1],f,d),Co(f,x,d^1),PU(f);}
		I void S(RI x) {RI f=x,T=0;W(St[++T]=f,!IR(f)) f=O[f].F;W(T) PD(St[T]),--T;W(!IR(x)) f=O[x].F,!IR(f)&&(Ro(Wh(x)^Wh(f)?x:f),0),Ro(x);PU(x);}
		I int FR(RI x) {Ac(x),S(x);W(O[x].S[0]) PD(x),x=O[x].S[0];return S(x),x;}
	public:
		I void Init() {O[0].G=-1;for(RI i=1;i<=n;++i) O[i].G=-1,O[i].Sz=1;}
		I void Link(CI x,CI y) {MR(x),O[x].F=y;}I void MR(CI x) {Ac(x),S(x),Re(x);}
		I int Q(CI x) {return S(x),T.Q(O[x].G-1)+O[O[x].S[1]].Sz+1;}
		I void Ac(RI x,CI tg=-1)
		{
			RI y;for(y=0;x;x=O[y=x].F) S(x),T.A(O[x].G,-O[x].Sz),T.A(O[O[x].S[1]].G,O[O[x].S[1]].Sz),O[x].S[1]=y,PU(x);
			Ts(y,tg),T.A(tg,O[y].Sz);
		}
}LCT;
int main()
{
	RI Qt,i,x,y;for(read(n,Qt),Tsz=n+Qt,LCT.Init(),i=1;i^n;++i) read(x,y),LCT.Link(x,y);
	for(LCT.MR(n),i=1;i^n;++i) LCT.Ac(i,i);
	char op;RI rt=n,tt=n;W(Qt--)
	{
		if(readc(op),read(x),op=='u') {rt^x&&(LCT.MR(x),LCT.Ac(rt,tt),rt=x,++tt);continue;}
		op=='w'?writeln(LCT.Q(x)):(read(y),writeln(LCT.Q(x)<LCT.Q(y)?x:y));
	}return clear(),0;
}