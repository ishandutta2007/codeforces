#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define _rep(i,a,b) for (int i=(a); i>=(b); i--)
#define lc (o << 1)
#define rc (o << 1 | 1)
#define mid ((l + r) >> 1)
using namespace std;

inline int read() {
	char ch = getchar(); int x = 0, op = 1;
	while (ch < '0' || '9' < ch) { if (ch == '-') op = -1; ch = getchar(); }
	while ('0' <= ch && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return op * x;
}

const int maxn = 200009;
const int MOD = 1000000007;
struct segment {
	int u, l, r, s;
	bool operator < (const segment &a) const {
		return u < a.u;
	}
} a[maxn];
vector<int> del[maxn]; set<int> T[maxn<<2];
int h, w, n, L[maxn], R[maxn], cnt[maxn];

int search(int x) {
	int l = 1, r = n, Mid;
	while (l < r) {
		Mid = (l + r + 1) >> 1;
		if (a[Mid].u <= x) l = Mid;
		else r = Mid - 1;
	}
	return l;
}

void add(int &a, int b) {
	a = (a + b) % MOD;
}

void update(int o, int l, int r, int x, int y, int z) {
	if (l == x && y == r) {
		if (z > 0) T[o].insert(z);
		else T[o].erase(-z);
		return;
	}
	if (x <= mid) update(lc, l, mid, x, min(y, mid), z);
	if (mid+1 <= y) update(rc, mid+1, r, max(x, mid+1), y, z);
}

int query(int o, int l, int r, int x) {
	if (l == r) return T[o].empty() ? 0 : *(--T[o].end());
	int res = T[o].empty() ? 0 : *(--T[o].end());
	if (x <= mid) return max(res, query(lc, l, mid, x));
	return max(res, query(rc, mid+1, r, x));
}

int main() {
	h = read(); w = read(); n = read();
	rep (i, 1, n) {
		a[i].u = read(); a[i].l = read(); a[i].r = read(); a[i].s = read();
	}
	a[++n].u = 0; a[n].l = 1, a[n].r = w; a[n].s = h+1; 
	sort(a+1, a+n+1);
	rep (i, 1, n) {
		if (a[i].l != 1) L[i] = query(1, 1, w, a[i].l - 1);
		if (a[i].r != w) R[i] = query(1, 1, w, a[i].r + 1);
		update(1, 1, w, a[i].l, a[i].r, i); 
		if (a[i].u + a[i].s <= h) del[search(a[i].u + a[i].s)].push_back(i);
		while (!del[i].empty()) { 
			update(1, 1, w, a[del[i].back()].l, a[del[i].back()].r, -del[i].back());
			del[i].pop_back();
		}
	} 
	rep (i, 1, w) cnt[query(1, 1, w, i)]++;
	_rep (i, n, 2) { //printf("%d %d %d %d\n", i, L[i], R[i], cnt[i]);
		if (!L[i]) add(cnt[R[i]], 2 * cnt[i] % MOD);
		else if (!R[i]) add(cnt[L[i]], 2 * cnt[i] % MOD);
		else {
			add(cnt[R[i]], cnt[i]); add(cnt[L[i]], cnt[i]);
		}
	}
	printf("%d\n", cnt[1]);
	return 0;
}