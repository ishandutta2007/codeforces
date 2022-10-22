#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 50
#define M 50000
#define SZ (2*N*M)
#define LL long long
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	I void readc(char& x) {W(isspace(x=tc()));}
}using namespace FastIO;
int n,rt,St[M+5];LL P;struct Q {char op;LL x,y;}q[M+5];
struct Il {LL l,r;bool operator < (Cn Il& o) Cn {return l^o.l?l<o.l:r<o.r;}}s[M+5];
int Nt,ct,g[2*N+5];struct node {LL l,r;int H,Ex,S[2];}O[SZ+5];
int f[SZ+5];int fa(CI x) {return f[x]?f[x]=fa(f[x]):x;}I void U(RI x,RI y) {(x=fa(x))^(y=fa(y))&&(f[y]=x);}
void U(int& o,LL L,LL R,LL l=0,LL r=P-1)
{
	#define Get(x) make_pair((Il){O[x].l,O[x].r},x)
	if(O[o].Ex) return;if(!o&&(O[o=++Nt].l=l,O[o].r=r),L<=l&&r<=R) return (void)(O[g[++ct]=o].Ex=1);
	LL u=l+r>>1;L<=u&&(U(O[o].S[0],L,R,l,u),0),R>u&&(U(O[o].S[1],L,R,u+1,r),0);
	if(!O[O[o].S[0]].Ex||!O[O[o].S[1]].Ex) return;RI lc=O[o].S[0],rc=O[o].S[1];
	W(ct&&(g[ct]==lc||g[ct]==rc)) --ct;U(o,O[o].S[0]),U(o,O[o].S[1]),O[g[++ct]=o].Ex=1;
}
void K(CI o,LL L,LL R,CI x,LL l=0,LL r=P-1)
{
	if(!o) return;if(O[o].Ex) return U(x,o);if(L<=l&&r<=R) {if(O[o].H) return U(x,O[o].H);O[o].H=x;}
	LL u=l+r>>1;L<=u&&(K(O[o].S[0],L,R,x,l,u),0),R>u&&(K(O[o].S[1],L,R,x,u+1,r),0);
}
int ID(CI o,LL x,LL l=0,LL r=P-1) {if(O[o].Ex) return o;LL u=l+r>>1;return x<=u?ID(O[o].S[0],x,l,u):ID(O[o].S[1],x,u+1,r);}
I void Link(CI x) {for(RI i=0;i^n;++i) if((O[x].l>>i&1)==(O[x].r>>i&1)) K(rt,O[x].l^(1LL<<i),O[x].r^(1LL<<i),x);}
I void A(LL L,LL R) {ct=0,U(rt,L,R);for(RI i=1;i<=ct;++i) Link(g[i]);}
int main()
{
	RI Qt,i,c=0;for(read(n,Qt),P=1LL<<n,i=1;i<=Qt;++i) readc(q[i].op),read(q[i].x,q[i].y);
	for(i=Qt;q[i].op=='b';--i);for(;i;--i) q[i].op=='b'&&(s[++c]=(Il){q[i].x,q[i].y},0);sort(s+1,s+c+1);
	if(c) for(s[1].l&&(A(0,s[1].l-1),0),i=1;i^c;++i) s[i+1].l-s[i].r>1&&(A(s[i].r+1,s[i+1].l-1),0);s[c].r<P-1&&(A(s[c].r+1,P-1),0);
	RI T=0,fir,cnt=0;for(cnt=1;q[cnt].op=='a';++cnt);for(fir=cnt--;fir<=Qt&&q[fir].op=='b';++fir);
	for(i=Qt;i>=fir;--i) q[i].op=='a'?St[++T]=fa(ID(rt,q[i].x))==fa(ID(rt,q[i].y)):(A(q[i].x,q[i].y),0);
	W(cnt--) puts("1");W(T) putchar(48|St[T--]),putchar('\n');return 0;
}