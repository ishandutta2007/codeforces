#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 204000;
int n,q,fa[N][18],dep[N],dl[N],dr[N],num;Vi e[N];set<Pii>Set;
void dfs1(int u, int Fa, int Dep){
	fa[u][0]=Fa;dep[u]=Dep;dl[u]=++num;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=Fa)
		dfs1(e[u][i],u,Dep+1);
	dr[u]=num;
}
inline int kthfa(int u, int k){
	rep(i,0,17)if(k>>i&1)u=fa[u][i];return u;
}
inline int LCA(int u, int v){
	if(dep[u]<dep[v])swap(u,v);u=kthfa(u,dep[u]-dep[v]);
	if(u==v)return u;
	per(i,17,0)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
struct node{
	int l,r,mx,cnt,lzy;
}tree[N<<2];
inline void pushdown(int k){
	if(tree[k].lzy){
		int v=tree[k].lzy;tree[k].lzy=0;
		tree[k<<1].lzy+=v;tree[k<<1].mx+=v;
		tree[k<<1|1].lzy+=v;tree[k<<1|1].mx+=v;
	}
}
inline void upd(int k){
	tree[k].mx=max(tree[k<<1].mx,tree[k<<1|1].mx);
	tree[k].cnt=(tree[k<<1].mx==tree[k].mx?tree[k<<1].cnt:0)+(tree[k<<1|1].mx==tree[k].mx?tree[k<<1|1].cnt:0);
}
void build(int k, int l, int r){
	tree[k].l=l;tree[k].r=r;tree[k].mx=0;
	if(l==r){tree[k].cnt=1;return;}
	int mid=(l+r)>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	upd(k);
}
void modify(int k, int l, int r, int x){
	if(r<tree[k].l||l>tree[k].r)return;
	if(l<=tree[k].l&&r>=tree[k].r){
		tree[k].mx+=x;tree[k].lzy+=x;return;
	}
	pushdown(k);modify(k<<1,l,r,x);modify(k<<1|1,l,r,x);upd(k);
}
int query(int k, int l, int r, int x){
	if(r<tree[k].l||l>tree[k].r)return 0;
	if(l<=tree[k].l&&r>=tree[k].r)return tree[k].mx==x?tree[k].cnt:0;
	pushdown(k);return query(k<<1,l,r,x)+query(k<<1|1,l,r,x);
}

void mfy(int u, int v, int kd){
	if(dep[u]<dep[v])swap(u,v);int lca=LCA(u,v);
	if(u!=lca&&v!=lca){modify(1,dl[u],dr[u],kd);modify(1,dl[v],dr[v],kd);}
	else{
		modify(1,dl[u],dr[u],kd);int x=kthfa(u,dep[u]-dep[v]-1);
		if(1<=dl[x]-1)modify(1,1,dl[x]-1,kd);
		if(dr[x]+1<=n)modify(1,dr[x]+1,n,kd);
	}
}
int main() {
	read(n);read(q);
	rep(i,1,n-1){int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);}
	dfs1(1,0,0);
	rep(j,1,17)rep(i,1,n)fa[i][j]=fa[fa[i][j-1]][j-1];
	build(1,1,n);
	while(q--){
		int x,y;read(x);read(y);if(x>y)swap(x,y);
		if(Set.count(Pii(x,y)))Set.erase(Pii(x,y)),mfy(x,y,-1);
		else Set.insert(Pii(x,y)),mfy(x,y,1);
		printf("%d\n",query(1,1,n,SZ(Set)));
	}
	return 0;
}