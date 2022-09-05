#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define lc(x) ((x)<<1)
#define rc(x) ((x)<<1|1)
#define pb push_back
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
const int N = 2e5+3;
int n,q,a[N],cf[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
//1. v,yh 
//2. [l,r]{s[i]=a[i-1]^a[i] (l<=i<=r)}
//3. 

struct Tree {
	int v,l,r,yh; //
	int a[31],len;
	inline void insert(int x) {
		per(i,30,0) if ((x>>i)&1) {
			if (a[i]) x^=a[i]; else {a[i]=x; len++; break;}
		}
	}
} tree[N<<2];
inline Tree merge(Tree a, Tree b) {
	Tree c=b;
	rep(i,0,30) if (a.a[i]) c.insert(a.a[i]);
	return c;
}
inline void update(int k) {
	int v=tree[k].v,l=tree[k].l,r=tree[k].r,yh=tree[k].yh;
	tree[k]=merge(tree[lc(k)],tree[rc(k)]);
	tree[k].v=v;tree[k].l=l;tree[k].r=r;tree[k].yh=yh;
}
inline void build(int k, int l, int r) {
	tree[k].l=l; tree[k].r=r; //tree[k].yh=0;
	if (l==r) {tree[k].v=a[l]; tree[k].insert(cf[l]); return;}
	int mid=(l+r)>>1;
	build(lc(k),l,mid); build(rc(k),mid+1,r);
	update(k);
}
inline void modify(int k, int l, int r, int val) {
	if (r<tree[k].l||l>tree[k].r) return;
	if (l<=tree[k].l&&r>=tree[k].r) {
		tree[k].yh^=val;
		return;
	}
	modify(lc(k),l,r,val); modify(rc(k),l,r,val);
}
inline void modify1(int k, int l) {
	if (tree[k].l==tree[k].r) {
		tree[k].len=0; memset(tree[k].a,0,sizeof(tree[k].a)); 
		tree[k].insert(cf[l]); return;
	} //update
	if (l<=tree[lc(k)].r) modify1(lc(k),l); else modify1(rc(k),l);
	update(k);
}
inline Tree query(int k, int l, int r) {
	if (l<=tree[k].l&&r>=tree[k].r) return tree[k];
	if (r<=tree[lc(k)].r) return query(lc(k),l,r);
	if (l>=tree[rc(k)].l) return query(rc(k),l,r);
	return merge(query(lc(k),l,tree[lc(k)].r),query(rc(k),tree[rc(k)].l,r));
}
inline int queryval(int k, int l, int &yh) {
	yh^=tree[k].yh;
	if (tree[k].l==tree[k].r) return tree[k].v^yh;
	if (l<=tree[lc(k)].r) return queryval(lc(k),l,yh);
	else return queryval(rc(k),l,yh);
}
int main() {
	read(n); read(q);
	rep(i,1,n) read(a[i]); rep(i,1,n) cf[i]=a[i]^a[i-1];
	build(1,1,n);
	while (q--) {
		int op,l,r,k; int Zero=0;
		read(op); read(l); read(r);
		if (op==1) {
			read(k); modify(1,l,r,k);
			cf[l]^=k; cf[r+1]^=k;
			modify1(1,l); if (r+1<=n) modify1(1,r+1);
		}
		else {
			Tree u;
			if (l+1<=r) u=query(1,l+1,r);
			else {u.len=0; memset(u.a,0,sizeof(u.a));}
			u.insert(queryval(1,l,Zero));
			printf("%d\n",1<<u.len);
		}
	}
	return 0;
}