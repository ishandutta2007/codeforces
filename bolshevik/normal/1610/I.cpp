#include<cstdio>
using namespace std;
const int o=8e5;
int n,h[o],cnt,fa[o],sg[o];bool vis[o];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void dfs(int nw){
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa[nw]) fa[e[i].v]=nw,dfs(e[i].v),sg[nw]^=sg[e[i].v]+1;
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i) scanf("%d%d",&u,&v),ad(u,v),ad(v,u);
	dfs(vis[1]=1);putchar(49+!sg[1]);
	for(int i=2;i<=n;++i,putchar(49+!sg[1]))
		for(int v=i;!vis[v];v=fa[v]) vis[v]=1,sg[1]^=sg[v]^(sg[v]+1)^1;
	return 0;
}