#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 1000
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,s[2],c[N+5],ee,lnk[N+5];struct edge {int to,nxt;}e[N<<1];pair<int,int> g[N+5];
int rt,Sz[N+5],Mx[N+5];void GetRt(CI x,CI lst=0)
{
	Sz[x]=1,Mx[x]=0;for(RI i=lnk[x],y;i;i=e[i].nxt) (y=e[i].to)^lst&&(GetRt(y,x),Sz[x]+=Sz[y],Mx[x]=max(Mx[x],Sz[y]));
	(Mx[x]=max(Mx[x],n-Sz[x]))<Mx[rt]&&(rt=x);
}
int t,w[N+5],d[N+5];void dfs(CI x,CI lst,CI pre,CI o)
{
	d[x]=++t*o,w[pre]=d[x]-d[lst];
	for(RI i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&(dfs(e[i].to,x,i+1>>1,o),0);
}
int main()
{
	RI i,x,y;for(scanf("%d",&n),i=1;i^n;++i) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	RI ct=0;for(Mx[rt=0]=1e9,GetRt(1),GetRt(rt),i=lnk[rt];i;i=e[i].nxt) g[++ct]=make_pair(Sz[e[i].to],e[i].to);
	for(sort(g+1,g+ct+1),i=ct;i;--i) s[0]<=s[1]?s[0]+=g[i].first:(s[1]+=g[i].first,c[g[i].second]=1);
	RI S=s[0];for(i=lnk[rt];i;i=e[i].nxt) s[c[e[i].to]]-=Sz[e[i].to],t=s[c[e[i].to]],dfs(e[i].to,rt,i+1>>1,c[e[i].to]?S:1);
	for(i=1;i^n;++i) printf("%d %d %d\n",e[2*i-1].to,e[2*i].to,w[i]);return 0;
}