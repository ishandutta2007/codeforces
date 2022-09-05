#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#define lc(k) (k<<1)
#define rc(k) (k<<1|1)
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> vec;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 202000;
ll tot;
int n,q,a[N],fa[N][17],dep[N],dy[N],rt,dfn[N],R[N],num;
int head[N],to[N],nxt[N],edgenum;
inline void add(int u, int v) {
	to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum;
}
inline void dfs(int u, int Fa, int Dep) {
	fa[u][0]=Fa; dep[u]=Dep; dfn[u]=++num;
	L(i,u) if (to[i]!=Fa) dfs(to[i],u,Dep+1);
	R[u]=num;
}
inline void init() {
	rep(i,1,16) dy[1<<i]=i;
	rep(j,1,16) rep(i,1,n)
		if (dep[i]>=(1<<j)) fa[i][j]=fa[fa[i][j-1]][j-1];
}
inline int LCA(int u, int v) {
	if (dep[u]<dep[v]) swap(u,v); int del=dep[u]-dep[v];
	while (del) {int bit=del&-del; del-=bit; u=fa[u][dy[bit]];}
	if (u==v) return u;
	per(i,16,0) if (fa[u][i]!=fa[v][i]) {u=fa[u][i]; v=fa[v][i];}
	return fa[u][0];
}
inline int getlca(int u, int v) {
	int a=LCA(u,v),b=LCA(u,rt),c=LCA(v,rt);
	if (dep[a]>=dep[b]&&dep[a]>=dep[c]) return a;
	if (dep[b]>=dep[a]&&dep[b]>=dep[c]) return b;
	return c;
}
struct Tree {
	int l,r;
	ll sum,lzy;
} tree[N<<2];
inline void build(int k, int l, int r) {
	tree[k].l=l; tree[k].r=r;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(lc(k),l,mid); build(rc(k),mid+1,r);
}
inline void add(int k, int p, int v) {
	tree[k].sum+=v; if (tree[k].l==tree[k].r) return;
	if (p<=tree[lc(k)].r) add(lc(k),p,v); else add(rc(k),p,v);
}
inline void add(int k, int l, int r, int v) {
	if (r<tree[k].l||l>tree[k].r) return;
	tree[k].sum+=1LL*v*(min(r,tree[k].r)-max(l,tree[k].l)+1);
	if (l<=tree[k].l&&r>=tree[k].r) {tree[k].lzy+=v; return;}
	add(lc(k),l,r,v); add(rc(k),l,r,v);
}
inline ll query(int k, int l, int r, ll sum) {
	if (r<tree[k].l||l>tree[k].r) return 0;
	if (l<=tree[k].l&&r>=tree[k].r) return tree[k].sum+sum*(tree[k].r-tree[k].l+1);
	return query(lc(k),l,r,sum+tree[k].lzy)+query(rc(k),l,r,sum+tree[k].lzy);
}
inline ll query(int dot) {return !dot?0:query(1,dfn[dot],R[dot],0)+tot*(R[dot]-dfn[dot]+1);}
inline int getson(int u) {
	int x=dep[rt]-dep[u]-1; u=rt;
	while (x) {int bit=x&-x; x-=bit; u=fa[u][dy[bit]];}
	return u;
}
int main() { //freopen("1.in","r",stdin);
	read(n); read(q); rep(i,1,n) read(a[i]); rt=1;
	rep(i,1,n-1) {
		int a,b;read(a);read(b);add(a,b);add(b,a);
	}
	dfs(1,0,0); init(); build(1,1,n);
	rep(i,1,n) add(1,dfn[i],a[i]);
	while (q--) {
		int op; read(op);
		if (op==1) {
			int v; read(v); rt=v;
		}
		else if (op==2) {
			int u,v,x; read(u); read(v); read(x);
			int dot=getlca(u,v); //printf("lca = %d\n",dot);
			if (dfn[rt]>=dfn[dot]&&dfn[rt]<=R[dot]) {
				tot+=x; int u=0; if (dot!=rt) u=getson(dot);
			//	printf("u = %d\n",u);
				add(1,dfn[u],R[u],-x);
			}
			else add(1,dfn[dot],R[dot],x);
		}
		else {
			int dot; read(dot);
			if (dfn[rt]>=dfn[dot]&&dfn[rt]<=R[dot]) {
				int u=0; if (dot!=rt) u=getson(dot);
				printf("%lld\n",query(1)-query(u));
			}
			else printf("%lld\n",query(dot));
		}
	}
	return 0;
}