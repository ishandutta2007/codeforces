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
#define K 50
#define ID(i,j) (((i)-1)*k+(j))
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,m,k,ee,lnk[N*K+5];struct edge {int to,nxt;}e[N*K+5];int w[N+5];char u[N+5][K+1];
namespace T
{
	#define nadd(x,y) (ne[++nee].nxt=nlnk[x],ne[nlnk[x]=nee].to=y)
	int nee,nlnk[N*K+5];edge ne[N*K+5];
	int d,dfn[N*K+5],low[N*K+5],T,IS[N*K+5],S[N*K+5],ct,bl[N*K+5];I void dfs(CI x)
	{
		dfn[x]=low[x]=++d,IS[S[++T]=x]=1;for(RI i=lnk[x],y;i;i=e[i].nxt)
			dfn[y=e[i].to]?IS[y]&&(low[x]=min(low[x],dfn[y])):(dfs(y),low[x]=min(low[x],low[y]));
		if(dfn[x]==low[x]) {++ct;W(bl[S[T]]=ct,IS[S[T]]=0,S[T--]^x);}
	}
	int s[N*K+5],vis[N*K+5];I void ReBuild()
	{
		RI i,j;for(i=1;i<=n*k;++i) !dfn[i]&&(dfs(i),0);
		for(i=1;i<=n*k;++i) for(j=lnk[i];j;j=e[j].nxt) bl[i]^bl[e[j].to]&&nadd(bl[i],bl[e[j].to]);
		for(i=1;i<=n;++i) for(j=1;j<=k;++j) u[i][j]&1&&vis[bl[ID(i,j)]]^i&&(++s[bl[ID(i,j)]],vis[bl[ID(i,j)]]=i);
	}
	int f[N*K+5],q[N*K+5],D[N*K+5];I void Topo()
	{
		RI i,j;for(i=1;i<=ct;++i) for(j=nlnk[i];j;j=ne[j].nxt) ++D[ne[j].to];
		RI H=1,T=0;for(i=1;i<=ct;++i) !D[i]&&(q[++T]=i);
		W(H<=T) for(i=nlnk[q[H++]];i;i=ne[i].nxt) !--D[ne[i].to]&&(q[++T]=ne[i].to);
		RI k;for(j=ct;j;--j) {for(i=nlnk[k=q[j]];i;i=ne[i].nxt) f[k]=max(f[k],f[ne[i].to]);f[k]+=s[k];}
		printf("%d\n",f[bl[1]]);
	}
}
int main()
{
	RI i,j,x,y;for(scanf("%d%d%d",&n,&m,&k),i=1;i<=m;++i) for(scanf("%d%d",&x,&y),j=1;j<=k;++j) add(ID(x,j),ID(y,j%k+1));
	for(i=1;i<=n;++i) for(scanf("%s",u[i]+1),j=1;j<=k;++j) u[i][j]&1&&(w[i]=1);return T::ReBuild(),T::Topo(),0;
}