#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 300000
#define LL long long
#define INF (LL)1e18
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,m,ee,lnk[N+5];struct edge {int to,nxt;}e[2*N+5];
struct Data {int d,v;};vector<Data> s[N+5];
namespace FastIO
{
	#define FS 10000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
class SegmentTree
{
	private:
		#define SZ N*22
		#define PT CI l=1,CI r=n
		#define LT l,mid
		#define RT mid+1,r
		#define PU(x) (O[x].V=min(O[O[x].S[0]].V,O[O[x].S[1]].V))
		#define PD(x) (O[x].F&&(T(O[x].S[0],O[x].F),T(O[x].S[1],O[x].F),O[x].F=0))
		#define T(x,v) (x&&(O[x].V=min(O[x].V+v,INF),O[x].F=min(O[x].F+v,INF)))
		#define Del(x) (Et^N&&(EP[++Et]=x),x=0)
		int Nt,Et,EP[N+5];struct node {LL V,F;int S[2];}O[SZ+1];
		I int New() {RI k=Et?EP[Et--]:++Nt;return O[k].V=INF,O[k].S[0]=O[k].S[1]=0,k;}
	public:
		I SegmentTree() {O[0].V=INF;}
		I void U(int& rt,CI x,Con LL& v,PT)
		{
			if(!rt&&(rt=New()),l==r) return (void)(O[rt].V=min(O[rt].V,v));
			RI mid=l+r>>1;PD(rt);x<=mid?U(O[rt].S[0],x,v,LT):U(O[rt].S[1],x,v,RT),PU(rt);
		}
		I void E(int& rt,CI x,PT)
		{
			if(l==r) return (void)Del(rt);RI mid=l+r>>1;PD(rt);
			x<=mid?E(O[rt].S[0],x,LT):E(O[rt].S[1],x,RT),!O[rt].S[0]&&!O[rt].S[1]?Del(rt):PU(rt);
		}
		I LL Q(CI rt,CI L,CI R,PT)
		{
			if(!rt||L<=l&&r<=R) return O[rt].V;RI mid=l+r>>1;PD(rt);
			return min(L<=mid?Q(O[rt].S[0],L,R,LT):INF,R>mid?Q(O[rt].S[1],L,R,RT):INF);
		}
		I void Merge(int& x,RI y,Con LL& vx=INF,Con LL& vy=INF,PT)
		{
			if(!y) return (void)T(x,vy);if(!x) return (void)(x=y,T(x,vx));
			if(l==r) return (void)(O[x].V=min(min(O[x].V+vy,O[y].V+vx),min(O[x].V+O[y].V,INF)),Del(y));
			RI mid=l+r>>1;PD(x),PD(y);
			Merge(O[x].S[0],O[y].S[0],min(vx,O[O[x].S[1]].V),min(vy,O[O[y].S[1]].V),LT);
			Merge(O[x].S[1],O[y].S[1],vx,vy,RT),Del(y),PU(x);
		}
}S;
int dep[N+5];I void Init(CI x=1,CI lst=0)
{
	for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&(dep[e[i].to]=dep[x]+1,Init(e[i].to,x),0);
}
int Rt[N+5];vector<Data>::iterator it;I void dfs(CI x=1,CI lst=0)
{
	S.U(Rt[x],dep[x]+1,0);for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&(dfs(e[i].to,x),S.Merge(Rt[x],Rt[e[i].to]),0);
	LL v;for(it=s[x].begin();it!=s[x].end();++it) (v=S.Q(Rt[x],it->d+1,dep[x]+1)+it->v)<INF&&(S.U(Rt[x],it->d,v),0);
	x^1&&(S.E(Rt[x],dep[x]+1),0);
}
int main()
{
	RI i,x,y,z;for(read(n,m),i=1;i^n;++i) read(x,y),add(x,y),add(y,x);Init();
	for(i=1;i<=m;++i) read(x,y,z),x^y&&(s[x].push_back((Data){dep[y]+1,z}),0);
	dfs();LL t=S.Q(Rt[1],1,1);printf("%lld\n",t==INF?-1:t),0;
}