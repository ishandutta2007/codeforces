#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 200000
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,Nt=1,ee,lnk[2*N+5];struct edge {int to,nxt;}e[2*N+5];char s[N+5];
namespace TCD
{
	int d,dfn[2*N+5],fac[2*N+5],f[2*N+5],g[2*N+5],Sz[2*N+5],tp[2*N+5];
	I void dfs1(CI x)
	{
		Sz[x]=1;for(RI i=lnk[x];i;i=e[i].nxt) f[e[i].to]=x,
			dfs1(e[i].to),Sz[x]+=Sz[e[i].to],Sz[e[i].to]>Sz[g[x]]&&(g[x]=e[i].to);
	}
	I void dfs2(CI x,CI t)
	{
		tp[fac[dfn[x]=++d]=x]=t,g[x]&&(dfs2(g[x],t),0);
		for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^g[x]&&(dfs2(e[i].to,e[i].to),0);
	}
	int w[2*N+5];I int U(RI x)
	{
		RI y;W(x)
		{
			if(w[tp[x]]) return dfn[y=w[tp[x]]]<dfn[x]?(w[tp[x]]=x,y):x;
			w[tp[x]]=x,x=f[tp[x]];
		}return 0;
	}
	I void Del(RI x,CI p)
	{
		W(x)
		{
			if(dfn[tp[x]]<=dfn[p]) return (void)(w[tp[x]]==x&&(w[tp[x]]=p));
			w[tp[x]]==x&&(w[tp[x]]=0),x=f[tp[x]];
		}
	}
}
namespace SAM
{
	int lst=1,q[2*N+5],s[2*N+5];struct node {int L,F,S[30];}O[2*N+5];
	I void Build() {for(RI i=2;i<=Nt;++i) add(O[i].F,i);}
	I void A(CI x)
	{
		RI p=lst,o=lst=++Nt;O[o].L=O[p].L+1;
		W(p&&!O[p].S[x]) O[p].S[x]=o,p=O[p].F;if(!p) return (void)(O[o].F=1);
		RI q=O[p].S[x];if(O[q].L==O[p].L+1) return (void)(O[o].F=q);
		RI k=++Nt;(O[k]=O[q]).L=O[p].L+1,O[o].F=O[q].F=k;
		W(p&&O[p].S[x]==q) O[p].S[x]=k,p=O[p].F;
	}
	int d[2*N+5],dis[2*N+5],pre[2*N+5];vector<int> nxt[2*N+5];I void Topo()
	{
		RI i,j,k,H=1,T=0;for(i=1;i<=Nt;++i) for(j=1;j<=26;++j) O[i].S[j]&&++d[O[i].S[j]];
		for(i=1;i<=Nt;++i) !d[i]&&(q[++T]=i);
		W(H<=T) for(k=q[H++],i=1;i<=26;++i) O[k].S[i]&&
		(
			dis[k]+1>dis[O[k].S[i]]&&(dis[O[k].S[i]]=dis[pre[O[k].S[i]]=k]+1),
			!--d[O[k].S[i]]&&(q[++T]=O[k].S[i])
		);
		for(i=2;i<=Nt;++i) nxt[pre[i]].push_back(i);
	}
	I void Walk(CI x=1)
	{
		s[x]=TCD::U(x);for(RI i=0,sz=nxt[x].size();i^sz;++i) Walk(nxt[x][i]);TCD::Del(x,s[x]);
	}
	int f[2*N+5],t[N+5];I void Calc()
	{
		RI i,ans=0;for(i=1;i<=Nt;++i) ++t[O[i].L];for(i=1;i<=n;++i) t[i]+=t[i-1];
		for(i=1;i<=Nt;++i) q[t[O[i].L]--]=i;for(i=2;i<=Nt;++i) ans=max(ans,f[q[i]]=f[s[q[i]]]+1);
		printf("%d\n",ans);
	}
}
int main()
{
	RI i;for(scanf("%d%s",&n,s+1),i=1;i<=n;++i) SAM::A(s[i]&31);SAM::Build();
	return TCD::dfs1(1),TCD::dfs2(1,1),SAM::Topo(),SAM::Walk(),SAM::Calc(),0;
}