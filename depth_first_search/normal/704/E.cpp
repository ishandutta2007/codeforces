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
#define DB double
#define pb push_back
#define eps 1e-9
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
#define Eq(A,B) (fabs((A)-(B))<eps)
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int n,m,ee,lnk[N+5];struct edge {int to,nxt;}e[N<<1];
DB nw;struct S
{
	DB k,b,ed;bool operator < (Cn S& o) Cn
	{
		return Eq(k*nw+b,o.k*nw+o.b)?(Eq(k,o.k)?(Eq(b,o.b)?ed<o.ed:b<o.b):k<o.k):k*nw+b<o.k*nw+o.b;
	}
};multiset<S> G;
int ct;struct OP {int op;DB x;S g;bool operator < (Cn OP& o) Cn {return Eq(x,o.x)?op>o.op:x<o.x;}};vector<OP> A[N+5],B[N+5];
namespace TCD
{
	int D[N+5],f[N+5],g[N+5],sz[N+5];void dfs1(CI x)
	{
		sz[x]=1;for(RI i=lnk[x],y;i;i=e[i].nxt) (y=e[i].to)^f[x]&&(D[y]=D[f[y]=x]+1,dfs1(y),sz[x]+=sz[y],sz[y]>sz[g[x]]&&(g[x]=y));
	}
	int d,dI[N+5],tp[N+5];void dfs2(CI x,CI t)
	{
		dI[x]=++d,tp[x]=t;if(!g[x]) return;dfs2(g[x],t);for(RI i=lnk[x],y;i;i=e[i].nxt) (y=e[i].to)^f[x]&&y^g[x]&&(dfs2(y,y),0);
	}
	I int Dis(RI x,RI y)
	{
		RI t=D[x]+D[y];W(tp[x]^tp[y]) D[tp[x]]>D[tp[y]]?x=f[tp[x]]:y=f[tp[y]];return t-2*min(D[x],D[y]);
	}
	I void G(RI x,RI y,DB bg,DB ed,CI v)
	{
		S g;RI t;W(tp[x]^tp[y]) if(D[tp[x]]>D[tp[y]])
		{
			t=tp[x],g=(S){-v,dI[x]+v*bg,bg+1.0*(dI[x]-dI[t])/v},A[t].pb((OP){1,bg,g}),A[t].pb((OP){-1,bg=g.ed,g});
			g.k=1.0*(dI[f[t]]-dI[t])*v,g.b=dI[t]-g.k*bg,g.ed=bg+1.0/v,B[t].pb((OP){1,bg,g}),B[t].pb((OP){-1,bg=g.ed,g}),x=f[t];
		} else {
			t=tp[y],g=(S){v,dI[y]-v*ed,ed},A[t].pb((OP){-1,ed,g}),A[t].pb((OP){1,ed-=1.0*(dI[y]-dI[t])/v,g});
			g.k=1.0*(dI[t]-dI[f[t]])*v,g.b=dI[t]-g.k*ed,g.ed=ed,B[t].pb((OP){-1,ed,g}),B[t].pb((OP){1,ed-=1.0/v,g}),y=f[t];
		}
		g.k=(dI[x]<dI[y]?1:-1)*v,g.b=dI[x]-g.k*bg,g.ed=ed,A[tp[x]].pb((OP){1,bg,g}),A[tp[x]].pb((OP){-1,ed,g});
	}
}
DB ans=1e18;I void Solve(vector<OP>& V)
{
	vector<OP>::iterator it;multiset<S>::iterator st;sort(V.begin(),V.end()),G.clear();
	DB x;S g;for(it=V.begin();it!=V.end()&&it->x<ans;++it)
	{
		if(!~(it->op)) {G.erase(G.find(it->g));continue;}
		nw=it->x,g=it->g;
		if((st=G.upper_bound(g))!=G.begin())
		{
			if(--st,g.k!=st->k) x=(st->b-g.b)/(g.k-st->k),it->x-x<eps&&x-min(g.ed,st->ed)<eps&&(ans=min(ans,x));
			else if(g.b==st->b) return (void)(ans=it->x);
		}
		if((st=G.lower_bound(g))!=G.end())
		{
			if(g.k!=st->k) x=(st->b-g.b)/(g.k-st->k),it->x-x<eps&&x-min(g.ed,st->ed)<eps&&(ans=min(ans,x));
			else if(g.b==st->b) return (void)(ans=it->x);
		}
		G.insert(g);
	}
}
int main()
{
	RI i,x,y,v,t;for(read(n,m),i=1;i^n;++i) read(x,y),add(x,y),add(y,x);TCD::dfs1(1),TCD::dfs2(1,1);
	W(m--) read(t,v,x,y),TCD::G(x,y,t,t+1.0*TCD::Dis(x,y)/v,v);
	for(i=1;i<=n;++i) !A[i].empty()&&(Solve(A[i]),0),!B[i].empty()&&(Solve(B[i]),0);
	return ans==1e18?puts("-1"):printf("%.8lf\n",ans),0;
}