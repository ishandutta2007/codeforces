#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#pragma GCC diagnostic ignored "-Wunused-result" 
#pragma GCC diagnostic ignored "-Wsign-compare" 
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
#define setio(x)
#else
#define setio(x) freopen((x+".in").c_str(),"r",stdin); freopen((x+".out").c_str(),"w",stdout)
#endif
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e6+3, BASE = 31, LOG = 20, MOD = 1e9+7;
struct Node {
	int l,r,ff,ss,fs,sf; bool flip;
} tree[MN << 2];
char s[MN];
void upd (int ind) {
	tree[ind].ff = tree[lc].ff + tree[rc].ff;
	tree[ind].ss = tree[lc].ss + tree[rc].ss;
	tree[ind].fs = max({tree[lc].fs+tree[rc].ss,tree[lc].ff+tree[rc].fs,tree[lc].ff+tree[rc].ss});
	tree[ind].sf = max({tree[lc].sf+tree[rc].ff,tree[lc].ss+tree[rc].sf,tree[lc].ss+tree[rc].ff});
}
void push_down (int ind) {
	if (!tree[ind].flip) return;
	int ofs = tree[ind].fs, off = tree[ind].ff;
	tree[ind].fs = tree[ind].sf;
	tree[ind].ff = tree[ind].ss;
	tree[ind].ss = off;
	tree[ind].sf = ofs;
	if (tree[ind].l != tree[ind].r) {
		tree[lc].flip ^= 1;
		tree[rc].flip ^= 1;
	}
	tree[ind].flip = 0;
}
void build (int ind, int l, int r) {
	tree[ind].l = l; tree[ind].r = r; 
	if (l == r) {
		(s[l]=='4'?tree[ind].ff:tree[ind].ss) = 1;
		return;
	}
	int mid = (l+r)/2;
	build(lc,l,mid); build(rc,mid+1,r);
	upd(ind);
}
void update (int ind, int l, int r) {
	push_down(ind);
	if (tree[ind].r < l || tree[ind].l > r) return;
	if (tree[ind].l >= l && tree[ind].r <= r) {
		tree[ind].flip ^= 1;
		push_down(ind);
		return;
	}
	update(lc,l,r); update(rc,l,r);
	upd(ind);
}
int main() {
	int n,m;
	scanf ("%d %d",&n,&m);
	scanf ("%s",s+1);
	build(1,1,n);
	while (m--) {
		scanf ("%s",s);
		if (s[0] == 'c') {
			printf ("%d\n",max({tree[1].ff,tree[1].ss,tree[1].fs}));
		} else {
			int l,r;
			scanf ("%d %d",&l,&r);
			update(1,l,r);
		}
	}
	return 0;
}