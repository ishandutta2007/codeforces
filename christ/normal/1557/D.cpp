#include <bits/stdc++.h>
using namespace std;
const int MN = 6e5 + 5, MOD = 1e9 + 7;
#define lc ind<<1
#define rc ind<<1|1
vector<array<int,2>> segs[MN];
array<int,2> dp[MN];
vector<int> xs;
int getx (int x) {return lower_bound(xs.begin(),xs.end(),x) - xs.begin() + 1;}
struct Node {
	array<int,2> mx,lz;
} tree[MN << 2];
void push_down (int ind, int l, int r) {
	if (tree[ind].lz == array<int,2>{0,0}) return;
	tree[ind].mx = tree[ind].lz;
	if (l != r) {
		tree[lc].lz = tree[ind].lz;
		tree[rc].lz = tree[ind].lz;
	}
	tree[ind].lz = {0,0};
}
void update (int ind, int tl, int tr, int l, int r, array<int,2> v) {
	push_down(ind,tl,tr);
	if (tl > r || tr < l) return;
	if (l <= tl && tr <= r) {
		tree[ind].lz = v;
		push_down(ind,tl,tr);
		return;
	}
	int mid = (tl + tr) / 2;
	update(lc,tl,mid,l,r,v); update(rc,mid+1,tr,l,r,v);
	tree[ind].mx = max(tree[lc].mx,tree[rc].mx);
}
array<int,2> query (int ind, int tl, int tr, int l, int r) {
	push_down(ind,tl,tr);
	if (tl > r || tr < l) return {0,0};
	if (l <= tl && tr <= r) return tree[ind].mx;
	int mid = (tl + tr) / 2;
	return max(query(lc,tl,mid,l,r),query(rc,mid+1,tr,l,r));
}
int main() {
	int n,m; scanf ("%d %d",&n,&m);
	while (m--) {
		int i,l,r; scanf ("%d %d %d",&i,&l,&r);
		segs[i].push_back({l,r}); xs.push_back(l); xs.push_back(r);
	}
	sort(xs.begin(),xs.end());
	xs.erase(unique(xs.begin(),xs.end()),xs.end());
	for (int i = 1; i <= n; i++) {
		for (auto &[l,r] : segs[i]) dp[i] = max(dp[i],query(1,1,(int)xs.size(),getx(l),getx(r)));
		dp[i][0]++;
		array<int,2> togo = dp[i];
		togo[1] = i;
		for (auto &[l,r] : segs[i]) update(1,1,(int)xs.size(),getx(l),getx(r),togo);
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) if (dp[i][0] > ret) {
		ret = dp[i][0];
	}
	printf ("%d\n",n - ret);
	for (int i = 1; i <= n; i++) if (dp[i][0] == ret) {
		int cur = i;
		vector<bool> take(n+1);
		while (cur != 0) {
			take[cur] = true;
			cur = dp[cur][1];
		}
		for (int i = 1; i <= n; i++) if (!take[i]) printf ("%d ",i);
		printf ("\n");
		return 0;
	}
    return 0;
}