#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;
const int o=1e6+10;
int T,n,h[o],cnt,dfn[o],low[o],st[o],tp,sccn,scc[o],d[o];bool vis[o];pair<int,int> a[o],b[o];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void tarjan(int nw){
	dfn[nw]=low[nw]=++cnt;vis[st[++tp]=nw]=1;
	for(int i=h[nw];i;i=e[i].p)
		if(!dfn[e[i].v]) tarjan(e[i].v),low[nw]=min(low[nw],low[e[i].v]);
		else if(vis[e[i].v]) low[nw]=min(low[nw],dfn[e[i].v]);
	if(dfn[nw]==low[nw]) for(d[++sccn]=st[tp+1]=0;st[tp+1]^nw;vis[st[tp--]]=0) scc[st[tp]]=sccn;
}
int main(){
	for(scanf("%d",&T);T--;cnt=sccn=0,putchar('\n')){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i].first),a[i].second=i;
		for(int i=1;i<=n;++i) scanf("%d",&b[i].first),b[i].second=i;
		sort(a+1,a+n+1);sort(b+1,b+n+1);
		for(int i=1;i<=3*n;++i) dfn[i]=h[i]=0;
		for(int i=1;i<=n;++i) ad(i,i+n),ad(i+n,i),ad(i,i+2*n),ad(i+2*n,i);
		for(int i=1;i<n;++i) ad(a[i+1].second+n,a[i].second+n);
		for(int i=1;i<n;++i) ad(b[i+1].second+2*n,b[i].second+2*n);
		cnt=0;
		for(int i=1;i<=3*n;++i) if(!dfn[i]) tarjan(i);
		for(int i=1;i<=3*n;++i) for(int j=h[i];j;j=e[j].p) if(scc[i]^scc[e[j].v]) ++d[scc[e[j].v]];
		for(int i=1;i<=n;++i) printf("%d",!d[scc[i]]);
	}
	return 0;
}