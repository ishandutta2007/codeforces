
// Problem : E. Permutation Separation
// Contest : Educational Codeforces Round 81 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1295/problem/E
// Memory Limit : 256.000000 MB
// Time Limit : 2000.000000 milisec
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

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
const int MN = 2e5+3;
int p[MN], a[MN], where[MN];
ll psa[MN], tree[MN<<2], lz[MN<<2];
void build (int ind, int l, int r) {
	if (l == r) {
		tree[ind] = psa[l];
		return;
	}
	int mid = (l+r)/2;
	build(lc,l,mid); build(rc,mid+1,r);
	tree[ind] = min(tree[lc],tree[rc]);
}
void push_down (int ind, int tl, int tr) {
	if (!lz[ind]) return;
	tree[ind] += lz[ind];
	if (tl != tr) {
		lz[lc] += lz[ind];
		lz[rc] += lz[ind];
	}
	lz[ind] = 0;
}
void update (int ind, int tl, int tr, int l, int r, ll v) {
	push_down(ind,tl,tr);
	if (tl > r || tr < l) return;
	if (tl >= l && tr <= r) {
		lz[ind] += v;
		push_down(ind,tl,tr);
		return;
	}
	int mid = (tl+tr)/2;
	update(lc,tl,mid,l,r,v); update(rc,mid+1,tr,l,r,v);
	tree[ind] = min(tree[lc],tree[rc]);
}
int main () {
	int n;
	scanf ("%d",&n);
	for (int i = 1; i <= n; i++) scanf ("%d",p+i), where[p[i]] = i;
	for (int i = 1; i <= n; i++) scanf ("%d",a+i), psa[i] = psa[i-1] + a[i];
	build(1,1,n-1);
	ll sofar = 0, best = tree[1];
	for (int i = 1; i <= n; i++) {
		sofar += a[where[i]];
		if (where[i] < n)update(1,1,n-1,where[i],n-1,-2*a[where[i]]);
		best = min(best,sofar+tree[1]);
	}
	printf ("%lld\n",best);
	return 0;
}