#include<bits/stdc++.h>
using namespace std;
const int $=2e5,$$=8e6;
vector<int>E[$],ord[$];
int n,m,S,T,pc,ans,dep[$],f[$],sz[$],son[$],dfn[$],rt,lc[$],rc[$],tim,top[$],idfn[$],Ord[$];
int fir[$],l[$$],to[$$],w[$$],ec=1,d[$],q[$],Ans[$];
void link(int a,int b,int v){l[++ec]=fir[a];fir[a]=ec;to[ec]=b;w[ec]=v;}
void con(int a,int b,int v){link(a,b,v);link(b,a,0);}
#define md (L+R>>1)
void build(int&p,int L=2,int R=n){
	p=++pc;if(L==R)return con(idfn[L],p,$$);
	build(lc[p],L,md);build(rc[p],md+1,R); con(lc[p],p,$$); con(rc[p],p,$$);
}
void ask(int p,int l,int r,int P,int L=2,int R=n){
	if(l<=L&&R<=r)return con(p,P,$$);
	if(l<=md)ask(lc[p],l,r,P,L,md); if(r>md)ask(rc[p],l,r,P,md+1,R);
}
void dfs(int p,int fa){
	dep[p]=dep[fa]+1; sz[p]=1; f[p]=fa;
	for(int i=0,y;y=i<E[p].size()?E[p][i]:0;++i)if(y!=fa)Ord[y]=ord[p][i],dfs(y,p),sz[p]+=sz[y],son[p]=sz[son[p]]>sz[y]?son[p]:y;
}
void DFS(int p,int tp){
	top[p]=tp; dfn[p]=++tim; idfn[tim]=Ord[p];
	if(son[p])DFS(son[p],tp);
	for(auto y:E[p])if(!dfn[y])DFS(y,y);
}
void Ask(int a,int b,int P){
	while(top[a]!=top[b]){if(dep[top[a]]<dep[top[b]])swap(a,b);ask(rt,dfn[top[a]],dfn[a],P);a=f[top[a]];}
	if(dep[a]>dep[b])swap(a,b); if(a^b)ask(rt,dfn[a]+1,dfn[b],P);
}
bool bfs(){
	for(int i=1;i<=pc;++i)d[i]=$; d[S]=0;q[1]=S;
	for(int h=1,t=1,p;p=q[h],h<=t;++h)for(int i=fir[p],y;y=to[i];i=l[i])if(d[y]>d[p]+1&&w[i])
		d[q[++t]=y]=d[p]+1;
	return d[T]<$;
}
int Dfs(int p,int f){
	if(p==T)return f;int r=f;
	for(int i=fir[p],y;r&&(y=to[i]);i=l[i])if(d[y]==d[p]+1&&w[i]){
		int x=Dfs(y,min(w[i],r));
		if(!x)d[y]=$;
		w[i]-=x;w[i^1]+=x;r-=x;
	}return f-r;
}
#define pb push_back
int main(){
	scanf("%d%d",&n,&m); S=n+m;T=pc=S+1;
	for(int i=1,a,b;i<n;++i)scanf("%d%d",&a,&b),E[a].pb(b),E[b].push_back(a),ord[a].pb(i+m),ord[b].pb(i+m);
	for(int i=1;i<=m;++i)con(i,T,1);
	for(int i=1;i<n;++i)con(S,m+i,1);
	dfs(1,1); DFS(1,1); build(rt,2,n);
	for(int i=1,a,b;i<=m;++i)scanf("%d%d",&a,&b),Ask(a,b,i);
	while(bfs())ans+=Dfs(S,m);
	printf("%d",ans); ans=0;
	for(int i=fir[T];i;i=l[i])if(!w[i^1]&&d[to[i]]!=$)Ans[++ans]=to[i];
	sort(Ans+1,Ans+1+ans); printf("\n%d ",ans);
	for(int i=1;i<=ans;++i)printf("%d ",Ans[i]); ans=0;
	for(int i=fir[S];i;i=l[i])if(!w[i]&&d[to[i]]==$)Ans[++ans]=to[i]-m;
	sort(Ans+1,Ans+1+ans); printf("\n%d ",ans);
	for(int i=1;i<=ans;++i)printf("%d ",Ans[i]);
}