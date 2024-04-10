#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define lc ind<<1
#define rc ind<<1|1
const int MN = 3e5+5, MM = 1e6+3;
int a[MN], b[MN], ree[MM];
struct Node {
	int l,r,mx,lz;
} tree[MM<<2];
void build (int ind, int l, int r) {
	tree[ind].l = l, tree[ind].r = r;
	if (l == r) {
		tree[ind].mx = ree[l];
		return;
	}
	int mid = (l+r)/2;
	build(lc,l,mid); build(rc,mid+1,r);
	tree[ind].mx = max(tree[lc].mx,tree[rc].mx);
}
void push_down (int ind) {
	if (!tree[ind].lz) return;
	tree[ind].mx += tree[ind].lz;
	if (tree[ind].l != tree[ind].r) {
		tree[lc].lz += tree[ind].lz;
		tree[rc].lz += tree[ind].lz;
	}
	tree[ind].lz = 0;
}
void update (int ind, int l, int r, int v) {
	push_down(ind);
	if (tree[ind].r < l || tree[ind].l > r) return;
	if (tree[ind].l >= l && tree[ind].r <= r) {
		tree[ind].lz += v;
		push_down(ind);
		return;
	}
	update(lc,l,r,v); update(rc,l,r,v);
	tree[ind].mx = max(tree[lc].mx,tree[rc].mx);
}
int solve (int ind) {
	push_down(ind);
	if (tree[ind].l == tree[ind].r) return tree[ind].mx>0?tree[ind].l:-1;
	push_down(rc);
	if (tree[rc].mx > 0) return solve(rc);
	return solve(lc);
}
int main () {
	int n,m;
	scanf ("%d %d",&n,&m);
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]), ++ree[a[i]];
	for (int i = 1; i <= m; i++) scanf ("%d",&b[i]), --ree[b[i]];
	for (int i = MM-1; i >= 1; i--) ree[i] += ree[i+1];
	build(1,1,1000000);
	int q; scanf ("%d",&q);
	while (q--) {
		int t,i,v;
		scanf ("%d %d %d",&t,&i,&v);
		int* arr = t==1?a:b;
		t = t==1?1:-1;
		update(1,1,arr[i],-1*t);
		update(1,1,v,t);
		arr[i] = v;
		printf ("%d\n",solve(1));
	}
	return 0;
}