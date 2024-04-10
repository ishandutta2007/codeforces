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
#define LL long long
#define add(x,y,z) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y,e[ee].v=z)
using namespace std;
int n,a[N+5],ee,lnk[N+5];struct edge {int to,nxt,v;}e[N<<1];
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
int Rt[N+5];LL v[N+5];class ChairmanTree
{
	private:
		#define SZ 30000000
		#define PT CI l=1,CI r=n
		#define LT l,mid
		#define RT mid+1,r
		#define PU() (O[rt].V=O[O[rt].S[0]].V+O[O[rt].S[1]].V+(v[r]-v[l-1])*O[rt].F)
		struct node {LL V;int F,S[2];}O[SZ+5];
	public:
		int Nt,lst;I void U(int& rt,CI L,CI R,PT)
		{
			if(rt<=lst&&(O[++Nt]=O[rt],rt=Nt),L<=l&&r<=R) return (void)(O[rt].V+=v[r]-v[l-1],++O[rt].F);RI mid=l+r>>1;
			L<=mid&&(U(O[rt].S[0],L,R,LT),0),R>mid&&(U(O[rt].S[1],L,R,RT),0),PU();
		}
		I LL Q(CI rt,CI L,CI R,RI f=0,PT)
		{
			if(L<=l&&r<=R) return O[rt].V+(v[r]-v[l-1])*f;RI mid=l+r>>1;
			return (L<=mid?Q(O[rt].S[0],L,R,f+O[rt].F,LT):0)+(R>mid?Q(O[rt].S[1],L,R,f+O[rt].F,RT):0);
		}
}C;
namespace TCD
{
	int d,dI[N+5],dO[N+5],f[N+5],g[N+5],sz[N+5],tp[N+5];LL D[N+5];
	I void dfs1(CI x) {sz[x]=1;for(RI i=lnk[x],y;i;i=e[i].nxt) !sz[y=e[i].to]&&(f[y]=x,D[y]=D[x]+e[i].v,dfs1(y),sz[x]+=sz[y],sz[y]>sz[g[x]]&&(g[x]=y));}
	I void dfs2(CI x,CI t) {v[dI[x]=++d]=D[x]-D[f[x]],tp[x]=t;if(g[x]) {dfs2(g[x],t);for(RI i=lnk[x],y;i;i=e[i].nxt) !dI[y=e[i].to]&&(dfs2(y,y),0);}dO[x]=d;}
	I void U(int& rt,RI x) {C.lst=C.Nt;W(x) C.U(rt,dI[tp[x]],dI[x]),x=f[tp[x]];}
	I LL Q(CI rt,RI x) {LL t=0;W(x) t+=C.Q(rt,dI[tp[x]],dI[x]),x=f[tp[x]];return t;}
}
struct TreeArray {LL a[N+5];I void U(RI x,LL v) {W(x<=n) a[x]+=v,x+=x&-x;}I LL Q(RI x) {LL t=0;W(x) t+=a[x],x-=x&-x;return t;}}T;
I void Get(CI x) {Rt[x]=Rt[x-1],TCD::U(Rt[x],a[x]);}
I LL Q(CI l,CI r,CI x) {return 1LL*TCD::D[x]*(r-l+1)+(T.Q(r)-T.Q(l-1))-2*(TCD::Q(Rt[r],x)-TCD::Q(Rt[l-1],x));}
I void U(CI x)
{
	swap(a[x],a[x+1]),T.U(x,TCD::D[a[x]]-TCD::D[a[x+1]]),T.U(x+1,TCD::D[a[x+1]]-TCD::D[a[x]]);
	if(C.Nt>SZ-100000) {C.Nt=0;for(RI i=1;i<=n;++i) Get(i);return;}Get(x);
}
int main()
{
	RI Qt,i,x,y,z;for(read(n,Qt),i=1;i<=n;++i) read(a[i]);for(i=1;i^n;++i) read(x,y,z),add(x,y,z),add(y,x,z);
	for(TCD::dfs1(1),TCD::dfs2(1,1),i=1;i<=n;++i) v[i]+=v[i-1];for(i=1;i<=n;++i) Get(i),T.U(i,TCD::D[a[i]]);
	RI op;LL t=0;W(Qt--) t&=(1<<30)-1,read(op,x),op==1?(read(y,z),writeln(t=Q(x^t,y^t,z^t))):U(x^t);return clear(),0;
}