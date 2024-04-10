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
#define V 1048575
#define LG 19
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
	Tp I void writeln(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc('\n');}
}using namespace FastIO;
int n,rt;class Trie
{
	private:
		#define PT RI l=0,RI r=V,RI d=LG
		#define LT l,u,d-1
		#define RT u+1,r,d-1
		#define New() (Et?Ep[Et--]:++Nt)
		#define D(x) (O[x].S[0]=O[x].S[1]=O[x].G=O[x].F=0,Ep[++Et]=x,x=0)
		#define PU(x)\
		(\
			O[x].Sz=O[O[x].S[0]].Sz+O[O[x].S[1]].Sz,\
			O[x].G=O[O[x].S[0]].G|O[O[x].S[1]].G|((O[x].S[0]&&O[x].S[1])<<d)\
		)
		#define PD(x)\
		(\
			O[x].F&&(Re(O[x].S[0],O[x].F,d-1),Re(O[x].S[1],O[x].F,d-1),O[x].F=0),\
			O[x].P[0]&&(T(O[x].S[0],O[x].P[0],0,d-1),T(O[x].S[1],O[x].P[0],0,d-1),O[x].P[0]=0),\
			O[x].P[1]&&(T(O[x].S[0],O[x].P[1],1,d-1),T(O[x].S[1],O[x].P[1],1,d-1),O[x].P[1]=0)\
		)
		int Nt,Et,Ep[N*60];struct node {int Sz,G,F,P[2],S[2];}O[N*60];
	public:
		I int Q(CI x) {return O[x].Sz;}
		I void Re(CI x,CI v,RI d=LG)
		{
			if(!x||!~d) return;v>>d&1&&(swap(O[x].S[0],O[x].S[1]),0);
			RI f0=O[x].P[0]&v,f1=O[x].P[1]&v;O[x].P[0]^=f0^f1,O[x].P[1]^=f0^f1,O[x].F^=v^f0^f1;
		}
		I void T(CI x,CI v,CI w,RI d=LG)
		{
			if(!x||!~d) return;v>>d&1&&O[x].S[w^1]&&(swap(O[x].S[w],O[x].S[w^1]),0);
			O[x].P[w]|=v,O[x].P[w^1]&=~v,O[x].F&=~v;
		}
		I void A(int& x,CI v,PT)
		{
			if(!x&&(x=New()),l==r) return (void)(O[x].Sz=1);
			RI u=l+r>>1;v<=u?A(O[x].S[0],v,LT):A(O[x].S[1],v,RT),PU(x);
		}
		I void Mg(int& x,int& y,PT)
		{
			if(!x||!y) return (void)(x|=y,y=0);if(l==r) return (void)D(y);RI u=l+r>>1;
			PD(x),PD(y),Mg(O[x].S[0],O[y].S[0],LT),Mg(O[x].S[1],O[y].S[1],RT),D(y),PU(x);
		}
		I void Sp(int& x,int& y,CI L,CI R,PT)
		{
			if(!x) return;if(L<=l&&r<=R) return (void)(y=x,x=0);RI u=l+r>>1;y=New();
			PD(x),L<=u&&(Sp(O[x].S[0],O[y].S[0],L,R,LT),0),R>u&&(Sp(O[x].S[1],O[y].S[1],L,R,RT),0);
			PU(y),O[x].S[0]||O[x].S[1]?PU(x):D(x);
		}
		I void U(int& x,CI v,CI w,PT)
		{
			if(!(O[x].G&v)) return T(x,v,w,d);RI u=l+r>>1;PD(x);
			if(v>>d&1) w?Mg(O[x].S[1],O[x].S[0],RT):Mg(O[x].S[0],O[x].S[1],LT);
			U(O[x].S[0],v,w,LT),U(O[x].S[1],v,w,RT),PU(x);
		}
}T;
int main()
{
	RI Qt,i,x;for(read(n,Qt),i=1;i<=n;++i) read(x),T.A(rt,x);
	RI o,op,y,z;W(Qt--) switch(read(op,x,y),op)
	{
		case 1:read(z),o=0,T.Sp(rt,o,x,y),T.U(o,(~z)&V,0),T.Mg(rt,o);break;
		case 2:read(z),o=0,T.Sp(rt,o,x,y),T.U(o,z,1),T.Mg(rt,o);break;
		case 3:read(z),o=0,T.Sp(rt,o,x,y),T.Re(o,z),T.Mg(rt,o);break;
		case 4:o=0,T.Sp(rt,o,x,y),writeln(T.Q(o)),T.Mg(rt,o);break;
	}return clear(),0;
}