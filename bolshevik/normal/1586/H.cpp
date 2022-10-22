#include<cstdio>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
const int o=4e5+10;
int n,q,ev[o],h[o],cnt,tot,d[o],anc[o][20],tol[o][20],fa[o],z[o],ls[o],rs[o],w[o],ans_[o],ans[o],val[o],X[o];
int Anc[o][20];pair<int,pair<int,int> > ed[o];vector<int> ask[o];
struct Edge{int v,p,w;}e[o];
inline void ad(int U,int V,int W){e[++cnt].v=V;e[cnt].p=h[U];e[h[U]=cnt].w=W;}
int fr(int x){return fa[x]==x?x:fa[x]=fr(fa[x]);}
void Dfs(int nw){
	d[nw]=d[anc[nw][0]]+1;
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^anc[nw][0]) tol[e[i].v][0]=e[i].w,anc[e[i].v][0]=nw,Dfs(e[i].v);
}
inline int dis(int x,int y){
	int res=0;
	if(d[x]<d[y]) swap(x,y);
	for(int i=20;i--;) if(d[anc[x][i]]>=d[y]) res=max(res,tol[x][i]),x=anc[x][i];
	if(x==y) return res;
	for(int i=20;i--;) if(anc[x][i]^anc[y][i]) res=max(res,max(tol[x][i],tol[y][i])),x=anc[x][i],y=anc[y][i];
	return max(res,max(tol[x][0],tol[y][0]));
}
void dfs(int nw){
	if(nw<=n){z[nw]=nw;return;}
	dfs(ls[nw]);dfs(rs[nw]);
	ev[nw]=max(ev[ls[nw]],ev[rs[nw]]);
	if(ev[nw]^ev[ls[nw]]) z[nw]=z[rs[nw]],val[nw]=val[rs[nw]];
	else if(ev[nw]^ev[rs[nw]]) z[nw]=z[ls[nw]],val[nw]=val[ls[nw]];
	else val[nw]=max(max(val[ls[nw]],val[rs[nw]]),dis(z[nw]=z[ls[nw]],z[rs[nw]]));
	for(int i=ask[nw].size(),j;i--;) ans_[j=ask[nw][i]]=ev[nw],ans[j]=max(val[nw],dis(z[nw],X[j]));
}
int main(){
	scanf("%d%d",&n,&q);tot=n;
	for(int i=1;i<=n;++i) scanf("%d",&ev[i]),fa[i]=z[i]=i;
	for(int i=1,a,b,t;i<n;++i)
		scanf("%d%d%d%d",&a,&b,&ed[i].first,&t),ed[i].second.first=a,ed[i].second.second=b,ad(a,b,t),ad(b,a,t);
	sort(ed+1,ed+n);
	Dfs(1);
	for(int i=n,u,v;--i;w[z[fa[u]=v]=tot]=ed[i].first)
		Anc[z[u=fr(ed[i].second.first)]][0]=Anc[z[v=fr(ed[i].second.second)]][0]=++tot,ls[tot]=z[u],rs[tot]=z[v];
	for(int i=1;i<20;++i) for(int j=1;j<=tot;++j) Anc[j][i]=Anc[Anc[j][i-1]][i-1];
	for(int i=1,v,x;i<=q;++i){
		scanf("%d%d",&v,&X[i]);ans_[i]=ev[x=X[i]];
		for(int j=20;j--;) if(w[Anc[x][j]]>=v) x=Anc[x][j];
		ask[x].push_back(i);
	}
	for(int i=1;i<20;++i) for(int j=1;j<=n;++j)
		anc[j][i]=anc[anc[j][i-1]][i-1],tol[j][i]=max(tol[j][i-1],tol[anc[j][i-1]][i-1]);
	dfs(tot);
	for(int i=1;i<=q;++i) printf("%d %d\n",ans_[i],ans[i]);
	return 0;
}