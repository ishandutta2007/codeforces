#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 120000;
int n,m,a[N];
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
struct Tree {
	int l,r,max;
	ll sum;
} tree[N<<2];
inline void update(int k) {
	tree[k].sum=tree[lc(k)].sum+tree[rc(k)].sum;
	tree[k].max=max(tree[lc(k)].max,tree[rc(k)].max);
}
inline void build(int k, int l, int r) {
	tree[k].l=l; tree[k].r=r;
	if (l==r) {tree[k].sum=tree[k].max=a[l]; return;} int mid=(l+r)>>1;
	build(lc(k),l,mid); build(rc(k),mid+1,r); update(k);
}
inline ll query(int k, int l, int r) {
	if (r<tree[k].l||l>tree[k].r) return 0;
	if (l<=tree[k].l&&r>=tree[k].r) return tree[k].sum;
	return query(lc(k),l,r)+query(rc(k),l,r);
}
inline void Modify(int k, int mo) {
	tree[k].max%=mo; tree[k].sum=tree[k].max;
//	printf("modify %d %d\n",tree[k].l,mo);
	while (k>1) {k>>=1; update(k);}
}
inline void modify(int k, int l, int r, int mo) {
	if (r<tree[k].l||l>tree[k].r) return;
//	printf("modify %d %d %d\n",tree[k].l,tree[k].r,mo);
	if (tree[k].l==tree[k].r) {Modify(k,mo); return;}
	if (tree[lc(k)].max>=mo) modify(lc(k),l,r,mo);
	if (tree[rc(k)].max>=mo) modify(rc(k),l,r,mo);
}
inline void fuzhi(int k, int p, int v) {
	if (tree[k].l==tree[k].r) {tree[k].max=tree[k].sum=v; return;}
	if (p<=tree[lc(k)].r) fuzhi(lc(k),p,v); else fuzhi(rc(k),p,v);
	update(k);
}
int main() {
	read(n); read(m); rep(i,1,n) read(a[i]);
	build(1,1,n);
	while (m--) {
		int op,l,r,x; read(op); read(l); read(r);
		if (op==1) printf("%lld\n",query(1,l,r));
		else if (op==2) {read(x); modify(1,l,r,x);}
		else fuzhi(1,l,r);
	}
	return 0;
}