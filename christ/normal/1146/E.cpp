#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using ld = long double;
using ui = unsigned int;
using ull = unsigned long long;
using ui128 = __uint128_t;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define lc ind<<1
#define rc ind<<1|1
const int MN = 2e5 + 2, LOG = 17, INF = 1e8;
pii a[MN]; int ans[MN];
struct Node {
	int lz,c0,c1; bool flip;
} tree[MN << 2];
void build (int ind, int l, int r) {
	if (l == r) {tree[ind] = {-1,a[l].second < 0,a[l].second > 0}; return;}
	int mid = (l + r) / 2;
	build(lc,l,mid); build(rc,mid+1,r);
	tree[ind] = {-1,tree[lc].c0 + tree[rc].c0,tree[lc].c1 + tree[rc].c1};
}
void push_down (int ind, int l, int r) {
	if (~tree[ind].lz) {
		(tree[ind].lz ? tree[ind].c1 : tree[ind].c0) = r - l + 1;
		(tree[ind].lz ? tree[ind].c0 : tree[ind].c1) = 0;
		if (l != r) {
			tree[rc].lz = tree[ind].lz; tree[lc].flip = 0;
			tree[lc].lz = tree[ind].lz; tree[rc].flip = 0;
		}
		tree[ind].lz = -1;
	}
	if (tree[ind].flip) {
		swap(tree[ind].c0,tree[ind].c1);
		if (l != r) {
			tree[rc].flip ^= 1; tree[lc].flip ^= 1;
		} 
		tree[ind].flip = 0;
	}
}
void update (int ind, int tl, int tr, int l, int r, int v) {
	push_down(ind,tl,tr);
	if (tl > r || tr < l) return;
	if (l <= tl && tr <= r) {
		tree[ind].lz = v; tree[ind].flip = 0;
		push_down(ind,tl,tr);
		return;
	}
	int mid = (tl + tr) / 2;
	update(lc,tl,mid,l,r,v); update(rc,mid+1,tr,l,r,v);
	tree[ind].c0 = tree[lc].c0 + tree[rc].c0;
	tree[ind].c1 = tree[lc].c1 + tree[rc].c1;
}
void updateF (int ind, int tl, int tr, int l, int r) {
	push_down(ind,tl,tr);
	if (tl > r || tr < l) return;
	if (l <= tl && tr <= r) {
		tree[ind].flip ^= 1;
		push_down(ind,tl,tr);
		return;
	}
	int mid = (tl + tr) / 2;
	updateF(lc,tl,mid,l,r); updateF(rc,mid+1,tr,l,r);
	tree[ind].c0 = tree[lc].c0 + tree[rc].c0;
	tree[ind].c1 = tree[lc].c1 + tree[rc].c1;
}
void fill (int ind, int l, int r) {
	push_down(ind,l,r);
	if (l == r) {
		if (tree[ind].c1) ans[abs(a[l].second)] = a[l].first;
		return;
	}
	int mid = (l + r) / 2;
	fill(lc,l,mid); fill(rc,mid+1,r);
}
int main () { 
	int n,q;
	scanf ("%d %d",&n,&q);
	for (int i = 1; i <= n*2; i+=2) scanf ("%d",&a[i].first), a[i].second = i, a[i+1].second = -i, a[i+1].first = -a[i].first;
	sort(a+1,a+1+n*2);
	build(1,1,n*2);
	while (q--) {
		char c; int x;
		scanf (" %c %d",&c,&x);
		if (c == '<') {
			int ind = lower_bound(a+1,a+1+n*2,pii{x,-INF}) - a - 1, ind2 = upper_bound(a+1,a+1+n*2,pii{-x,INF}) - a;
			if (ind2 <= ind) updateF(1,1,n*2,ind2,ind);
			if (min(ind,ind2-1) > 0) update(1,1,n*2,1,min(ind,ind2-1),0);
			if (max(ind2,ind+1) <= 2 * n) update(1,1,n*2,max(ind2,ind+1),n*2,1);
		} else {
			int ind = upper_bound(a+1,a+1+n*2,pii{x,INF}) - a, ind2 = lower_bound(a+1,a+1+n*2,pii{-x,-INF}) - a - 1;
			if (ind <= ind2) updateF(1,1,n*2,ind,ind2);
			if (max(ind,ind2+1) <= 2 * n) update(1,1,n*2,max(ind,ind2+1),n*2,0);
			if (min(ind2,ind-1) > 0) update(1,1,n*2,1,min(ind2,ind-1),1);
		}
	}
	fill(1,1,2*n);
	for (int i = 1; i <= 2*n; i+=2) printf ("%d ",ans[i]);
	printf ("\n");
    return 0;
}

//0 1 -2 -1 2
// < 2
//-2 -2 -1 -1 0 0 1 1 2 2
//0  1   0  1 0 1 0 1 0 1

//0 0 1 0 1 0 1 0 1 1