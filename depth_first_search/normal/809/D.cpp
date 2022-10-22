#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 300000
#define INF (int)2e9
using namespace std;
int n;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
class FHQTreap
{
	private:
		#define Rd() (sd=(324682339ull*sd+456789001)%998244353)
		#define SX O[k].S[1],O[x].S[1],y
		#define SY O[k].S[0],x,O[y].S[0]
		#define PD(x) (O[x].F&&(O[x].S[0]&&T(O[x].S[0],O[x].F),O[x].S[1]&&T(O[x].S[1],O[x].F),O[x].F=0))
		#define T(x,v) (O[x].V+=v,O[x].F+=v)
		int sd,rt,Nt;struct node {int D,V,F,S[2];}O[2*N+5];
		I int New(CI v) {return O[++Nt].D=Rd(),O[Nt].V=v,Nt;}
		I void Mg(int& k,RI x,RI y) {if(!x||!y) return (void)(k=x|y);O[x].D>O[y].D?(k=x,PD(x),Mg(SX)):(k=y,PD(y),Mg(SY));}
		I void Sp(RI k,int& x,int& y,CI v) {if(!k) return (void)(x=y=0);PD(k),O[k].V<v?(x=k,Sp(SX,v)):(y=k,Sp(SY,v));}
		I void SpL(RI k,int& x,int& y,CI f=1) {if(!k) return (void)(x=y=0);PD(k),f&&!O[k].S[0]?(x=k,SpL(SX,0)):(y=k,SpL(SY,f));}
		I void Bd(CI l,CI r,int& rt) {RI mid=l+r>>1;rt=New(mid?INF:0);l^mid&&(Bd(l,mid-1,O[rt].S[0]),0),r^mid&&(Bd(mid+1,r,O[rt].S[1]),0);}
		I void U(CI x) {T(x,1);}I int Sz(CI x) {return x?(Sz(O[x].S[0])+Sz(O[x].S[1])+1):0;}
		I void Print(CI x) {if(x) {Print(O[x].S[0]),cout<<O[x].V<<" ",Print(O[x].S[1]);}}
	public:
		I void Init() {Bd(0,n,rt);}
		I void U(CI x,CI y) {RI a,b,c,d,k=New(x);Sp(rt,a,b,x),Sp(b,b,c,y),U(b),Mg(b,k,b),SpL(c,d,c),Mg(b,b,c),Mg(rt,a,b);}
		I void GetAns() {RI a,b;Sp(rt,a,b,INF),printf("%d\n",Sz(a)-1);}
}T;
int main()
{
	RI i,x,y;for(read(n),T.Init(),i=1;i<=n;++i) read(x,y),T.U(x,y);return T.GetAns(),0;
}