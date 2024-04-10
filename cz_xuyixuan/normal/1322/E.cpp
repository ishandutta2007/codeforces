#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int ans[MAXN];
struct SegmentTree {
	struct Node {
		int lc, rc;
		int sum;
	} a[MAXN * 2];
	int n, root, size;
	void update(int root) {
		a[root].sum = a[a[root].lc].sum + a[a[root].rc].sum;
	}
	void build(int &root, int l, int r) {
		root = ++size;
		if (l == r) {
			a[root].sum = 1;
			return;
		}
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid);
		build(a[root].rc, mid + 1, r);
		update(root);
	}
	void init(int x) {
		n = x;
		build(root, 1, n);
	}
	void modify(int root, int l, int r, int ql, int qr, int v) {
		if (l == ql && r == qr) {
			if (a[root].sum == 0) return;
			if (l == r) {
				a[root].sum = 0;
				ans[l] = v;
				return;
			}
			int mid = (l + r) / 2;
			modify(a[root].lc, l, mid, l, mid, v);
			modify(a[root].rc, mid + 1, r, mid + 1, r, v);
			update(root);
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= ql) modify(a[root].lc, l, mid, ql, min(mid, qr), v);
		if (mid + 1 <= qr) modify(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, v);
		update(root);
	}
	void modify(int l, int r, int v) {
		modify(root, 1, n, l, r, v);
	}
} ST;
set <int> Break;
int n, col[MAXN];
struct DataStructure {
	int cnt[MAXN];
	set <int> Max;
	void inc(int x) {
		cnt[x]++;
		if (cnt[x] == 1) Max.insert(x);
	}
	void dec(int x) {
		cnt[x]--;
		if (cnt[x] == 0) Max.erase(x);
	}
	int query() {
		auto tmp = Max.end(); tmp--;
		return (*tmp);
	}
} D;
void inc(int pos, int val) {
	if (pos == 0 || pos == n) {
		col[pos] += 2;
		if (pos == 0) {
			auto tmp = Break.lower_bound(pos);
			auto suf = tmp; suf++;
			if (col[*suf] == 2) ST.modify((*tmp) + 1, *suf, val);
			else ST.modify((*tmp) + 1, ((*tmp) + (*suf)) / 2, val);
		} else {
			auto tmp = Break.lower_bound(pos);
			auto pre = tmp; pre--;
			if (col[*pre] == 2) ST.modify((*pre) + 1, *tmp, val);
			else ST.modify(((*pre) + (*tmp)) / 2 + 1, *tmp, val);
		}
	} else if (col[pos] == 0) {
		col[pos] += 1;
		auto tmp = Break.lower_bound(pos);
		auto pre = tmp, suf = tmp; pre--, suf++;
		D.dec((*tmp) - (*pre)), D.dec((*suf) - (*tmp)), D.inc((*suf) - (*pre));
		if (col[*pre] == 2 && col[*suf] == 2) ST.modify((*pre) + 1, *suf, val);
		else if (col[*pre] == 2) ST.modify((*pre) + 1, ((*pre) + (*suf)) / 2, val);
		else if (col[*suf] == 2) ST.modify(((*pre) + (*suf)) / 2 + 1, *suf, val);
		Break.erase(tmp);
	} else {
		col[pos] += 1;
		auto tmp = Break.insert(pos).first;
		auto pre = tmp, suf = tmp; pre--, suf++;
		D.inc((*tmp) - (*pre)), D.inc((*suf) - (*tmp)), D.dec((*suf) - (*pre));
		if (col[*suf] == 2) ST.modify((*tmp) + 1, *suf, val);
		else ST.modify((*tmp) + 1, ((*tmp) + (*suf)) / 2, val);
		if (col[*pre] == 2) ST.modify((*pre) + 1, *tmp, val);
		else ST.modify(((*pre) + (*tmp)) / 2 + 1, *tmp, val);
	}
}
int main() {
	read(n);
	static int p[MAXN], a[MAXN];
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		p[i] = i;
	}
	sort(p + 1, p + n + 1, [&] (int x, int y) {return a[x] > a[y]; });
	for (int i = 0; i <= n; i++)
		Break.insert(i);
	for (int i = 1; i <= n; i++) 
		D.inc(1);
	int Max = 1; ST.init(n);
	for (int i = 1; i <= n; i++) {
		inc(p[i], a[p[i]]), inc(p[i] - 1, a[p[i]]);
		if (a[p[i]] != a[p[i + 1]]) chkmax(Max, D.query());
	}
	printf("%d\n", (Max - 1) / 2);
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}