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
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,a[N+5],f[N+5],ee,lnk[N+5];struct edge {int to,nxt;}e[N+5];map<string,int> P;set<int> c[N+5];
int D[N+5],g[N+5],sz[N+5];I void Init(CI x)
{
	sz[x]=1;for(RI i=lnk[x];i;i=e[i].nxt) D[e[i].to]=D[x]+1,Init(e[i].to),sz[x]+=sz[e[i].to],sz[e[i].to]>sz[g[x]]&&(g[x]=e[i].to);
}
I void Tg(CI x) {c[D[x]].insert(a[x]);for(RI i=lnk[x];i;i=e[i].nxt) Tg(e[i].to);}
I void Dl(CI x) {c[D[x]].erase(a[x]);for(RI i=lnk[x];i;i=e[i].nxt) Dl(e[i].to);}
int ans[N+5];vector<pair<int,int> > q[N+5];I void DSU(CI x)
{
	RI i;for(i=lnk[x];i;i=e[i].nxt) e[i].to^g[x]&&(DSU(e[i].to),Dl(e[i].to),0);
	if(lnk[x]) {for(DSU(g[x]),i=lnk[x];i;i=e[i].nxt) e[i].to^g[x]&&(Tg(e[i].to),0);}c[D[x]].insert(a[x]);
	for(RI i=0,z=q[x].size();i^z;++i) ans[q[x][i].first]=D[x]+q[x][i].second<=n?c[D[x]+q[x][i].second].size():0;
}
int main()
{
	RI Qt,i,t=0,rt;string s;for(scanf("%d",&n),i=1;i<=n;++i) cin>>s,!P.count(s)&&(P[s]=++t),a[i]=P[s],scanf("%d",f+i),f[i]&&(add(f[i],i),0);
	for(i=1;i<=n;++i) !f[i]&&(Init(i),0);RI x,y;for(scanf("%d",&Qt),i=1;i<=Qt;++i) scanf("%d%d",&x,&y),q[x].push_back(make_pair(i,y));
	for(i=1;i<=n;++i) !f[i]&&(DSU(i),Dl(i),0);for(i=1;i<=Qt;++i) printf("%d\n",ans[i]);return 0;
}