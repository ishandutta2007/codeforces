#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MN = 5e5+5, MOD = 1e9+7, CHEESE = 1e4;
#define all(x) (x).begin(),(x).end()
#define lc ind<<1
#define rc ind<<1|1
int nxt[MN], prv[MN], occ[MN], a[MN], ans[MN];
struct Q {
	int l,r,ind;
};
struct Value {
	int nxt,prv,val,ind;
};
pii NIL = {INT_MIN,0};
struct Node {
	int l,r,mx,val;
} tree[MN << 2];
void build (int ind, int l, int r) {
	tree[ind] = {l,r,INT_MIN,0};
	if (l != r) {
		int mid = l+r>>1;
		build(lc,l,mid); build(rc,mid+1,r);
	}
}
void update (int ind, Value v) {
	if (tree[ind].l == tree[ind].r) {
		if (v.nxt > tree[ind].mx) {
			tree[ind].mx = v.nxt;
			tree[ind].val = v.val;
		}
		return;
	}
	if (v.ind <= tree[lc].r) update(lc,v);
	else update(rc,v);
	if (tree[lc].mx > tree[rc].mx) {
		tree[ind].mx = tree[lc].mx;
		tree[ind].val = tree[lc].val;
	} else {
		tree[ind].mx = tree[rc].mx;
		tree[ind].val = tree[rc].val;
	}
}
pii query (int ind, int l, int r) { //{maximum,value}
	if (tree[ind].l > r || tree[ind].r < l) return NIL;
	if (tree[ind].l >= l && tree[ind].r <= r) return {tree[ind].mx,tree[ind].val};
	return max(query(lc,l,r),query(rc,l,r));
}
int main () {
	int n;
	scanf ("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&a[i]);
		prv[i] = occ[a[i]];
		occ[a[i]] = i;
	}
	vector<Value> values;
	values.reserve(n);
	memset(occ,0x3f,sizeof occ);
	for (int i = n; i >= 1; i--) {
		nxt[i] = occ[a[i]];
		occ[a[i]] = i;
		values.push_back({nxt[i],prv[i],a[i],i});
	}
	int qq;
	scanf ("%d",&qq);
	vector<Q> queries(qq);
	for (int i = 0; i < qq; i++) {
		scanf ("%d %d",&queries[i].l,&queries[i].r);
		queries[i].ind = i;
	}
	sort(all(queries),[](Q a, Q b){return a.l < b.l;});
	sort(all(values),[](Value a, Value b){return a.prv < b.prv;});
	build(1,1,n);
	int vind = 0;
	for (auto &q : queries) {
		while (vind < n && values[vind].prv < q.l) {
			update(1,values[vind]);
			vind++;
		}
		pii ret = query(1,q.l,q.r);
		ans[q.ind] = ret.first > q.r ? ret.second : 0;
	}
	for (int i = 0; i < qq; i++) printf ("%d\n",ans[i]);
    return 0;
}