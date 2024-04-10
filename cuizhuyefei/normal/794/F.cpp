#pragma GCC optimize("Ofast")
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#define lc(k) (k<<1)
#define rc(k) (k<<1|1)
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> vec;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 102000;
int n,q,a[N];
struct seg {
	bool mrk;
	int l,r,f[10]; //(mrk) i-->f[i]
	ll sum,val[10];
} tree[N<<2];
inline void update(int k) {
	tree[k].sum=tree[lc(k)].sum+tree[rc(k)].sum;
	rep(i,0,9) tree[k].val[i]=tree[lc(k)].val[i]+tree[rc(k)].val[i];
}
ll tmp[10];
inline void pushdown(int k) {
	if (tree[k].mrk) {
		tree[lc(k)].sum=0; tree[lc(k)].mrk=1;
		rep(i,0,9) tree[lc(k)].sum+=tree[lc(k)].val[i]*tree[k].f[i];
		memset(tmp,0,sizeof(tmp));
		rep(i,0,9) tmp[tree[k].f[i]]+=tree[lc(k)].val[i];
		memcpy(tree[lc(k)].val,tmp,sizeof(tmp));
		rep(i,0,9) tree[lc(k)].f[i]=tree[k].f[tree[lc(k)].f[i]];
		
		
		tree[rc(k)].sum=0; tree[rc(k)].mrk=1;
		rep(i,0,9) tree[rc(k)].sum+=tree[rc(k)].val[i]*tree[k].f[i];
		memset(tmp,0,sizeof(tmp));
		rep(i,0,9) tmp[tree[k].f[i]]+=tree[rc(k)].val[i];
		memcpy(tree[rc(k)].val,tmp,sizeof(tmp));
		rep(i,0,9) tree[rc(k)].f[i]=tree[k].f[tree[rc(k)].f[i]];
		
		tree[k].mrk=0; rep(i,0,9) tree[k].f[i]=i;
	}
}
inline void build(int k, int l, int r) {
	tree[k].l=l; tree[k].r=r; rep(i,0,9) tree[k].f[i]=i;
	if (l==r) {
		tree[k].sum=a[l];
		for (int v=1; v<=a[l]; v*=10) tree[k].val[(a[l]/v)%10]+=v;
		return;
	}
	int mid=(l+r)>>1;
	build(lc(k),l,mid); build(rc(k),mid+1,r);
	update(k);
}
inline void modify(int k, int l, int r, int x, int y) {
	if (r<tree[k].l||l>tree[k].r) return;
	if (l<=tree[k].l&&r>=tree[k].r) {
		tree[k].sum+=tree[k].val[x]*(y-x); 
		rep(i,0,9) if (tree[k].f[i]==x) tree[k].f[i]=y; tree[k].mrk=1;
		tree[k].val[y]+=tree[k].val[x]; tree[k].val[x]=0;
		return;
	}
	pushdown(k);
	modify(lc(k),l,r,x,y); modify(rc(k),l,r,x,y);
	update(k);
}
inline ll query(int k, int l, int r) {
	if (r<tree[k].l||l>tree[k].r) return 0;
	if (l<=tree[k].l&&r>=tree[k].r) return tree[k].sum;
	pushdown(k);
	return query(lc(k),l,r)+query(rc(k),l,r);
}
int main() {
	read(n); read(q); rep(i,1,n) read(a[i]);
	build(1,1,n);
	while (q--) {
		int op,l,r; read(op); read(l); read(r);
		if (op==1) {
			int x,y; read(x); read(y);
			if (x!=y) modify(1,l,r,x,y);
		}
		else printf("%lld\n",query(1,l,r));
	}
	return 0;
}