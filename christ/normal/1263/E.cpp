#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 1e6+2, MOD = 1e9+7, LOG = 15, INF = 1e9, ED = 1e6+1;
#define all(x) (x).begin(),(x).end()
#define lc ind<<1
#define rc ind<<1|1
char s[MN], at[MN];
struct Node {
	int mx, mn, lz;
} tree[MN << 2];
void push_down (int ind, int l, int r) {
	if (!tree[ind].lz) return;
	tree[ind].mx += tree[ind].lz;
	tree[ind].mn += tree[ind].lz;
	if (l != r) {
		tree[lc].lz += tree[ind].lz;
		tree[rc].lz += tree[ind].lz;
	}
	tree[ind].lz = 0;
}
void update (int ind, int tl, int tr, int l, int r, int v) {
	push_down(ind,tl,tr);
	if (tl > r || tr < l) return;
	if (tl >= l && tr <= r) {
		tree[ind].lz += v;
		push_down(ind,tl,tr);
		return;
	}
	int mid = (tl+tr)/2;
	update(lc,tl,mid,l,r,v); update(rc,mid+1,tr,l,r,v);
	tree[ind].mn = min(tree[lc].mn,tree[rc].mn);
	tree[ind].mx = max(tree[lc].mx,tree[rc].mx);
}
pii query (int ind, int tl, int tr, int l, int r) {
	push_down(ind,tl,tr);
	if (tl > r || tr < l) return {INF,-INF};
	if (tl >= l && tr <= r) return {tree[ind].mn,tree[ind].mx};
	int mid = (tl+tr)/2;
	pii q1 = query(lc,tl,mid,l,r), q2 = query(rc,mid+1,tr,l,r);
	return {min(q1.first,q2.first),max(q1.second,q2.second)};
}
int get (char c) {
	if (c == '(') return 1;
	return c == ')' ? -1 : 0;
}
int main() {
	int n;
	scanf ("%d",&n);
	scanf ("%s",s); int curpos = 1;
	for (int i = 0; i < (MN << 2); i++) tree[i] = {0,0};
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') ++curpos;
		else if (s[i] == 'L') curpos = max(curpos-1,1);
		else {
			int go = get(s[i]) - get(at[curpos]);
			at[curpos] = s[i];
			update(1,1,ED,curpos,ED,go);
		}
		if (query(1,1,ED,ED,ED).first != 0 || tree[1].mn < 0) printf ("-1 ");
		else printf ("%d ",tree[1].mx);
	}
	printf ("\n");
    return 0;
}