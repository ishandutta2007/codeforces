#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg //register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 200000
#define pb push_back
using namespace std;
int n,m;struct line {int x,y,p;}s[N+5];
namespace T
{
	int ee,lnk[N+5];struct edge {int to,nxt;}e[N+5];
	I void add(CI x,CI y) {e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y;}
	int f[N+5],d[N+5];I void Init(CI x)
	{
		for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^f[x]&&
			(d[e[i].to]=d[f[e[i].to]=x]+1,Init(e[i].to),0);
	}
	int id[N+5];I int Mark(CI i,RI x,RI y)
	{
		d[x]<d[y]&&(swap(x,y),0);W(d[x]^d[y]) if(id[x]) return id[x];else id[x]=i,x=f[x];
		W(x^y) if(id[x]||id[y]) return id[x]?id[x]:id[y];else id[x]=id[y]=i,x=f[x],y=f[y];return 0;
	}
	vector<int> g;int S[N+5];I void Walk(RI x,RI y)
	{
		RI T=0;if(d[x]>d[y]) W(d[x]^d[y]) g.pb(x),x=f[x];else W(d[x]^d[y]) S[++T]=y,y=f[y];
		W(x^y) g.pb(x),S[++T]=y,x=f[x],y=f[y];g.pb(x);W(T) g.pb(S[T--]);
	}
	I int LCA(RI x,RI y)
	{
		d[x]<d[y]&&(swap(x,y),0);W(d[x]^d[y]) x=f[x];W(x^y) x=f[x],y=f[y];return x;
	}
	int c[N+5];I void C(CI x) {RI t=x;W(t&&!c[t]) c[t]=x,t=f[t];}
	I int F(RI x,int& y) {W(!c[x]) x=f[x];return y=c[x],x;}
	I void Solve(CI i,CI j)
	{
		#define P() printf("%d ",g.size());\
			for(RI i=0,w=g.size();i^w;++i) printf("%d%c",g[i]," \n"[i==w-1])
		d[s[j].x]<d[s[j].y]&&(swap(s[j].x,s[j].y),0);
		RI a=LCA(s[i].x,s[j].x),b=LCA(s[i].y,s[j].x);
		d[a]<d[b]&&(swap(a,b),swap(s[i].x,s[i].y),0),b=LCA(s[i].y,s[j].y);
		RI u=LCA(s[i].x,s[i].y),v=LCA(s[j].x,s[j].y);d[u]<d[v]&&(u=v),
		d[a]<d[u]&&(a=u),d[b]<d[u]&&(b=u),puts("YES"),Walk(a,b),P();
		g.clear(),Walk(a,s[i].x),Walk(s[i].y,b),P();
		g.clear(),Walk(a,s[j].x),Walk(s[j].y,b),P();
	}
}
namespace G
{
	int ee,lnk[N+5];struct edge {int to,nxt;}e[2*N+5];
	I void add(CI x,CI y) {e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y;}
	int vis[N+5];I void dfs(CI x)
	{
		vis[x]=1;for(RI i=lnk[x];i;i=e[i].nxt)
			!vis[e[i].to]&&(s[i+1>>1].p=1,T::add(x,e[i].to),dfs(e[i].to),0);
	}
}
int main()
{
	RI i,x;for(scanf("%d%d",&n,&m),i=1;i<=m;++i)
		scanf("%d%d",&s[i].x,&s[i].y),G::add(s[i].x,s[i].y),G::add(s[i].y,s[i].x);
	for(i=1;i<=n;++i) !G::vis[i]&&(G::dfs(i),T::Init(i),0);
	for(i=1;i<=m;++i) if(!s[i].p&&(x=T::Mark(i,s[i].x,s[i].y))) return T::Solve(i,x),0;
	return puts("NO"),0;
}