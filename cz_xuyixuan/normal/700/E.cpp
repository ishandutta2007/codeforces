#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXP = 5e6 + 5;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
namespace SuffixArray {
	const int MAXN = 2e5 + 5;
	const int MAXLOG = 20;
	const int MAXC = 256;
	int sa[MAXN], rnk[MAXN], height[MAXN];
	int Min[MAXN][MAXLOG], bit[MAXN], N;
	void init(char *a, int n) {
		N = n;
		static int x[MAXN], y[MAXN], cnt[MAXN], rk[MAXN];
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++)
			cnt[(int) a[i]]++;
		for (int i = 1; i <= MAXC; i++)
			cnt[i] += cnt[i - 1];
		for (int i = n; i >= 1; i--)
			sa[cnt[(int) a[i]]--] = i;
		rnk[sa[1]] = 1;
		for (int i = 2; i <= n; i++)
			rnk[sa[i]] = rnk[sa[i - 1]] + (a[sa[i]] != a[sa[i - 1]]);
		for (int k = 1; rnk[sa[n]] != n; k <<= 1) {
			for (int i = 1; i <= n; i++) {
				x[i] = rnk[i];
				y[i] = (i + k <= n) ? rnk[i + k] : 0;
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
			rnk[sa[1]] = 1;
			for (int i = 2; i <= n; i++)
				rnk[sa[i]] = rnk[sa[i - 1]] + (x[sa[i]] != x[sa[i - 1]] || y[sa[i]] != y[sa[i - 1]]);		
		}
		int now = 0;
		for (int i = 1; i <= n; i++) {
			if (now) now--;
			while (a[i + now] == a[sa[rnk[i] + 1] + now]) now++;
			height[rnk[i]] = now;
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
	}
	int lcp(int x, int y) {
		if (x == y) return N - x + 1;
		x = rnk[x], y = rnk[y];
		if (x > y) swap(x, y);
		int tmp = bit[y - x];
		return min(Min[x][tmp], Min[y - (1 << tmp)][tmp]);
	}
}
struct SegmentTree {
	struct Node {
		int lc, rc;
		int sum;
	} a[MAXP];
	int n, size, root[MAXN];
	void build(int &root, int l, int r) {
		if (root == 0) root = ++size;
		if (l == r) return;
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid);
		build(a[root].rc, mid + 1, r);
	}
	void init(int x) {
		n = x; size = 0;
		build(root[0], 1, n);
	}
	int modify(int root, int l, int r, int pos, int delta) {
		int ans = ++size;
		a[ans] = a[root];
		a[ans].sum += delta;
		if (l == r) return ans;
		int mid = (l + r) / 2;
		if (mid >= pos) a[ans].lc = modify(a[root].lc, l, mid, pos, delta);
		else a[ans].rc = modify(a[root].rc, mid + 1, r, pos, delta);
		return ans;
	}
	void extend(int ver, int pos, int delta) {
		root[ver] = modify(root[ver - 1], 1, n, pos, delta);
	}
	int findnxt(int rootl, int rootr, int l, int r, int pos) {
		if (a[rootr].sum - a[rootl].sum == 0 || r <= pos) return -1;
		if (l == r) return l;
		int mid = (l + r) / 2, ans = -1;
		ans = findnxt(a[rootl].lc, a[rootr].lc, l, mid, pos);
		if (ans != -1) return ans;
		ans = findnxt(a[rootl].rc, a[rootr].rc, mid + 1, r, pos);
		return ans;
	}
	int findnxt(int l, int r, int pos) {
		return findnxt(root[l - 1], root[r], 1, n, pos);
	}
} ST;
int n; char s[MAXN];
int getans(int l) {
	int len = 1, ans = 1;
	using namespace SuffixArray;
	while (true) {
		int ql = 1, qr = rnk[l];
		while (ql < qr) {
			int mid = (ql + qr) / 2;
			if (lcp(sa[mid], l) >= len) qr = mid;
			else ql = mid + 1;
		}
		int tl = ql;
		ql = rnk[l], qr = n;
		while (ql < qr) {
			int mid = (ql + qr + 1) / 2;
			if (lcp(sa[mid], l) >= len) ql = mid;
			else qr = mid - 1;
		}
		int tr = ql;
		int nxt = ST.findnxt(tl, tr, l);
		if (nxt == -1) return ans;
		int lcpnxt = lcp(l, nxt), delta = nxt - l;
		int cnt = (lcpnxt + delta - len) / delta;
		ans += cnt, len += cnt * delta;
	}
	return -1;
}
int main() {
	read(n), scanf("\n%s", s + 1);
	SuffixArray :: init(s, n), ST.init(n);
	using namespace SuffixArray;
	for (int i = 1; i <= n; i++)
		ST.extend(i, sa[i], 1);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		chkmax(ans, getans(i));
	printf("%d\n", ans);
	return 0;
}