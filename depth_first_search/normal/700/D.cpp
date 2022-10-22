#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 100000
#define BS 1660
#define Pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int n,a[N+5],c[N+5],h[N+5],g[N+5],sz,bl[N+5];long long ans[N+5];
struct Q {int p,l,r;I bool operator < (Cn Q& o) Cn {return bl[l]^bl[o.l]?bl[l]<bl[o.l]:(bl[l]&1?r<o.r:r>o.r);}}q[N+5];
int tA,tB;pair<int,int> A[N+5],B[N+5];
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
Pr O;I Pr Get(int& pA,int& pB)
{
	if(O.se) {Pr t=O;return O=mp(0,0),t;}
	if(pA>tA) return B[pB++];if(pB>tB) return A[pA++];if(A[pA].fi^B[pB].fi) return A[pA].fi<B[pB].fi?A[pA++]:B[pB++];
	Pr t=mp(A[pA].fi,A[pA].se+B[pB].se);return ++pA,++pB,t;
}
int main()
{
	RI Qt,i,j;for(read(n),sz=sqrt(n),i=1;i<=n;++i) read(a[i]),++c[a[i]],bl[i]=(i-1)/sz+1;
	RI ht=0;for(i=1;i<=N;++i) c[i]>BS&&(h[++ht]=i),c[i]=0;
	for(read(Qt),i=1;i<=Qt;++i) read(q[i].l,q[i].r),q[i].p=i;sort(q+1,q+Qt+1);
	RI L=1,R=0,o,pA,pB;Pr t,w;for(i=1;i<=Qt;++i)
	{
		W(R<q[i].r) ++R,--g[c[a[R]]],++c[a[R]],++g[c[a[R]]];W(L>q[i].l) --L,--g[c[a[L]]],++c[a[L]],++g[c[a[L]]];
		W(R>q[i].r) --g[c[a[R]]],--c[a[R]],++g[c[a[R]]],--R;W(L<q[i].l) --g[c[a[L]]],--c[a[L]],++g[c[a[L]]],++L;
		#define Empty() (pA>tA&&pB>tB&&!O.se)
		for(tA=tB=0,j=1;j<=BS;++j) g[j]&&(A[++tA]=mp(j,g[j]),0);
		for(o=tA,j=1;j<=ht;++j) c[h[j]]>BS&&(A[++tA]=mp(c[h[j]],1),0);sort(A+o+1,A+tA+1);
		pA=pB=1;W(!Empty())
		{
			t=Get(pA,pB),t.se>1&&(ans[q[i].p]+=1LL*(t.fi<<1)*(t.se>>1),B[++tB]=mp(t.fi<<1,t.se>>1),t.se&=1);
			if(!t.se) continue;if(Empty()) break;w=Get(pA,pB),ans[q[i].p]+=t.fi+w.fi,B[++tB]=mp(t.fi+w.fi,1),--w.se&&(O=w,0);
		}
	}
	for(i=1;i<=Qt;++i) writeln(ans[i]);return clear(),0;
}