#include<cstdio>
const int S=2e6+6;
int dep[S],fir[S],l[S],to[S],ec,top[S],*f[S],dp[S],*ptr=dp,n,son[S],ans[S];
void link(int a,int b){l[++ec]=fir[a];fir[a]=ec;to[ec]=b;}
void dfs(int p,int fa){
	for(int i=fir[p];i;i=l[i])if(to[i]!=fa)dfs(to[i],p),son[p]=dep[to[i]]>dep[son[p]]?to[i]:son[p];
	dep[p]=dep[son[p]]+1;
}
void DFS(int p,int fa){
	f[p][0]=1;
	if(son[p])f[son[p]]=f[p]+1,DFS(son[p],p),ans[p]=ans[son[p]]+1;
	for(int i=fir[p],y;y=to[i];i=l[i])if(y!=fa&&y!=son[p]){
		f[y]=ptr,ptr+=dep[y],DFS(y,p);
		for(int j=dep[y];j;--j)f[p][j]+=f[y][j-1],ans[p]=f[p][j]>=f[p][ans[p]]?j:ans[p];
	}if(f[p][ans[p]]==1)ans[p]=0;
}
int main(){
	scanf("%d",&n);
	for(int i=1,a,b;i<n;++i)scanf("%d%d",&a,&b),link(a,b),link(b,a);
	dfs(1,0); f[1]=ptr;ptr+=dep[1]; DFS(1,0);
	for(int i=1;i<=n;++i)printf("%d\n",ans[i]);
}