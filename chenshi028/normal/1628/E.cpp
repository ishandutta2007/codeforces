#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
const int o=6e5+10;
int n,q,fa[o],z[o],anc[o][20],d[o],dfn[o],nfd[o],mn[o*2],mx[o*2],dmn[o*2],dmx[o*2],flg[o*2],tot,cnt,ls[o],rs[o],w[o];pair<int,pair<int,int> > e[o];
int fr(int x){return fa[x]==x?x:fa[x]=fr(fa[x]);}
void dfs(int nw){
	nfd[dfn[nw]=++cnt]=nw;d[nw]=d[anc[nw][0]]+1;
	if(ls[nw]) anc[ls[nw]][0]=nw,dfs(ls[nw]);
	if(rs[nw]) anc[rs[nw]][0]=nw,dfs(rs[nw]);
}
void build(int id,int l,int r){
	mn[id]=o;mx[id]=0;flg[id]=2;
	if(l==r){dmn[id]=dmx[id]=dfn[l];return;}
	int md=l+r>>1;
	build(id<<1,l,md);build((id<<1)|1,md+1,r);
	dmn[id]=min(dmn[id<<1],dmn[(id<<1)|1]);dmx[id]=max(dmx[id<<1],dmx[(id<<1)|1]);
}
inline void pnt(int id,int val){
	flg[id]=val;
	if(val) mn[id]=dmn[id],mx[id]=dmx[id];
	else mn[id]=o,mx[id]=0; 
}
inline void pushdown(int id){
	if(!flg[id]) pnt(id<<1,0),pnt((id<<1)|1,0);
	if(flg[id]==1) pnt(id<<1,1),pnt((id<<1)|1,1);
	flg[id]=2;
}
void modify(int id,int ql,int qr,int val,int l=1,int r=n){
	if(ql<=l&&r<=qr){pnt(id,val);return;}
	pushdown(id);
	int md=l+r>>1;
	if(ql<=md) modify(id<<1,ql,qr,val,l,md);
	if(md<qr) modify((id<<1)|1,ql,qr,val,md+1,r);
	mn[id]=min(mn[id<<1],mn[(id<<1)|1]);mx[id]=max(mx[id<<1],mx[(id<<1)|1]);
}
inline int lca(int x,int y){
	for(int i=19;i+1;--i) if(d[anc[x][i]]>=d[y]) x=anc[x][i];
	for(int i=19;i+1;--i) if(d[anc[y][i]]>=d[x]) y=anc[y][i];
	if(x==y) return x;
	for(int i=19;i+1;--i) if(anc[x][i]^anc[y][i]) x=anc[x][i],y=anc[y][i];
	return anc[x][0];
}
int main(){
	scanf("%d%d",&n,&q);tot=n;
	for(int i=1;i<n;++i) scanf("%d%d%d",&e[i].second.first,&e[i].second.second,&e[i].first);
	sort(e+1,e+n);
	for(int i=1;i<=n;w[i++]=-1) z[fa[i]=i]=i;
	for(int i=1,u,v;i<n;++i) u=fr(e[i].second.first),v=fr(e[i].second.second),w[++tot]=e[i].first,ls[tot]=z[v],rs[z[fa[u]=v]=tot]=z[u];
	dfs(tot);
	for(int i=1;i<20;++i) for(int j=1;j<=tot;++j) anc[j][i]=anc[anc[j][i-1]][i-1];
	build(1,1,n);
	for(int t,x,y;q--;){
		scanf("%d%d",&t,&x);
		if(t<3) scanf("%d",&y),modify(1,x,y,t&1);
		else t=mn[1],y=mx[1],printf("%d\n",y?max(w[lca(nfd[t],x)],w[lca(nfd[y],x)]):-1);
	}
	return 0;
}