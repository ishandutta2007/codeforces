#include<cstdio>
using namespace std;
const int o=6e5+10;
int T,p,n,h[o],cnt,ans1[o],ans2[o],tot;
struct Edge{int v,p,id;}e[o];
inline void ad(int U,int V,int ID){e[++cnt].v=V;e[cnt].p=h[U];e[h[U]=cnt].id=ID;}
void dfs(int nw,int fa,int dep){
	if(dep&1) ans1[nw]=tot;else ans1[nw]=n+tot;
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa)
		ans2[e[i].id]=((dep&1)?++tot:(n+(++tot))),dfs(e[i].v,nw,dep+1);
}
inline void slv(){
	n=1<<p;
	for(int i=1;i<=n;++i) h[i]=0;
	for(int i=1,u,v;i<n;++i) scanf("%d%d",&u,&v),ad(u,v,i),ad(v,u,i);
	dfs(1,0,0);
	printf("1\n");
	for(int i=1;i<=n;++i) printf("%d ",ans1[i]);
	putchar('\n');
	for(int i=1;i<n;++i) printf("%d ",ans2[i]);
}
int main(){
	for(scanf("%d",&T);T--;slv(),cnt=tot=0,putchar('\n')) scanf("%d",&p);
	return 0;
}