#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
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
		int lc, rc, Max;
	} a[MAXN * 2];
	int n, size, root;
	void update(int root) {
		a[root].Max = max(a[a[root].lc].Max, a[a[root].rc].Max);
	}
	void build(int &root, int l, int r) {
		root = ++size;
		if (l == r) {
			a[root].Max = 0;
			return;
		}
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid);
		build(a[root].rc, mid + 1, r);
		update(root);
	}
	void init(int x) {
		n = x;
		root = size = 0;
		build(root, 1, n);
	}
	void modify(int root, int l, int r, int pos, int d) {
		if (l == r) {
			a[root].Max = d;
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= pos) modify(a[root].lc, l, mid, pos, d);
		else modify(a[root].rc, mid + 1, r, pos, d);
		update(root);
	}
	void modify(int pos, int d) {
		modify(root, 1, n, pos, d);
	}
	int query(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].Max;
		int mid = (l + r) / 2, ans = 0;
		if (mid >= ql) chkmax(ans, query(a[root].lc, l, mid, ql, min(mid, qr)));
		if (mid + 1 <= qr) chkmax(ans, query(a[root].rc, mid + 1, r, max(mid + 1, ql), qr));
		return ans;
	}
	int query(int l, int r) {
		if (l > r) return 0;
		else return query(root, 1, n, l, r);
	}
} ST;
namespace SuffixArray {
	const int MAXN = 5e5 + 5;
	const int MAXLOG = 22;
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
		if (x == y) return N - sa[x] + 1;
		if (x > y) swap(x, y);
		int tmp = bit[y - x];
		return min(Min[x][tmp], Min[y - (1 << tmp)][tmp]);
	}
	int dp[MAXN];
	bool feasiable(int pos, int len) {
		if (len == 1) return true;
		len--;
		int l = 1, r = rnk[pos];
		while (l < r) {
			int mid = (l + r) / 2;
			if (lcp(mid, rnk[pos]) >= len) r = mid;
			else l = mid + 1;
		}
		int ql = l;
		l = rnk[pos], r = N;
		while (l < r) {
			int mid = (l + r + 1) / 2;
			if (lcp(mid, rnk[pos]) >= len) l = mid;
			else r = mid - 1;
		}
		int qr = l;
		if (ST.query(ql, qr) >= len) return true;
		pos++;
		l = 1, r = rnk[pos];
		while (l < r) {
			int mid = (l + r) / 2;
			if (lcp(mid, rnk[pos]) >= len) r = mid;
			else l = mid + 1;
		}
		ql = l;
		l = rnk[pos], r = N;
		while (l < r) {
			int mid = (l + r + 1) / 2;
			if (lcp(mid, rnk[pos]) >= len) l = mid;
			else r = mid - 1;
		}
		qr = l;
		return ST.query(ql, qr) >= len;
	}
	void work(int n) {
		int ans = 0, now = 1, pos = n + 1;
		for (int i = n; i >= 1; i--) {
			while (!feasiable(i, now)) {
				now--, pos--;
				ST.modify(rnk[pos], dp[pos]);
			}
			dp[i] = now;
			chkmax(ans, now);
			now = now + 1;
		}
		writeln(ans);
	}
}
int n; char s[MAXN];
int main() {
	read(n), ST.init(n);
	scanf("\n%s", s + 1);
	SuffixArray :: init(s, n);
	SuffixArray :: work(n);
	return 0;
}