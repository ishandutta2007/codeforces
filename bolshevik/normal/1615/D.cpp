#include<cstdio>
using namespace std;
const int o=1e6;
int T,n,m,h[o],cnt,U[o],V[o],W[o],z[o];bool flg;
struct Edge{int v,p,w;}e[o];
inline void ad(int U,int V,int W){e[++cnt].v=V;e[cnt].p=h[U];e[h[U]=cnt].w=W;}
void dfs(int nw){
	for(int i=h[nw];i;i=e[i].p)
		if(z[e[i].v]>1) z[e[i].v]=(z[nw]^e[i].w),dfs(e[i].v);
		else if(z[e[i].v]^z[nw]^e[i].w) flg=1;
}
int main(){
	for(scanf("%d",&T);T--;cnt=flg=0){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;z[i++]=2) h[i]=0;
		for(int i=1;i<n;++i){
			scanf("%d%d%d",&U[i],&V[i],&W[i]);
			if(W[i]+1) ad(U[i],V[i],__builtin_parity(W[i])),ad(V[i],U[i],__builtin_parity(W[i]));
		}
		for(int i=1,a,b,c;i<=m;++i) scanf("%d%d%d",&a,&b,&c),ad(a,b,c),ad(b,a,c);
		for(int i=1;i<=n;++i) if(z[i]>1) z[i]=0,dfs(i);
		if(flg){printf("NO\n");continue;}
		printf("YES\n");
		for(int i=1;i<n;++i)
			if(W[i]+1) printf("%d %d %d\n",U[i],V[i],W[i]);else printf("%d %d %d\n",U[i],V[i],z[U[i]]^z[V[i]]);
	}
	return 0;
}