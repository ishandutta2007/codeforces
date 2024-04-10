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
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int n,a[N+5];set<int> G;set<int>::iterator it;
class SegmentTree1
{
	private:
		#define PT RI l=1,RI r=n,RI o=1
		#define LT l,u,o<<1
		#define RT u+1,r,o<<1|1
		#define PU(x) (P[x]=P[x<<1]|P[x<<1|1],S[x]=S[x<<1]+S[x<<1|1])
		int P[N<<2],S[N<<2];
	public:
		void Bd(PT) {if(P[o]=0,S[o]=r-l+1,l==r) return;RI u=l+r>>1;Bd(LT),Bd(RT);}
		void U(CI x,CI v,PT) {if(l==r) return (void)(P[o]=v,S[o]=0);RI u=l+r>>1;x<=u?U(x,v,LT):U(x,v,RT);PU(o);}
		int Q(CI x,PT) Cn {if(l==r) return S[o]?-1:P[o];RI u=l+r>>1;return x<=u?Q(x,LT):Q(x,RT);}
		int Q1(CI L,CI R,PT) Cn {if(L<=l&&r<=R) return P[o];RI u=l+r>>1;return (L<=u?Q1(L,R,LT):0)||(R>u?Q1(L,R,RT):0);}
		int C(CI L,CI R,PT) Cn {if(L<=l&&r<=R) return S[o];RI u=l+r>>1;return (L<=u?C(L,R,LT):0)+(R>u?C(L,R,RT):0);}
}S;
int qt,ql[N+5],qr[N+5];class SegmentTree2
{
	private:
		#define PU(x) (A[x]=min(A[x<<1],A[x<<1|1]),V[x]=min(V[x<<1],V[x<<1|1]))
		#define PD(x) (F[x]&&(T(x<<1,F[x]),T(x<<1|1,F[x]),F[x]=0))
		#define T(x,v) (V[x]+=v,F[x]+=v)
		int A[N<<2],V[N<<2],F[N<<2];
	public:
		void Bd(PT) {if(A[o]=V[o]=1e9,l==r) return;RI u=l+r>>1;Bd(LT),Bd(RT);}
		void U(CI x,CI a,CI v,PT) {if(l==r) return (void)(A[o]=a,V[o]=v);RI u=l+r>>1;PD(o);x<=u?U(x,a,v,LT):U(x,a,v,RT),PU(o);}
		int Q(CI x,PT) Cn {if(l==r) return A[o];RI u=l+r>>1;return x<=u?Q(x,LT):Q(x,RT);}
		void D(CI x,CI y,PT)
		{
			if(V[o]>n) return;if(r<=x&&A[o]>=y&&V[o]>2) return (void)T(o,-1);
			if(l==r) return (void)(r<=x&&A[o]>=y&&(ql[++qt]=l,qr[qt]=A[o],A[o]=V[o]=1e9));
			RI u=l+r>>1;PD(o),A[o<<1|1]>y&&(D(x,y,LT),0),x>u&&(D(x,y,RT),0),PU(o);
		}
		void E(CI x,CI y,PT)
		{
			if(V[o]>n) return;if(l==r) return (void)(r<=x&&A[o]>=y&&(A[o]=V[o]=1e9));
			RI u=l+r>>1;PD(o),A[o<<1|1]>y&&(E(x,y,LT),0),x>u&&(E(x,y,RT),0),PU(o);
		}
}A;
I void U1(RI x) {G.erase(x),S.U(x,1),A.E(x,x);}
I void U0(RI x) {G.erase(x),S.U(x,0),A.D(x,x);W(qt) (it=G.lower_bound(ql[qt]))!=G.end()&&*it<=qr[qt]&&(U1(*it),0),--qt;}
int main()
{
	RI Qt,i,op,l,r,x;for(read(n,Qt),i=1;i<=n;++i) G.insert(i);A.Bd(),S.Bd();W(Qt--)
	{
		if(read(op),op) {read(x),x=S.Q(x),puts(~x?(x?"YES":"NO"):"N/A");continue;}
		if(read(l,r,x),x) A.Q(l)>r&&!S.Q1(l,r)&&(A.E(l,r),(x=S.C(l,r))==1?U1(*G.lower_bound(l)):A.U(l,r,x),0);
		else W((it=G.lower_bound(l))!=G.end()&&*it<=r) U0(*it);
	}return 0;
}