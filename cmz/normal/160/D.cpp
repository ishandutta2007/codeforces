#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10,maxm=1e6+10;
int n,m,f[maxn][18],h[maxn][18],root[maxn],ls[maxn*100],rs[maxn*100],val[maxn*100],dep[maxn],fa[maxn],tot;
struct My{
	int a,b,c,tag,id;
}q[maxn];
vector<int> son[maxn],g[maxn];
inline bool comp1(const My &x,const My &y){return x.c<y.c;}
inline bool comp2(const My &x,const My &y){return x.id<y.id;}
int ask(int x){return x==fa[x]?x:fa[x]=ask(fa[x]);}
inline void merge(int x,int y){x=ask(x); y=ask(y); fa[x]=y;}
inline int lca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=17;i>=0;--i) if (dep[f[x][i]]>=dep[y]) x=f[x][i];
	if (x==y) return x;
	for (int i=17;i>=0;--i) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
void dfs(int x,int fa){
	f[x][0]=fa; dep[x]=dep[fa]+1; for (int i=1;i<=17;++i) f[x][i]=f[f[x][i-1]][i-1],h[x][i]=max(h[x][i-1],h[f[x][i-1]][i-1]);
	for (int i=0;i<(int)son[x].size();++i){
		int v=son[x][i],id=g[x][i],w=q[id].c;
		if (v==fa) continue;
		h[v][0]=w; dfs(v,x);
	}
}
inline int Gao(int x,int y,int LCA){
	int Ans=0;
	for (int i=17;i>=0;--i) if (dep[f[x][i]]>=dep[LCA]) Ans=max(Ans,h[x][i]),x=f[x][i];
	for (int i=17;i>=0;--i) if (dep[f[y][i]]>=dep[LCA]) Ans=max(Ans,h[y][i]),y=f[y][i];
	return Ans;
}
inline void pushup(int now){
	val[now]=val[ls[now]]+val[rs[now]];
}
void update(int &now,int l,int r,int pos,int k){
	if (!now) now=++tot;
	if (l==r){
		val[now]+=k;
		return;
	}
	int mid=(l+r)/2;
	if (pos<=mid) update(ls[now],l,mid,pos,k); else update(rs[now],mid+1,r,pos,k);
	pushup(now);
}
int merge(int x,int y,int l,int r){
	if (!x||!y) return x|y;
	if (l==r){
		val[x]+=val[y];
		return x;
	}
	int mid=(l+r)/2;
	ls[x]=merge(ls[x],ls[y],l,mid);
	rs[x]=merge(rs[x],rs[y],mid+1,r);
	return pushup(x),x;
}
int query(int now,int l,int r,int pos){
	if (l==r) return val[now];
	int mid=(l+r)/2;
	if (pos<=mid) return query(ls[now],l,mid,pos); else return query(rs[now],mid+1,r,pos);
}
void get_ans(int x,int fa){
	for (int i=0,now,w,id,v;i<(int)son[x].size();++i){
		v=son[x][i],id=g[x][i],w=q[id].c;
		if (v==fa) continue;
		get_ans(v,x); 
		now=query(root[v],1,maxm-10,w);
		if (now>0) q[id].tag=2;
		root[x]=merge(root[x],root[v],1,maxm-10);
	}
}
int main(){
	//freopen(".in","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i) scanf("%d%d%d",&q[i].a,&q[i].b,&q[i].c),q[i].id=i;
	for (int i=1;i<=n;++i) fa[i]=i;
	sort(q+1,q+1+m,comp1);
	for (int i=1,x,y;i<=m;++i) 
	if (ask(q[i].a)!=ask(q[i].b)){
		x=q[i].a; y=q[i].b;
		merge(x,y); q[i].tag=1;
		son[x].push_back(y); g[x].push_back(i);
		son[y].push_back(x); g[y].push_back(i);
	}
	dfs(1,0);
	//for (int i=1;i<=m;++i) printf("tag[%d]=%d\n",i,q[i].tag);
	for (int i=1,x,y,LCA,w;i<=m;++i) 
	if (!q[i].tag){
		x=q[i].a,y=q[i].b,w=q[i].c,LCA=lca(x,y);
		if (Gao(x,y,LCA)==w) q[i].tag=2;
		update(root[LCA],1,maxm-10,w,-2);
		update(root[x],1,maxm-10,w,1);
		update(root[y],1,maxm-10,w,1);
	}
	get_ans(1,0);
	//for (int i=1;i<=m;++i) printf("tag[%d]=%d\n",i,q[i].tag);
	sort(q+1,q+1+m,comp2);
	for (int i=1;i<=m;++i) if (q[i].tag==0) puts("none"); else if (q[i].tag==1) puts("any"); else puts("at least one");
	return 0;
}