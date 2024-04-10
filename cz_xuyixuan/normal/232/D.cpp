#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int MAXP = 10000005;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
struct SegmentTree {
	struct Node {
		int lc, rc;
		int cnt;
	} a[MAXP];
	int n, size, root[MAXN];
	void build(int &root, int l, int r) {
		root = ++size;
		if (l == r) return;
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid);
		build(a[root].rc, mid + 1, r);
	}
	void init(int x) {
		n = x;
		size = 0;
		build(root[0], 1, n);
	}
	int copy(int root) {
		size++;
		a[size] = a[root];
		return size;
	}
	int modify(int root, int l, int r, int pos) {
		int ans = copy(root);
		a[ans].cnt++;
		if (l == r) return ans;
		int mid = (l + r) / 2;
		if (mid >= pos) a[ans].lc = modify(a[root].lc, l, mid, pos);
		else a[ans].rc = modify(a[root].rc, mid + 1, r, pos);
		return ans;
	}
	void extend(int pos, int val) {
		root[pos] = modify(root[pos - 1], 1, n, val);
	}
	int query(int rootl, int rootr, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[rootr].cnt - a[rootl].cnt;
		int mid = (l + r) / 2, ans = 0;
		if (mid >= ql) ans += query(a[rootl].lc, a[rootr].lc, l, mid, ql, min(qr, mid));
		if (mid + 1 <= qr) ans += query(a[rootl].rc, a[rootr].rc, mid + 1, r, max(mid + 1, ql), qr);
		return ans;
	}
	int query(int l, int r, int ql, int qr) {
		if (ql <= qr) return query(root[l - 1], root[r], 1, n, ql, qr);
		else return 0;
	}
} ST;
namespace SuffixArray {
	const int MAXN = 200005;
	const int MAXLOG = 20;
	int sa[MAXN], rank[MAXN], height[MAXN];
	int Min[MAXN][MAXLOG], bit[MAXN], N, tn;
	void init(int *a, int n) {
		static int tmp[MAXN], val[MAXN]; int tot = 0;
		N = 2 * n - 1, tn = n;
		for (int i = 1; i <= n - 1; i++) {
			tmp[++tot] = val[i] = a[i + 1] - a[i];
			tmp[++tot] = val[i + n] = a[i] - a[i + 1];
		}
		sort(tmp + 1, tmp + tot + 1);
		tot = unique(tmp + 1, tmp + tot + 1) - tmp - 1;
		for (int i = 1; i <= n - 1; i++) {
			val[i] = lower_bound(tmp + 1, tmp + tot + 1, val[i]) - tmp;
			val[i + n] = lower_bound(tmp + 1, tmp + tot + 1, val[i + n]) - tmp;
		}
		val[n] = 0; n = 2 * n - 1;
		static int x[MAXN], y[MAXN], cnt[MAXN], rk[MAXN];
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++)
			cnt[val[i]]++;
		for (int i = 1; i <= n; i++)
			cnt[i] += cnt[i - 1];
		for (int i = n; i >= 1; i--)
			sa[cnt[val[i]]--] = i;
		rank[sa[1]] = 1;
		for (int i = 2; i <= n; i++)
			rank[sa[i]] = rank[sa[i - 1]] + (val[sa[i]] != val[sa[i - 1]]);
		for (int k = 1; rank[sa[n]] != n; k <<= 1) {
			for (int i = 1; i <= n; i++) {
				x[i] = rank[i];
				y[i] = (i + k <= n) ? rank[i + k] : 0;
			}
			memset(cnt, 0, sizeof(cnt));
			for (int i = 1; i <= n; i++)
				cnt[y[i]]++;
			for (int i = 1; i <= n; i++)
				cnt[i] += cnt[i - 1];
			for (int i = n; i >= 1; i--)
				rk[cnt[y[i]]--] = i;
			memset(cnt, 0, sizeof(cnt));
			for (int i = 1; i <= n; i++)
				cnt[x[i]]++;
			for (int i = 1; i <= n; i++)
				cnt[i] += cnt[i - 1];
			for (int i = n; i >= 1; i--)
				sa[cnt[x[rk[i]]]--] = rk[i];
			rank[sa[1]] = 1;
			for (int i = 2; i <= n; i++)
				rank[sa[i]] = rank[sa[i - 1]] + (x[sa[i]] != x[sa[i - 1]] || y[sa[i]] != y[sa[i - 1]]);		
		}
		int now = 0;
		for (int i = 1; i <= n; i++) {
			if (now) now--;
			while (val[i + now] == val[sa[rank[i] + 1] + now]) now++;
			height[rank[i]] = now;
		}
		for (int i = 1; i <= n; i++)
			Min[i][0] = height[i];
		for (int p = 1; p < MAXLOG; p++) {
			int tmp = 1 << (p - 1);
			for (int i = 1, j = tmp + 1; j <= n; i++, j++)
				Min[i][p] = min(Min[i][p - 1], Min[i + tmp][p - 1]);
		}
		for (int i = 1; i <= n; i++) {
			bit[i] = bit[i - 1];
			if (i >= 1 << (bit[i] + 1)) bit[i]++;
		}
		ST.init(n);
		for (int i = 1; i <= n; i++)
			ST.extend(i, sa[i]);
	}
	int lcp(int x, int y) {
		if (x > y) swap(x, y);
		int tmp = bit[y - x];
		return min(Min[x][tmp], Min[y - (1 << tmp)][tmp]);
	}
	int query(int ql, int qr) {
		int len = qr - ql;
		int l = rank[ql + tn], r = rank[ql + tn];
		for (int i = MAXLOG; i >= 0; i--) {
			int tmp = 1 << i;
			if (l - tmp >= 1 && lcp(l, l - tmp) >= len) l -= tmp;
			if (r + tmp <= N && lcp(r, r + tmp) >= len) r += tmp;
		}
		return ST.query(l, r, 1, ql - len - 1) + ST.query(l, r, ql + len + 1, tn);
	}
}
int a[MAXN];
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	SuffixArray::init(a, n);
	int q; read(q);
	for (int i = 1; i <= q; i++) {
		int x, y;
		read(x), read(y);
		if (x == y) writeln(n - 1);
		else writeln(SuffixArray::query(x, y));
	}
	return 0;
}