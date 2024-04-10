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
int n,k,a[N+5],s[2*N+5],dc,dv[2*N+5];struct Q {int x,l,r;}q[N+5];
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
class SegmentTree
{
	private:
		#define PT CI l,CI r,CI rt
		#define LT l,mid,rt<<1
		#define RT mid+1,r,rt<<1|1
		#define PU(x) (O[x].V=min(O[x<<1].V,O[x<<1|1].V))
		#define PD(x) O[x].F&&(T(x<<1,O[x].F),T(x<<1|1,O[x].F),O[x].F=0)
		#define T(x,v) (O[x].V=O[x].F=v)
		int n;struct node {int V,F;}O[N<<3];
		I void Build(int* v,PT)
		{
			if(l==r) return (void)(O[rt].V=v[l]);RI mid=l+r>>1;Build(v,LT),Build(v,RT),PU(rt);
		}
		I void U(CI L,CI R,CI v,PT)
		{
			if(L<=l&&r<=R) return (void)T(rt,v);RI mid=l+r>>1;PD(rt);
			L<=mid&&(U(L,R,v,LT),0),R>mid&&(U(L,R,v,RT),0),PU(rt);
		}
		I int Q(CI L,CI R,PT)
		{
			if(L<=l&&r<=R) return O[rt].V;RI mid=l+r>>1;PD(rt);
			return min(L<=mid?Q(L,R,LT):1e9,R>mid?Q(L,R,RT):1e9);
		}
	public:
		I void Build(CI _n,int* v) {Build(v,1,n=_n,1);}
		I void U(CI L,CI R,CI v) {U(L,R,v,1,n,1);}I int Q(CI L,CI R) {return Q(L,R,1,n,1);}
}S;
I int Qry(RI L,RI R)
{
	if(R-L+1>=n) return S.Q(1,n);return (L=(L-1)%n+1)<=(R=(R-1)%n+1)?S.Q(L,R):min(S.Q(L,n),S.Q(1,R));
}
int main()
{
	RI Qt,i;for(read(n,k),i=1;i<=n;++i) read(a[i]);
	for(read(Qt),i=1;i<=Qt;++i) read(q[i].x,q[i].l,q[i].r),
		q[i].x==1?(read(q[i].x),0):q[i].x=0,dv[2*i-1]=q[i].l,dv[2*i]=q[i].r+1;
	sort(dv+1,dv+2*Qt+1),dc=unique(dv+1,dv+2*Qt+1)-dv-1;
	for(S.Build(n,a),i=1;i^dc;++i) s[i]=Qry(dv[i],dv[i+1]-1);S.Build(dc-1,s);
	#define G(x) lower_bound(dv+1,dv+dc+1,x)-dv
	for(i=1;i<=Qt;++i) q[i].l=G(q[i].l),q[i].r=G(q[i].r+1)-1,
		q[i].x?S.U(q[i].l,q[i].r,q[i].x):writeln(S.Q(q[i].l,q[i].r));return clear(),0;
}