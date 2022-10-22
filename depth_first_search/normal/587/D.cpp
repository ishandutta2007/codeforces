#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 50000
#define Gmin(x,y) (x>(y)&&(x=(y)))
#define mp make_pair
using namespace std;
int n,m;struct line {int x,y,c,v;}s[N+5];
namespace G
{
	#define SZ 10*N
	#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
	int cnt,oe,ee,lnk[SZ+5],h[SZ+5];struct edge {int to,nxt;}e[25*N+5];
	typedef pair<int,int> Pr;int w,g[4*N+5];map<Pr,int> id;
	I int ID(CI x,CI y) {return id.count(mp(x,y))?id[mp(x,y)]:(id[mp(x,y)]=++w);}
	int d,dfn[SZ+5],low[SZ+5],tot,bl[SZ+5],T,S[SZ+5],IS[SZ+5];I void Tarjan(CI x)
	{
		dfn[x]=low[x]=++d,IS[S[++T]=x]=1;for(RI i=lnk[x];i;i=e[i].nxt) dfn[e[i].to]?
			IS[e[i].to]&&Gmin(low[x],dfn[e[i].to]):(Tarjan(e[i].to),Gmin(low[x],low[e[i].to]));
		if(dfn[x]==low[x]) {++tot;W(bl[S[T]]=tot,IS[S[T]]=0,S[T--]^x);}
	}
	I void Link(CI p,CI x,CI y)
	{
		cnt+=2,g[p]&&(add(x,g[p]),add(g[p]-1,y),add(g[p]-1,cnt-1),add(cnt,g[p])),
		add(x,cnt-1),add(cnt,y),g[p]=cnt;
	}
	I void Init()
	{
		w=0,cnt=m<<1;for(RI i=1,x;i<=m;++i)
			Link(ID(s[i].x,0),m+i,i),Link(ID(s[i].x,s[i].c),i,m+i),
			Link(ID(s[i].y,0),m+i,i),Link(ID(s[i].y,s[i].c),i,m+i);
		oe=ee;for(RI i=1;i<=cnt;++i) h[i]=lnk[i];
	}
	I bool Check(CI v)
	{
		RI i;for(ee=oe,d=tot=0,i=1;i<=cnt;++i) dfn[i]=0,lnk[i]=h[i];
		for(i=1;i<=m;++i) s[i].v>v&&add(m+i,i);for(i=1;i<=cnt;++i) !dfn[i]&&(Tarjan(i),0);
		for(i=1;i<=m;++i) if(G::bl[i]==G::bl[m+i]) return 0;return 1;
	}
}
int main()
{
	RI i;for(scanf("%d%d",&n,&m),i=1;i<=m;++i) scanf("%d%d%d%d",&s[i].x,&s[i].y,&s[i].c,&s[i].v);
	G::Init();RI l=0,r=1e9+1,t;W(l^r) G::Check(t=l+r>>1)?r=t:l=t+1;if(r>1e9) return puts("No"),0;
	for(G::Check(r),puts("Yes"),t=0,i=1;i<=m;++i) G::bl[i]>G::bl[m+i]&&++t;
	for(printf("%d %d\n",r,t),i=1;i<=m;++i) G::bl[i]>G::bl[m+i]&&printf("%d ",i);return 0;
}