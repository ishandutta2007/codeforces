#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
const int MAXP = 6000005;
const int MAXLOG = 20;
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
		if (val == 0) root[pos] = root[pos - 1];
		else root[pos] = modify(root[pos - 1], 1, n, val);
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
struct SuffixArray {
	int n, oldn, sa[MAXN], rk[MAXN], height[MAXN], Log[MAXN], Min[MAXN][MAXLOG];
	void init(char *s, int old) {
		n = strlen(s + 1); oldn = old;
		static int x[MAXN], y[MAXN], cnt[MAXN], tmp[MAXN];
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++)
			cnt[s[i]]++;
		for (int i = 1; i <= 256; i++)
			cnt[i] += cnt[i - 1];
		for (int i = n; i >= 1; i--)
			sa[cnt[s[i]]--] = i;
		rk[sa[1]] = 1;
		for (int i = 2; i <= n; i++)
			rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);
		for (int k = 1; rk[sa[n]] != n; k <<= 1) {
			for (int i = 1; i <= n; i++) {
				x[i] = rk[i];
				if (i + k <= n) y[i] = rk[i + k];
				else y[i] = 0;
			}
			memset(cnt, 0, sizeof(cnt));
			for (int i = 1; i <= n; i++)
				cnt[y[i]]++;
			for (int i = 1; i <= n; i++)
				cnt[i] += cnt[i - 1];
			for (int i = n; i >= 1; i--)
				tmp[cnt[y[i]]--] = i;
			memset(cnt, 0, sizeof(cnt));
			for (int i = 1; i <= n; i++)
				cnt[x[i]]++;
			for (int i = 1; i <= n; i++)
				cnt[i] += cnt[i - 1];
			for (int i = n; i >= 1; i--)
				sa[cnt[x[tmp[i]]]--] = tmp[i];
			rk[sa[1]] = 1;
			for (int i = 2; i <= n; i++)
				rk[sa[i]] = rk[sa[i - 1]] + (x[sa[i]] != x[sa[i - 1]] || y[sa[i]] != y[sa[i - 1]]);
		}
		ST.init(oldn);
		for (int i = 1; i <= n; i++)
			if (sa[i] <= oldn) ST.extend(i, sa[i]);
			else ST.extend(i, 0);
		for (int i = 1; i <= n; i++) {
			height[rk[i]] = height[rk[i - 1]];
			if (height[rk[i]]) height[rk[i]]--;
			int tmp = sa[rk[i] + 1];
			while (s[i + height[rk[i]]] == s[tmp + height[rk[i]]]) height[rk[i]]++;
		}
		for (int i = 1; i <= n; i++) {
			Min[i][0] = height[i];
			Log[i] = Log[i - 1];
			if (i == (1 << (Log[i] + 1))) Log[i]++;
		}
		for (int p = 1; p < MAXLOG; p++)
		for (int i = 1, j = 1 + (1 << (p - 1)); j <= n; i++, j++)
			Min[i][p] = min(Min[i][p - 1], Min[j][p - 1]);
	}
	int query(int x, int y) {
		if (x == y) return n - x + 1;
		x = rk[x], y = rk[y];
		if (x > y) swap(x, y);
		int len = Log[y - x];
		return min(Min[x][len], Min[y - (1 << len)][len]);
	}
	int rmq(int x, int y) {
		if (x == y) return n;
		if (x > y) swap(x, y);
		int len = Log[y - x];
		return min(Min[x][len], Min[y - (1 << len)][len]);
	}
	void getans(char *t, char *s, int st, int len, int ql, int qr) {
		int tst = st; st = rk[st];
		for (int i = len; i >= 0; i--) {
			if (i + 1 > qr - ql + 1) continue;
			int l = 1, r = st;
			while (l < r) {
				int mid = (l + r) / 2;
				if (rmq(mid, st) >= i) r = mid;
				else l = mid + 1;
			}
			int pl = l;
			l = st, r = n;
			while (l < r) {
				int mid = (l + r + 1) / 2;
				if (rmq(mid, st) >= i) l = mid;
				else r = mid - 1;
			}
			int pr = l;
			if (i != len) {
				l = pl, r = pr + 1;
				while (l < r) {
					int mid = (l + r) / 2;
					if (s[sa[mid] + i] <= s[tst + i]) l = mid + 1;
					else r = mid;
				}
				pl = l;
			}
			if (ST.query(pl, pr, ql, qr - i) == 0) continue;
			l = pl, r = pr;
			while (l < r) {
				int mid = (l + r) / 2;
				if (ST.query(pl, mid, ql, qr - i) == 0) l = mid + 1;
				else r = mid;
			}
			for (int j = 0; j <= i; j++)
				putchar(s[sa[l] + j]);
			putchar('\n');
			return;
		}
		printf("-1\n");
	}
} SA;
char s[MAXN], t[MAXN];
int tot, n, ql[MAXN], qr[MAXN], len[MAXN], home[MAXN];
int main() {
	scanf("%s", s + 1);
	tot = n = strlen(s + 1);
	int q; read(q);
	for (int i = 1; i <= q; i++) {
		read(ql[i]), read(qr[i]);
		home[i] = tot + 1;
		scanf(" %s", t + 1);
		len[i] = strlen(t + 1);
		for (int j = 1; j <= len[i]; j++)
			s[j + tot] = t[j];
		tot += len[i];
	}
	SA.init(s, n);
	for (int i = 1; i <= q; i++)
		SA.getans(s + home[i] - 1, s, home[i], len[i], ql[i], qr[i]);
	return 0;
}