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
#define INF (int)1e9
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int n,d,fc[N+5],dI[N+5],dO[N+5],D[N+5],f[N+5],ee,lnk[N+5];struct edge {int to,nxt;}e[N+5];
void dfs(CI x) {fc[dI[x]=++d]=x;for(RI i=lnk[x],y;i;i=e[i].nxt) (y=e[i].to)^f[x]&&(D[y]=D[x]+1,dfs(y),0);dO[x]=d;}
class SegmentTree
{
	private:
		#define PT RI l=1,RI r=n,RI o=1
		#define LT l,u,o<<1
		#define RT u+1,r,o<<1|1
		#define TF(o,v) (F[o]+=v,G[o]^INF&&(G[o]+=v))
		#define TG(o,v) (G[o]=G[o]^INF?max(G[o],v):v)
		#define TP(o,v) (F[o]=0,G[o]=INF,P[o]=v)
		#define PD(o) (P[o]^INF&&(TP(o<<1,P[o]),TP(o<<1|1,P[o]),P[o]=INF),\
			F[o]&&(TF(o<<1,F[o]),TF(o<<1|1,F[o]),F[o]=0),G[o]^INF&&(TG(o<<1,G[o]),TG(o<<1|1,G[o]),G[o]=INF))
		int F[N<<2],G[N<<2],P[N<<2];
	public:
		void UF(CI L,CI R,PT) {if(L<=l&&r<=R) return (void)TF(o,-1);RI u=l+r>>1;PD(o),L<=u&&(UF(L,R,LT),0),R>u&&(UF(L,R,RT),0);}
		void UG(CI L,CI R,CI v,PT) {if(L<=l&&r<=R) return (void)TG(o,v);RI u=l+r>>1;PD(o),L<=u&&(UG(L,R,v,LT),0),R>u&&(UG(L,R,v,RT),0);}
		void UP(CI L,CI R,CI v,PT) {if(L<=l&&r<=R) return (void)TP(o,v);RI u=l+r>>1;PD(o),L<=u&&(UP(L,R,v,LT),0),R>u&&(UP(L,R,v,RT),0);}
		int Q(CI x,PT) {if(P[o]^INF) return max(D[fc[x]]+P[o]+F[o],G[o]^INF?G[o]:0);RI u=l+r>>1;PD(o);return x<=u?Q(x,LT):Q(x,RT);}
}S;
int main()
{
	RI Qt,i,x,y;for(read(n,Qt),i=2;i<=n;++i) read(f[i]),add(f[i],i);D[1]=1,dfs(1);
	RI g;W(Qt--) switch(read(y,x),g=x^1?S.Q(dI[f[x]]):0,y)
	{
		case 1:S.UF(dI[x],dO[x]),S.UG(dI[x],dO[x],g);break;
		case 2:S.UP(dI[x],dO[x],g-D[f[x]]);break;case 3:puts(S.Q(dI[x])^g?"white":"black");break;
	}return 0;
}