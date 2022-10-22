#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 1e5+3;
struct Node {
	int l,r,mn,lz;
} tree[MN<<2];
int arr[MN];
int ret[MN];
#define lc ind<<1
#define rc ind<<1|1
void push_down (int ind) {
	if(!tree[ind].lz) return;
	tree[ind].mn += tree[ind].lz;
	if (tree[ind].l != tree[ind].r) {
		tree[lc].lz += tree[ind].lz;
		tree[rc].lz += tree[ind].lz;
	}
	tree[ind].lz = 0;
}
void build (int ind, int l, int r) {
	tree[ind].l = l; tree[ind].r = r;
	if (l == r) {
		scanf ("%d",&tree[ind].mn);
		arr[l] = tree[ind].mn;
		return;
	}
	int mid = l+r>>1;
	build(lc,l,mid); build(rc,mid+1,r);
	tree[ind].mn = min(tree[lc].mn,tree[rc].mn);
}
void update (int ind, int l, int r, int v) {
	push_down(ind); //oops
	if (tree[ind].l > r || tree[ind].r < l) return;
	if (tree[ind].l >= l && tree[ind].r <= r) {
		tree[ind].lz += v;
		push_down(ind);
		return;
	}
	update(lc,l,r,v); update(rc,l,r,v);
	tree[ind].mn = min(tree[lc].mn,tree[rc].mn);
} 
vector<int> ed[MN], st[MN];
int main () {
	int n,m;
	scanf ("%d %d",&n,&m);
	vector<pii> ranges;
	build(1,1,n);
	for (int i = 1; i <= m; i++) {
		int l,r;
		scanf ("%d %d",&l,&r);
		ranges.emplace_back(l,r);
		update(1,l,r,-1);
		ed[r].push_back(l);
		st[l].push_back(r);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int l : ed[i-1]) update(1,l,i-1,-1);
		for (int r : st[i]) update(1,i,r,1);
		ret[i] = arr[i]-tree[1].mn;
		ans = max(ans,ret[i]); 
	}
	printf ("%d\n",ans);
	for (int ii = 1; ii <= n; ii++) if (ret[ii] == ans){
		vector<int> which;
		for (int i = 0; i < m; i++) if (ranges[i].second < ii || ranges[i].first > ii) which.push_back(i);
		printf ("%d\n",which.size());
		for (int i : which) printf ("%d ",i+1);
		printf ("\n");
		break;
	}
	return 0;
}