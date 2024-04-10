#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 500000
#define Pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int n,p[N+5];set<int> K;
struct TreeArray
{
	int a[N+5];I void U(RI x) {W(x<=n) ++a[x],x+=x&-x;}
	I int Q(RI x) {RI t=0;W(x) t+=a[x],x-=x&-x;return t;}
}T1,T2;
I int QV(CI x) {return abs((x-T1.Q(x))-(p[x]-T2.Q(p[x])));}
struct Solver
{
	int id,op,p[N+5];set<Pr> G;set<Pr>::iterator it;
	class SegmentTree
	{
		private:
			#define PT RI l=1,RI r=n,RI o=1
			#define LT l,u,o<<1
			#define RT u+1,r,o<<1|1
			#define PU(o) (Mn[o]=min(Mn[o<<1],Mn[o<<1|1]),V[o]=min(V[o<<1],V[o<<1|1]))
			#define PD(o) (G[o]&&(T(o<<1,G[o]),T(o<<1|1,G[o]),G[o]=0))
			#define T(o,v) (V[o].fi+=v,G[o]+=v)
			Pr Mn[N<<2],V[N<<2];int G[N<<2];
		public:
			int id;
			void Bd(PT) 
			{
				if(l==r) return (void)(Mn[o]=V[o]=mp(1e9,l));RI u=l+r>>1;Bd(LT),Bd(RT),PU(o);
			}
			void A(CI x,CI p,CI q,PT)
			{
				if(l==r) return (void)(Mn[o].fi=p,V[o].fi=q);
				RI u=l+r>>1;PD(o),x<=u?A(x,p,q,LT):A(x,p,q,RT),PU(o);
			}
			void D(CI x,PT)
			{
				if(l==r) return (void)(Mn[o].fi=V[o].fi=1e9);RI u=l+r>>1;PD(o),x<=u?D(x,LT):D(x,RT),PU(o);
			}
			void U(CI L,CI R,CI v,PT)
			{
				if(L<=l&&r<=R) return (void)T(o,v);RI u=l+r>>1;PD(o),L<=u&&(U(L,R,v,LT),0),R>u&&(U(L,R,v,RT),0),PU(o); 
			}
			Pr F(CI L,PT)
			{
				if(L>n) return mp(1e9,0);if(L<=l) return Mn[o];
				RI u=l+r>>1;PD(o);if(L>u) return F(L,RT);return min(F(L,LT),F(L,RT));
			}
			void Z(PT)
			{
				if(V[o].fi) return;if(l==r) return (void)(K.insert(id==1?l:n-l+1));
				RI u=l+r>>1;PD(o),Z(LT),Z(RT),PU(o);
			}
			I Pr Q() Cn {return V[1];}
			I int Q(CI x,PT)
			{
				if(l==r) return V[o].fi;RI u=l+r>>1;PD(o);return x<=u?Q(x,LT):Q(x,RT);
			}
	}S;
	I void Bd(CI o) {op=(S.id=id=o)==1?1:-1,S.Bd();}
	I void A(CI x) {S.A(x,op*p[x],QV(id==1?x:n-x+1));}
	I void Init() {for(Pr x=S.F(1);x.fi<1e9;x=S.F(x.se+1)) G.insert(x);}
	I void Del(CI x)
	{
		if((it=G.find(mp(op*p[x],x)))==G.end()) return;G.erase(it),S.D(x),it=G.upper_bound(mp(op*p[x],x));
		for(Pr y=S.F(it!=G.begin()?(--it)->se+1:1);y.fi<1e9&&G.find(y)==G.end();y=S.F(y.se+1)) A(y.se),G.insert(y);
	}
	I void U(CI x)
	{
		if(id==1) S.U(x,n,1),(it=G.lower_bound(mp(p[x],x)))!=G.end()&&(S.U(it->se,n,-1),0);
		else S.U(1,x,-1),(it=G.lower_bound(mp(-p[x],x)))!=G.begin()&&(S.U(1,(--it)->se,1),0);S.Z();
	}
}S1,S2;
int ans;I void Del(CI id,RI x)
{
	K.erase(x),S1.Del(x),S2.Del(n-x+1),ans=max(ans,QV(x)),T1.U(x),T2.U(p[x]),S1.U(x),S2.U(n-x+1);
}
int main()
{
	RI i;for(read(n),i=1;i<=n;++i) read(p[i]),S1.p[i]=p[i],S2.p[n-i+1]=p[i];
	for(S1.Bd(1),S2.Bd(2),i=1;i<=n;++i) i<p[i]?S1.A(i):(i>p[i]?S2.A(n-i+1):(void)(K.insert(i)));S1.Init(),S2.Init();
	for(i=1;i<=n;++i) if(!K.empty()) Del(0,*K.begin());else S1.S.Q()<S2.S.Q()?Del(1,S1.S.Q().se):Del(2,n-S2.S.Q().se+1);
	return printf("%d\n",ans),0;
}