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
#define LL long long
using namespace std;
int n;LL a[N+5];I LL Nxt(Con LL& x) {LL t=1;W(t<x) t*=42;return t;}
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
		#define PT CI l=1,CI r=n,CI rt=1
		#define LT l,mid,rt<<1
		#define RT mid+1,r,rt<<1|1
		#define PU(x) (V[x]=min(D[x<<1]?1e18:V[x<<1],D[x<<1|1]?1e18:V[x<<1|1]))
		#define PD(x) (D[x]&&(D[x<<1]=D[x<<1|1]=1,D[x]=F[x]=0),F[x]&&(T(x<<1,F[x]),T(x<<1|1,F[x]),F[x]=0))
		#define T(x,v) (!D[x]&&(V[x]-=v,F[x]+=v))
		int D[N<<2];LL V[N<<2],F[N<<2];
	public:
		I void Bd(PT)
		{
			if(l==r) return (void)(V[rt]=Nxt(a[l])-a[l]);RI mid=l+r>>1;Bd(LT),Bd(RT),PU(rt);
		}
		I void U(CI x,Con LL& v,PT)
		{
			if(l==r) return (void)(a[l]=v,V[rt]=Nxt(a[l])-a[l],D[rt]=0);
			RI mid=l+r>>1;PD(rt),x<=mid?U(x,v,LT):U(x,v,RT),PU(rt);
		}
		I void E(CI L,CI R,PT)
		{
			if(D[rt]) return;if(L<=l&&r<=R) return (void)(D[rt]=1);RI mid=l+r>>1;
			PD(rt),L<=mid&&(E(L,R,LT),0),R>mid&&(E(L,R,RT),0),PU(rt);
		}
		I void M(CI L,CI R,CI v,PT)
		{
			if(D[rt]) return;if(l==r) return (void)(a[l]=Nxt(a[l])-V[rt]+v,V[rt]=Nxt(a[l])-a[l]);
			if(L<=l&&r<=R&&V[rt]>v) return (void)T(rt,v);RI mid=l+r>>1;
			PD(rt),L<=mid&&(M(L,R,v,LT),0),R>mid&&(M(L,R,v,RT),0),PU(rt);
		}
		I LL Q(CI x,PT)
		{
			if(l==r) return Nxt(a[l])-V[rt];RI mid=l+r>>1;return PD(rt),x<=mid?Q(x,LT):Q(x,RT);
		}
		I LL Mn(CI L,CI R,PT)
		{
			if(D[rt]) return 1e18;if(L<=l&&r<=R) return V[rt];RI mid=l+r>>1;
			return PD(rt),min(L<=mid?Mn(L,R,LT):1e18,R>mid?Mn(L,R,RT):1e18);
		}
}S;
namespace ODT
{
	#define IT set<Il>::iterator
	struct Il {int l,r;I Il(CI a=0,CI b=0):l(a),r(b){}I bool operator < (Con Il& o) Con {return l<o.l;}};set<Il> s;
	I IT Split(CI x)
	{
		IT it=s.lower_bound(x);if(it->l==x) return it;RI l=(--it)->l,r=it->r;LL v=S.Q(l);
		return S.U(x,v),s.erase(it),s.insert(Il(l,x-1)),s.insert(Il(x,r)).first;
	}
	I void Assign(CI l,CI r,CI v)
	{
		IT tr=Split(r+1),tl=Split(l);S.U(l,v),l^r&&(S.E(l+1,r),0),s.erase(tl,tr),s.insert(Il(l,r));
	}
}
int main()
{
	RI Qt,i;for(read(n,Qt),i=1;i<=n;++i) read(a[i]),ODT::s.insert(ODT::Il(i,i));S.Bd();
	RI op,x,y,z;W(Qt--) switch(read(op,x),op)
	{
		case 1:ODT::Split(x),writeln(S.Q(x));break;case 2:read(y,z),ODT::Assign(x,y,z);break;
		case 3:read(y,z),ODT::Split(y+1),ODT::Split(x),S.M(x,y,z);W(!S.Mn(x,y)) S.M(x,y,z);break;
	}return clear(),0;
}