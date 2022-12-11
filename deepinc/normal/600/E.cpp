#include<cstdio>
const int S=222222,T=10000005;
int n,fir[S],l[S],to[S],ec,a[S],rt[S],lc[T],rc[T],mx[T],sz[S],pc;long long w[T],ans[S];
void link(int a,int b){l[++ec]=fir[a];fir[a]=ec;to[ec]=b;}
#define md (L+R>>1)
void ins(int&p,int x,int L=1,int R=n){
	if(!p)p=++pc;
	if(L==R){w[p]=L;mx[p]++;return;}
	if(x<=md)ins(lc[p],x,L,md);else ins(rc[p],x,md+1,R);
	if(mx[lc[p]]>mx[rc[p]])mx[p]=mx[lc[p]],w[p]=w[lc[p]];
	else if(mx[rc[p]]>mx[lc[p]])mx[p]=mx[rc[p]],w[p]=w[rc[p]];
	else mx[p]=mx[lc[p]],w[p]=w[lc[p]]+w[rc[p]];
}
void DFS(int&r,int p,int fa){
	for(int i=fir[p];i;i=l[i])if(to[i]!=fa)DFS(r,to[i],p);
	ins(r,a[p]);
}
void dfs(int p,int fa){
	sz[p]=1; int son=0;
	for(int i=fir[p];i;i=l[i])if(to[i]!=fa){
		dfs(to[i],p);sz[p]+=sz[to[i]];
		if(sz[to[i]]>sz[son])son=to[i];
	}
	ins(rt[p]=rt[son],a[p]);
	for(int i=fir[p];i;i=l[i])if(to[i]!=fa&&to[i]!=son)DFS(rt[p],to[i],p);
	ans[p]=w[rt[p]];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1,a,b;i<n;++i)scanf("%d%d",&a,&b),link(a,b),link(b,a);
	dfs(1,0);
	for(int i=1;i<=n;++i)printf("%lld ",ans[i]);
}