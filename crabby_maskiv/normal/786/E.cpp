#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=6e4+5; 
int n,m;
vector<pii> g[N];
struct edge{
	int v,f,b,pre;
};
edge G[15000000];
int tl[N],Pe;
inline void addE(int u,int v,int f,int b){
	int p=++Pe;G[p].v=v;G[p].f=f;G[p].b=b;
	G[p].pre=tl[u];tl[u]=p;
}
inline void add(int u,int v,int f){
	int bu=Pe+1,bv=Pe+2;
	addE(u,v,f,bv);
	addE(v,u,0,bu);
}
int S,T;
int cur[N],d[N];
int dfs(int u,int fl){
	if(u==T) return fl;
	if(!fl) return 0;
	int ans=0;
	for(int &i=cur[u];i;i=G[i].pre){
		int v=G[i].v,f=G[i].f,b=G[i].b;
		if(!f||d[v]!=d[u]+1) continue;
		int ff=dfs(v,min(fl,f));
		ans+=ff;
		fl-=ff;
		G[i].f-=ff;
		G[b].f+=ff;
		if(!fl) return ans;
	}
	return ans;
}
inline bool bfs(){
	queue<int> q;
	memset(d,0,sizeof(d));
	d[S]=1;q.push(S);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=tl[u];i;i=G[i].pre){
			int v=G[i].v,f=G[i].f,b=G[i].b;
			if(!f||d[v]) continue;
			d[v]=d[u]+1;
			q.push(v);
		}
	}
	return d[T];
}
inline int dinic(){
	int ans=0;
	while(bfs()){
		memcpy(cur,tl,sizeof(cur));
		ans+=dfs(S,1e9);
	}
	return ans;
}
int fa[N],lft[N],rgt[N],sz[N],son[N],top[N],h[N],id[N],tot;
int eid[N];
void dfs1(int u){
	h[u]=h[fa[u]]+1;
	sz[u]=1;
	for(int i=0;i<(int)g[u].size();i++){
		int v=g[u][i].fr;
		if(v==fa[u]) continue;
		eid[v]=g[u][i].sc;
		fa[v]=u;
		dfs1(v);
		sz[u]+=sz[v];
		if(sz[son[u]]<sz[v]) son[u]=v;
	}
}
void dfs2(int u,int tp){
	lft[u]=++tot;id[tot]=u;
	top[u]=tp;
	if(son[u]) dfs2(son[u],tp);
	for(int i=0;i<(int)g[u].size();i++){
		int v=g[u][i].fr;
		if(v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
	rgt[u]=tot;
}
struct sgt{
	int l,r,ls,rs;
}s[3*N];
int P,rt;
inline int build(int l,int r){
	int p=++P;s[p].l=l;s[p].r=r;
	if(l==r){
		add(p,T,1);
		return p;
	}
	int mid=(l+r)>>1;
	s[p].ls=build(l,mid);
	s[p].rs=build(mid+1,r);
	add(p,s[p].ls,1e9);
	add(p,s[p].rs,1e9);
	return p;
}
void chg(int p,int l,int r,int x){
	if(s[p].l==l&&s[p].r==r){
		add(x,p,1);
		return;
	}
	int mid=(s[p].l+s[p].r)>>1;
	if(r<=mid) chg(s[p].ls,l,r,x);
	else if(l>mid) chg(s[p].rs,l,r,x);
	else{
		chg(s[p].ls,l,mid,x);
		chg(s[p].rs,mid+1,r,x);
	}
}
inline void opt(int u,int v,int x){
	while(top[u]!=top[v]){
		if(h[top[u]]<h[top[v]]) swap(u,v);
		chg(rt,lft[top[u]],lft[u],x);
		u=fa[top[u]];
	}
	if(u==v) return;
	if(h[u]>h[v]) swap(u,v);
	chg(rt,lft[u]+1,lft[v],x);
}
int main(){
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(make_pair(v,i));
		g[v].push_back(make_pair(u,i));
	}
	dfs1(1);
	dfs2(1,1);
	rt=build(1,n);
	S=P+m+1;
	for(i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		opt(u,v,P+i);
	}
	for(i=1;i<=m;i++)
		add(S,i+P,1);
	printf("%d\n",dinic());
//	for(i=T;i<=S;i++) cout<<d[i]<<" ";cout<<endl;
	int ans=0;
	for(i=P+1;i<=P+m;i++) if(!d[i]) ans++;
	printf("%d ",ans);
	for(i=P+1;i<=P+m;i++) if(!d[i]) printf("%d ",i-P);
	puts("");
	ans=0;
	for(i=1;i<=P;i++) if(d[i]&&s[i].l==s[i].r) ans++;
	printf("%d ",ans);
	for(i=1;i<=P;i++) if(d[i]&&s[i].l==s[i].r) printf("%d ",eid[id[s[i].l]]);
	return 0;
}